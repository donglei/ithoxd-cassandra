import std.stdio;
import std.datetime;

//http://datastax.github.io/cpp-driver/
void main()
{
	//testcassandraobj();
	testcassandrainsert();
	
}
import ithox.cassandra4d;
import ithox.cassandra;
import std.format;

void testcassandrainsert()
{
	CassandraClient client = new CassandraClient("10.1.12.240");
	client.setLogLevel(CassLogLevel.CASS_LOG_ERROR);
	//client.createKeyspace("donglei");
	auto ks = client.getKeyspace("donglei");

	for(auto i=0; i< 10000;i++)
	{
		
		//string sql = format("insert into users (id) values(%s)", i+6000);
		string sql = format("select * from users where id=%s;", i+6000 );
		auto result = ks.query(sql);
		///sql 执行成功
		if(result.isSuccess)
		{
			while(!result.empty)
			{
				writeln("result.row i", i , result.front.toAA);
				result.popFront();
			}
		}
		else
		{
			//执行失败
			writeln("faild");
		}
	}
}

void testcassandraobj()
{
	CassandraClient client = new CassandraClient("10.1.11.14");
	client.setLogLevel(CassLogLevel.CASS_LOG_ERROR);
	//client.createKeyspace("donglei");
	auto ks = client.getKeyspace("donglei");
	auto result = ks.query("SELECT users.* FROM users LEFT JOIN users2 ON users.user_id = users2.user_id  ");
	///sql 执行成功
	if(result.isSuccess)
	{
		while(!result.empty)
		{
			writeln("result.row", result.front.toAA);
			result.popFront();
		}
	}
	else
	{
		//执行失败
	}

}


import std.array;
alias const(ubyte)* cstring;
string fromCstring(cstring c, size_t len = size_t.max) {
	if(c is null)
		return null;
	if(len == 0)
		return "";
	if(len == size_t.max) {
		auto iterator = c;
		len =0;
		while(*iterator)
		{
			iterator++;
			len++;
		}
		assert(len >= 0);
	}
	return cast(string) (c[0 .. len].idup);
}
