## DataStax D Driver for Apache Cassandra.

- examples:
- https://github.com/datastax/cpp-driver/tree/1.0/examples

## examples

```
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
```
