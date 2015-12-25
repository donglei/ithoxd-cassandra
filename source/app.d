import std.stdio;

//http://datastax.github.io/cpp-driver/
void main()
{
	testcassandraobj();
	
}
import ithox.cassandra4d;
import ithox.cassandra;

void testcassandraobj()
{
	CassandraClient client = new CassandraClient("10.1.11.14");
	client.setLogLevel(CassLogLevel.CASS_LOG_ERROR);
	//client.createKeyspace("donglei");
	auto ks = client.getKeyspace("mykeyspace");
	auto result = ks.query("SELECT fname, lname  FROM users where user_id=1744");
	///sql 执行成功
	if(result.isSuccess)
	{
		writeln("result.row", result.front.toAA);
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
