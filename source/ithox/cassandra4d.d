module ithox.cassandra4d;
/// cassandra 操作类

import ithox.cassandra;
import std.format;
import std.traits;



class CassandraResultSet
{
	private
	{
		CassandraKeyspace keyspace;
		string sql;
		bool runSuccess;
		CassResult* result;
		size_t _columnCount, _rowCount;
		int _usedCount;
		string[] _columns;
		CassValueType[] _columnsType;
		CassIterator* iterator;
		Row stringRow;
	}

	this(CassandraKeyspace ks, string sql)
	{
		this.keyspace = ks;
		this.sql = sql;
		_rowCount = 0;
		_usedCount = 0;
		this.execute();
	}

	~this()
	{
		sql.destroy;
		runSuccess.destroy;
		stringRow.destroy;

		if(result !is null)
		{
			cass_result_free(result);
		}
		if(iterator !is null)
		{
			cass_iterator_free(iterator  );
		}
	}
	///执行
	private void execute()
	{
		import std.string;
		CassStatement* statement = cass_statement_new(this.sql.toStringz, 0);
		auto future = cass_session_execute(this.keyspace.client.getSession(), statement);
		
		cass_future_wait(future);
		auto rc = cass_future_error_code(future);

		if (rc != CassError.CASS_OK) 
		{
			this.runSuccess = false;
			std.stdio.writeln(this.sql);
			printError(future, __LINE__);
		}
		else
		{
			this.runSuccess = true;
			this.result = cast(CassResult*)cass_future_get_result(future);

			_columnCount =  cass_result_column_count(result);
			_rowCount =  cass_result_row_count(result);

			for(auto i =0; i < _columnCount; i++)
			{
				_columnsType ~= cass_result_column_type(result, i);
			}
			const char*  name;
			size_t name_length;
			for(size_t i =0; i < _columnCount; i++)
			{
				cass_result_column_name(result, i,&name, &name_length);
				_columns ~= cast(string)name[0 .. name_length];
			}
			this.iterator = cass_iterator_from_result(result);

			this.fetchNext();
		}

		cass_future_free(future);
		cass_statement_free(statement);
	}

	///是否执行成功
	public @property bool isSuccess()
	{
		return this.runSuccess;
	}

	/// 结果条数
	public @property size_t count()
	{
		if(!this.isSuccess)
		{
			return 0;
		}
		return this._rowCount;
	}
	///结果条数
	public @property size_t length()
	{
		return count;
	}
	///列名
	public @property string[] columnNames()
	{
		return this._columns;
	}

	///列个数
	public @property size_t columnCount()
	{
		return this._columnCount;
	}


	///列类型
	public @property CassValueType[] columnsType()
	{
		return this._columnsType;
	}

	public @property bool empty() {
		return _usedCount == _rowCount;
	}

	public Row front() 
	{
		return stringRow;
	}

	public void popFront() 
	{
		this._usedCount++;
		if(this._usedCount < this._rowCount) {
			fetchNext();
		}
	}

	///获取role
	private void fetchNext()
	{
		if(this.empty)
		{
			return;
		}
		//this._usedCount++;
		import std.conv;
		cass_iterator_next(this.iterator);
		const CassRow* row = cass_iterator_get_row(this.iterator);
		string[] tmpRow;
		foreach(int index, string cname; this._columns)
		{
			import std.string;
			const CassValue* value = cass_row_get_column_by_name(row, cname.toStringz);
			switch(this._columnsType[index])
			{
				case CassValueType.CASS_VALUE_TYPE_INT:
				case CassValueType.CASS_VALUE_TYPE_TINY_INT:
				case CassValueType.CASS_VALUE_TYPE_SMALL_INT:
					cass_int32_t op;
					cass_value_get_int32(value, &op);
					tmpRow ~= to!string(op);
					break;
				case CassValueType.CASS_VALUE_TYPE_BIGINT:
					cass_int64_t op;
					cass_value_get_int64(value, &op);
					tmpRow ~= to!string(op);
					break;
				case CassValueType.CASS_VALUE_TYPE_VARCHAR:
					const char* var;
					size_t len;
					cass_value_get_string(value, &var, &len);
					tmpRow ~= cast(string)(var[0 .. len]);

					break;

				default:
					throw new Exception(format("CassValueType is not deal:%s", this._columnsType[index]), __FILE__, __LINE__);
			}
		}
		this.stringRow.row = tmpRow;
		this.stringRow.columnNames = this._columns;
	}

}


struct Row {
	import std.conv;
	string[] row;
	string[] columnNames;

	private{
		int[string] mapping;
	}

	string opIndex(size_t idx, string file = __FILE__, int line = __LINE__) {
		if(idx >= row.length)
			throw new Exception(text("index ", idx, " is out of bounds on result"), file, line);
		return row[idx];
	}

	string opIndex(string name, string file = __FILE__, int line = __LINE__) {
		auto idx = this.getFieldIndex(name);
		if(idx >= row.length)
			throw new Exception(text("no field ", name, " in result"), file, line);
		return row[idx];
	}

	string toString() {
		return to!string(row);
	}

	string[string] toAA() {
		string[string] a;
		foreach(i, r; row)
		{
			a[columnNames[i]] = r;
		}
		return a;
	}

	int opApply(int delegate(ref string, ref string) dg) {
		foreach(a, b; toAA())
			mixin(yield("a, b"));

		return 0;
	}



	string[] toStringArray() {
		return row;
	}

	private void makeFieldMapping() {

		if(columnNames.length == 0)
			return;

		for(int i = 0; i < columnNames.length; i++) {
			mapping[columnNames[i]] = i;
		}
	}

	private int getFieldIndex(string name)
	{
		if(mapping is null)
			this.makeFieldMapping();
		return mapping[name];
	}
}

string yield(string what) { return `if(auto result = dg(`~what~`)) return result;`; }

class CassandraKeyspace{
	private{

		CassandraClient _client;
		string _name;
	}
	this(CassandraClient client, string name)
	{
		this._client = client;
		this._name = name;
		this._client.useKeyspace(name);
	}

	@property string name()
	{
		return this._name;
	}
	@property inout(CassandraClient) client() inout 
	{ 
		return this._client; 
	}

	///执行sql
	CassandraResultSet query(string sql)
	{
		return new CassandraResultSet(this, sql);
	}



}
class CassandraTable{

	private{
		CassandraKeyspace _keyspace;
		string _name;
	}

	this(CassandraKeyspace keyspace, string name)
	{
		_keyspace = keyspace;
		_name = name;
	}

	bool exists()
	{
		auto sysks = _keyspace.client.getKeyspace("system");
		//	auto res = sysks.client.executeQuery(format(`SELECT columnfamily_name FROM schema_columnfamilies WHERE keyspace_name='%s' AND columnfamily_name='%s'`, _keyspace.name, _name));
		//return !res.empty;
		return false;
	}

	void truncate()
	{
		_keyspace.client.executeQuery("TRUNCATE "~ _name);
	}


}
class CassandraDb{

}

class CassandraClient{
	private{
		string hosts;
		int port;
		CassCluster* cluster;
		CassSession* session;
		string usedKeyspace;
	}

	this(string hosts, int port = int.init, int protocol_version = 2)
	{
		this.hosts = hosts;
		this.port = port;
		cluster = cass_cluster_new();

		cass_cluster_set_protocol_version( cluster,protocol_version);
		import std.string;
		cass_cluster_set_contact_points(cluster, hosts.toStringz);
		if(this.port != int.init)
		{
			cass_cluster_set_port(cluster, port);
		}

		this.connectSession();
	}

	///连接session
	private CassError connectSession() 
	{
		CassError rc = CassError.CASS_OK;
		session = cass_session_new();
		CassFuture* future = cass_session_connect(session, cluster);

		//	cass_future_wait(future);
		rc = cass_future_error_code(future);
		if (rc != CassError.CASS_OK) {
			printError(future, __LINE__);
		}
		cass_future_free(future);
		return rc;
	}

	///获取连接session
	public CassSession* getSession()
	{
		return this.session;
	}
	///执行sql,无返回结果
	public CassError executeQuery(string query) 
	{
		CassError rc = CassError.CASS_OK;
		CassFuture* future;
		import std.string;
		CassStatement* statement = cass_statement_new(query.toStringz, 0);

		future = cass_session_execute(session, statement);
		cass_future_wait(future);

		rc = cass_future_error_code(future);
		if (rc != CassError.CASS_OK) {
			printError(future, __LINE__);
		}

		cass_future_free(future);
		cass_statement_free(statement);

		return rc;
	}


	CassandraKeyspace getKeyspace(string name) 
	{ 
		return new CassandraKeyspace(this, name); 
	}

	CassandraKeyspace createKeyspace(string name/*, ...*/,string strategy = "SimpleStrategy", int replication_factor = 1)
	{
		string sql = format(`CREATE KEYSPACE %s WITH replication = {'class': '%s', 'replication_factor': %s}`, name, strategy, replication_factor);
		this.executeQuery(sql);
		return getKeyspace(name);
	}

	void useKeyspace(string name)
	{
		if (name == usedKeyspace) 
			return;
		this.executeQuery(`USE `~name);
		usedKeyspace = name;
	}

	public void setLogLevel(CassLogLevel level)
	{
		cass_log_set_level(level);
	}

}

void printError(CassFuture* future, int line) 
{
	const char* message;
	size_t message_length;
	cass_future_error_message(future, &message, &message_length);
	import std.conv;
	throw new Exception("error message: " ~ cast(string)(message[0 .. message_length]) ~ " line:"~ to!string(line));
}