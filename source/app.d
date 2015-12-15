import std.stdio;
//http://datastax.github.io/cpp-driver/
void main()
{
	testcassandra();
}

void testcassandra()
{
	import ithox.cassandra;
	import std.string;
	cass_log_set_level(CassLogLevel.CASS_LOG_ERROR);
	CassCluster* cluster = cass_cluster_new();
	CassSession* session = cass_session_new();
	cass_cluster_set_protocol_version( cluster,2);
	//cass_cluster_set_connection_heartbeat_interval(cluster,60);
	cass_cluster_set_contact_points(cluster, "10.1.12.64,10.1.11.31");

	CassFuture* connect_future = cass_session_connect(session, cluster);

	CassError rc = cass_future_error_code(connect_future);
	if(rc == CassError.CASS_OK)
	{ca
		CassFuture* close_future = null;
		CassStatement* statement = cass_statement_new("SELECT *  FROM mykeyspace64.users ", 0);
		CassFuture* result_future = cass_session_execute(session, statement);
		if(cass_future_error_code(result_future) == CassError.CASS_OK)
		{
			const CassResult* result = cass_future_get_result(result_future);
			CassIterator* rows = cass_iterator_from_result(result);
			while(cass_iterator_next(rows))
			{
				const CassRow* row = cass_iterator_get_row(rows);
				const CassValue* value = cass_row_get_column_by_name(row, "fname");
				const char* keyspace;
				size_t keyspace_length;
				cass_value_get_string(value, &keyspace, &keyspace_length);
				writeln("fname---",cast(string)(keyspace[0 .. keyspace_length]));


				const CassValue* user_id = cass_row_get_column_by_name(row, "user_id");
				cass_int32_t op;
				cass_value_get_int32(user_id, &op);
				writeln("userid---",op);

			}
			cass_result_free(result);
			cass_iterator_free(rows);
		}
		else
		{
			const char* message;
			size_t message_length;
			cass_future_error_message(result_future, &message, &message_length);
			writeln("error message---", cast(string)(message[0 .. message_length]));
		}
		cass_statement_free(statement);
		cass_future_free(result_future);

		/* Close the session */
		close_future = cass_session_close(session);
		cass_future_wait(close_future);
		cass_future_free(close_future);
	}
	cass_future_free(connect_future);
	cass_session_free(session);
	cass_cluster_free(cluster);
	
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

