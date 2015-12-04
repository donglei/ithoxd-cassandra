# 1 "cassandra.h"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "cassandra.h"
# 20 "cassandra.h"
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h" 1 3 4
# 147 "/usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h" 3 4
typedef long int ptrdiff_t;
# 212 "/usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 324 "/usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h" 3 4
typedef int wchar_t;
# 21 "cassandra.h" 2
# 62 "cassandra.h"
typedef enum { cass_false = 0, cass_true = 1 } cass_bool_t;

typedef float cass_float_t;
typedef double cass_double_t;


typedef signed char cass_int8_t;
typedef unsigned char cass_uint8_t;
# 79 "cassandra.h"
typedef short int cass_int16_t;
typedef short unsigned int cass_uint16_t;
# 90 "cassandra.h"
typedef int cass_int32_t;
typedef unsigned int cass_uint32_t;
# 101 "cassandra.h"
typedef long int cass_int64_t;
typedef long unsigned int cass_uint64_t;
# 114 "cassandra.h"
typedef cass_uint8_t cass_byte_t;
typedef cass_uint64_t cass_duration_t;
# 137 "cassandra.h"
typedef struct CassInet_ {



  cass_uint8_t address[16];



  cass_uint8_t address_length;
} CassInet;
# 158 "cassandra.h"
typedef struct CassUuid_ {







  cass_uint64_t time_and_version;
# 176 "cassandra.h"
  cass_uint64_t clock_seq_and_node;
} CassUuid;
# 186 "cassandra.h"
typedef struct CassCluster_ CassCluster;
# 198 "cassandra.h"
typedef struct CassSession_ CassSession;
# 210 "cassandra.h"
typedef struct CassStatement_ CassStatement;
# 219 "cassandra.h"
typedef struct CassBatch_ CassBatch;
# 231 "cassandra.h"
typedef struct CassFuture_ CassFuture;
# 242 "cassandra.h"
typedef struct CassPrepared_ CassPrepared;
# 252 "cassandra.h"
typedef struct CassResult_ CassResult;






typedef struct CassErrorResult_ CassErrorResult;






typedef struct CassIterator_ CassIterator;






typedef struct CassRow_ CassRow;






typedef struct CassValue_ CassValue;







typedef struct CassDataType_ CassDataType;




typedef struct CassFunctionMeta_ CassFunctionMeta;




typedef struct CassAggregateMeta_ CassAggregateMeta;






typedef struct CassCollection_ CassCollection;






typedef struct CassTuple_ CassTuple;






typedef struct CassUserType_ CassUserType;






typedef struct CassSsl_ CassSsl;






typedef struct CassSchemaMeta_ CassSchemaMeta;






typedef struct CassKeyspaceMeta_ CassKeyspaceMeta;






typedef struct CassTableMeta_ CassTableMeta;






typedef struct CassColumnMeta_ CassColumnMeta;
# 363 "cassandra.h"
typedef struct CassUuidGen_ CassUuidGen;
# 374 "cassandra.h"
typedef struct CassTimestampGen_ CassTimestampGen;




typedef struct CassRetryPolicy_ CassRetryPolicy;




typedef struct CassCustomPayload_ CassCustomPayload;






typedef struct CassMetrics_ {
  struct {
    cass_uint64_t min;
    cass_uint64_t max;
    cass_uint64_t mean;
    cass_uint64_t stddev;
    cass_uint64_t median;
    cass_uint64_t percentile_75th;
    cass_uint64_t percentile_95th;
    cass_uint64_t percentile_98th;
    cass_uint64_t percentile_99th;
    cass_uint64_t percentile_999th;
    cass_double_t mean_rate;
    cass_double_t one_minute_rate;
    cass_double_t five_minute_rate;
    cass_double_t fifteen_minute_rate;
  } requests;

  struct {
    cass_uint64_t total_connections;
    cass_uint64_t available_connections;
    cass_uint64_t exceeded_pending_requests_water_mark;
    cass_uint64_t exceeded_write_bytes_water_mark;
  } stats;

  struct {
    cass_uint64_t connection_timeouts;
    cass_uint64_t pending_request_timeouts;
    cass_uint64_t request_timeouts;
  } errors;

} CassMetrics;

typedef enum CassConsistency_ {
  CASS_CONSISTENCY_UNKNOWN = 0xFFFF,
  CASS_CONSISTENCY_ANY = 0x0000,
  CASS_CONSISTENCY_ONE = 0x0001,
  CASS_CONSISTENCY_TWO = 0x0002,
  CASS_CONSISTENCY_THREE = 0x0003,
  CASS_CONSISTENCY_QUORUM = 0x0004,
  CASS_CONSISTENCY_ALL = 0x0005,
  CASS_CONSISTENCY_LOCAL_QUORUM = 0x0006,
  CASS_CONSISTENCY_EACH_QUORUM = 0x0007,
  CASS_CONSISTENCY_SERIAL = 0x0008,
  CASS_CONSISTENCY_LOCAL_SERIAL = 0x0009,
  CASS_CONSISTENCY_LOCAL_ONE = 0x000A
} CassConsistency;
# 453 "cassandra.h"
typedef enum CassWriteType_ {
  CASS_WRITE_TYPE_UKNOWN,
  CASS_WRITE_TYPE_SIMPLE,
  CASS_WRITE_TYPE_BATCH,
  CASS_WRITE_TYPE_UNLOGGED_BATCH,
  CASS_WRITE_TYPE_COUNTER,
  CASS_WRITE_TYPE_BATCH_LOG,
  CASS_WRITE_TYPE_CAS
} CassWriteType;
# 471 "cassandra.h"
typedef enum CassValueType_ {
  CASS_VALUE_TYPE_UNKNOWN = 0xFFFF,
  CASS_VALUE_TYPE_CUSTOM = 0x0000,
  CASS_VALUE_TYPE_ASCII = 0x0001,
  CASS_VALUE_TYPE_BIGINT = 0x0002,
  CASS_VALUE_TYPE_BLOB = 0x0003,
  CASS_VALUE_TYPE_BOOLEAN = 0x0004,
  CASS_VALUE_TYPE_COUNTER = 0x0005,
  CASS_VALUE_TYPE_DECIMAL = 0x0006,
  CASS_VALUE_TYPE_DOUBLE = 0x0007,
  CASS_VALUE_TYPE_FLOAT = 0x0008,
  CASS_VALUE_TYPE_INT = 0x0009,
  CASS_VALUE_TYPE_TEXT = 0x000A,
  CASS_VALUE_TYPE_TIMESTAMP = 0x000B,
  CASS_VALUE_TYPE_UUID = 0x000C,
  CASS_VALUE_TYPE_VARCHAR = 0x000D,
  CASS_VALUE_TYPE_VARINT = 0x000E,
  CASS_VALUE_TYPE_TIMEUUID = 0x000F,
  CASS_VALUE_TYPE_INET = 0x0010,
  CASS_VALUE_TYPE_DATE = 0x0011,
  CASS_VALUE_TYPE_TIME = 0x0012,
  CASS_VALUE_TYPE_SMALL_INT = 0x0013,
  CASS_VALUE_TYPE_TINY_INT = 0x0014,
  CASS_VALUE_TYPE_LIST = 0x0020,
  CASS_VALUE_TYPE_MAP = 0x0021,
  CASS_VALUE_TYPE_SET = 0x0022,
  CASS_VALUE_TYPE_UDT = 0x0030,
  CASS_VALUE_TYPE_TUPLE = 0x0031,

  CASS_VALUE_TYPE_LAST_ENTRY

} CassValueType;

typedef enum CassCollectionType_ {
  CASS_COLLECTION_TYPE_LIST = CASS_VALUE_TYPE_LIST,
  CASS_COLLECTION_TYPE_MAP = CASS_VALUE_TYPE_MAP,
  CASS_COLLECTION_TYPE_SET = CASS_VALUE_TYPE_SET
} CassCollectionType;

typedef enum CassBatchType_ {
  CASS_BATCH_TYPE_LOGGED = 0,
  CASS_BATCH_TYPE_UNLOGGED = 1,
  CASS_BATCH_TYPE_COUNTER = 2
} CassBatchType;

typedef enum CassIteratorType_ {
  CASS_ITERATOR_TYPE_RESULT,
  CASS_ITERATOR_TYPE_ROW,
  CASS_ITERATOR_TYPE_COLLECTION,
  CASS_ITERATOR_TYPE_MAP,
  CASS_ITERATOR_TYPE_TUPLE,
  CASS_ITERATOR_TYPE_USER_TYPE_FIELD,
  CASS_ITERATOR_TYPE_META_FIELD,
  CASS_ITERATOR_TYPE_KEYSPACE_META,
  CASS_ITERATOR_TYPE_TABLE_META,
  CASS_ITERATOR_TYPE_TYPE_META,
  CASS_ITERATOR_TYPE_FUNCTION_META,
  CASS_ITERATOR_TYPE_AGGREGATE_META,
  CASS_ITERATOR_TYPE_COLUMN_META
} CassIteratorType;
# 541 "cassandra.h"
typedef enum CassLogLevel_ {

  CASS_LOG_DISABLED, CASS_LOG_CRITICAL, CASS_LOG_ERROR, CASS_LOG_WARN, CASS_LOG_INFO, CASS_LOG_DEBUG, CASS_LOG_TRACE,


  CASS_LOG_LAST_ENTRY

} CassLogLevel;

typedef enum CassSslVerifyFlags {
  CASS_SSL_VERIFY_NONE,
  CASS_SSL_VERIFY_PEER_CERT,
  CASS_SSL_VERIFY_PEER_IDENTITY
} CassSslVerifyFlags;

typedef enum CassColumnType_ {
  CASS_COLUMN_TYPE_REGULAR,
  CASS_COLUMN_TYPE_PARTITION_KEY,
  CASS_COLUMN_TYPE_CLUSTERING_KEY,
  CASS_COLUMN_TYPE_STATIC
} CassColumnType;

typedef enum CassErrorSource_ {
  CASS_ERROR_SOURCE_NONE,
  CASS_ERROR_SOURCE_LIB,
  CASS_ERROR_SOURCE_SERVER,
  CASS_ERROR_SOURCE_SSL,
  CASS_ERROR_SOURCE_COMPRESSION
} CassErrorSource;
# 626 "cassandra.h"
typedef enum CassError_ {
  CASS_OK = 0,

  CASS_ERROR_LIB_BAD_PARAMS = ((CASS_ERROR_SOURCE_LIB << 24) | 1), CASS_ERROR_LIB_NO_STREAMS = ((CASS_ERROR_SOURCE_LIB << 24) | 2), CASS_ERROR_LIB_UNABLE_TO_INIT = ((CASS_ERROR_SOURCE_LIB << 24) | 3), CASS_ERROR_LIB_MESSAGE_ENCODE = ((CASS_ERROR_SOURCE_LIB << 24) | 4), CASS_ERROR_LIB_HOST_RESOLUTION = ((CASS_ERROR_SOURCE_LIB << 24) | 5), CASS_ERROR_LIB_UNEXPECTED_RESPONSE = ((CASS_ERROR_SOURCE_LIB << 24) | 6), CASS_ERROR_LIB_REQUEST_QUEUE_FULL = ((CASS_ERROR_SOURCE_LIB << 24) | 7), CASS_ERROR_LIB_NO_AVAILABLE_IO_THREAD = ((CASS_ERROR_SOURCE_LIB << 24) | 8), CASS_ERROR_LIB_WRITE_ERROR = ((CASS_ERROR_SOURCE_LIB << 24) | 9), CASS_ERROR_LIB_NO_HOSTS_AVAILABLE = ((CASS_ERROR_SOURCE_LIB << 24) | 10), CASS_ERROR_LIB_INDEX_OUT_OF_BOUNDS = ((CASS_ERROR_SOURCE_LIB << 24) | 11), CASS_ERROR_LIB_INVALID_ITEM_COUNT = ((CASS_ERROR_SOURCE_LIB << 24) | 12), CASS_ERROR_LIB_INVALID_VALUE_TYPE = ((CASS_ERROR_SOURCE_LIB << 24) | 13), CASS_ERROR_LIB_REQUEST_TIMED_OUT = ((CASS_ERROR_SOURCE_LIB << 24) | 14), CASS_ERROR_LIB_UNABLE_TO_SET_KEYSPACE = ((CASS_ERROR_SOURCE_LIB << 24) | 15), CASS_ERROR_LIB_CALLBACK_ALREADY_SET = ((CASS_ERROR_SOURCE_LIB << 24) | 16), CASS_ERROR_LIB_INVALID_STATEMENT_TYPE = ((CASS_ERROR_SOURCE_LIB << 24) | 17), CASS_ERROR_LIB_NAME_DOES_NOT_EXIST = ((CASS_ERROR_SOURCE_LIB << 24) | 18), CASS_ERROR_LIB_UNABLE_TO_DETERMINE_PROTOCOL = ((CASS_ERROR_SOURCE_LIB << 24) | 19), CASS_ERROR_LIB_NULL_VALUE = ((CASS_ERROR_SOURCE_LIB << 24) | 20), CASS_ERROR_LIB_NOT_IMPLEMENTED = ((CASS_ERROR_SOURCE_LIB << 24) | 21), CASS_ERROR_LIB_UNABLE_TO_CONNECT = ((CASS_ERROR_SOURCE_LIB << 24) | 22), CASS_ERROR_LIB_UNABLE_TO_CLOSE = ((CASS_ERROR_SOURCE_LIB << 24) | 23), CASS_ERROR_LIB_NO_PAGING_STATE = ((CASS_ERROR_SOURCE_LIB << 24) | 24), CASS_ERROR_LIB_PARAMETER_UNSET = ((CASS_ERROR_SOURCE_LIB << 24) | 25), CASS_ERROR_LIB_INVALID_ERROR_RESULT_TYPE = ((CASS_ERROR_SOURCE_LIB << 24) | 26), CASS_ERROR_LIB_INVALID_FUTURE_TYPE = ((CASS_ERROR_SOURCE_LIB << 24) | 27), CASS_ERROR_SERVER_SERVER_ERROR = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x0000), CASS_ERROR_SERVER_PROTOCOL_ERROR = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x000A), CASS_ERROR_SERVER_BAD_CREDENTIALS = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x0100), CASS_ERROR_SERVER_UNAVAILABLE = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x1000), CASS_ERROR_SERVER_OVERLOADED = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x1001), CASS_ERROR_SERVER_IS_BOOTSTRAPPING = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x1002), CASS_ERROR_SERVER_TRUNCATE_ERROR = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x1003), CASS_ERROR_SERVER_WRITE_TIMEOUT = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x1100), CASS_ERROR_SERVER_READ_TIMEOUT = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x1200), CASS_ERROR_SERVER_READ_FAILURE = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x1300), CASS_ERROR_SERVER_FUNCTION_FAILURE = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x1400), CASS_ERROR_SERVER_WRITE_FAILURE = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x1500), CASS_ERROR_SERVER_SYNTAX_ERROR = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x2000), CASS_ERROR_SERVER_UNAUTHORIZED = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x2100), CASS_ERROR_SERVER_INVALID_QUERY = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x2200), CASS_ERROR_SERVER_CONFIG_ERROR = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x2300), CASS_ERROR_SERVER_ALREADY_EXISTS = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x2400), CASS_ERROR_SERVER_UNPREPARED = ((CASS_ERROR_SOURCE_SERVER << 24) | 0x2500), CASS_ERROR_SSL_INVALID_CERT = ((CASS_ERROR_SOURCE_SSL << 24) | 1), CASS_ERROR_SSL_INVALID_PRIVATE_KEY = ((CASS_ERROR_SOURCE_SSL << 24) | 2), CASS_ERROR_SSL_NO_PEER_CERT = ((CASS_ERROR_SOURCE_SSL << 24) | 3), CASS_ERROR_SSL_INVALID_PEER_CERT = ((CASS_ERROR_SOURCE_SSL << 24) | 4), CASS_ERROR_SSL_IDENTITY_MISMATCH = ((CASS_ERROR_SOURCE_SSL << 24) | 5), CASS_ERROR_SSL_PROTOCOL_ERROR = ((CASS_ERROR_SOURCE_SSL << 24) | 6),


  CASS_ERROR_LAST_ENTRY

} CassError;
# 645 "cassandra.h"
typedef void (*CassFutureCallback)(CassFuture* future,
                                   void* data);
# 656 "cassandra.h"
typedef struct CassLogMessage_ {



  cass_uint64_t time_ms;
  CassLogLevel severity;
  const char* file;
  int line;
  const char* function;
  char message[256];
} CassLogMessage;
# 677 "cassandra.h"
typedef void (*CassLogCallback)(const CassLogMessage* message,
                                void* data);
# 695 "cassandra.h"
__attribute__ ((visibility("default"))) CassCluster*
cass_cluster_new();
# 705 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_free(CassCluster* cluster);
# 725 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_contact_points(CassCluster* cluster,
                                const char* contact_points);
# 742 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_contact_points_n(CassCluster* cluster,
                                  const char* contact_points,
                                  size_t contact_points_length);
# 758 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_port(CassCluster* cluster,
                      int port);
# 772 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_ssl(CassCluster* cluster,
                     CassSsl* ssl);
# 788 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_protocol_version(CassCluster* cluster,
                                  int protocol_version);
# 804 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_num_threads_io(CassCluster* cluster,
                                unsigned num_threads);
# 820 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_queue_size_io(CassCluster* cluster,
                               unsigned queue_size);
# 836 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_queue_size_event(CassCluster* cluster,
                                  unsigned queue_size);
# 852 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_queue_size_log(CassCluster* cluster,
                                unsigned queue_size);
# 868 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_core_connections_per_host(CassCluster* cluster,
                                           unsigned num_connections);
# 884 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_max_connections_per_host(CassCluster* cluster,
                                          unsigned num_connections);
# 898 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_reconnect_wait_time(CassCluster* cluster,
                                     unsigned wait_time);
# 915 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_max_concurrent_creation(CassCluster* cluster,
                                         unsigned num_connections);
# 932 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_max_concurrent_requests_threshold(CassCluster* cluster,
                                                   unsigned num_requests);
# 948 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_max_requests_per_flush(CassCluster* cluster,
                                        unsigned num_requests);
# 965 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_write_bytes_high_water_mark(CassCluster* cluster,
                                             unsigned num_bytes);
# 982 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_write_bytes_low_water_mark(CassCluster* cluster,
                                            unsigned num_bytes);
# 1000 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_pending_requests_high_water_mark(CassCluster* cluster,
                                                  unsigned num_requests);
# 1018 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_pending_requests_low_water_mark(CassCluster* cluster,
                                                 unsigned num_requests);
# 1032 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_connect_timeout(CassCluster* cluster,
                                 unsigned timeout_ms);
# 1046 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_request_timeout(CassCluster* cluster,
                                 unsigned timeout_ms);
# 1059 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_credentials(CassCluster* cluster,
                             const char* username,
                             const char* password);
# 1079 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_credentials_n(CassCluster* cluster,
                               const char* username,
                               size_t username_length,
                               const char* password,
                               size_t password_length);
# 1096 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_load_balance_round_robin(CassCluster* cluster);
# 1121 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_load_balance_dc_aware(CassCluster* cluster,
                                       const char* local_dc,
                                       unsigned used_hosts_per_remote_dc,
                                       cass_bool_t allow_remote_dcs_for_local_cl);
# 1143 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_cluster_set_load_balance_dc_aware_n(CassCluster* cluster,
                                         const char* local_dc,
                                         size_t local_dc_length,
                                         unsigned used_hosts_per_remote_dc,
                                         cass_bool_t allow_remote_dcs_for_local_cl);
# 1170 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_token_aware_routing(CassCluster* cluster,
                                     cass_bool_t enabled);
# 1189 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_latency_aware_routing(CassCluster* cluster,
                                       cass_bool_t enabled);
# 1220 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_latency_aware_routing_settings(CassCluster* cluster,
                                                cass_double_t exclusion_threshold,
                                                cass_uint64_t scale_ms,
                                                cass_uint64_t retry_period_ms,
                                                cass_uint64_t update_rate_ms,
                                                cass_uint64_t min_measured);
# 1248 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_whitelist_filtering(CassCluster* cluster,
                                     const char* hosts);
# 1265 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_whitelist_filtering_n(CassCluster* cluster,
                                       const char* hosts,
                                       size_t hosts_length);
# 1280 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_tcp_nodelay(CassCluster* cluster,
                             cass_bool_t enabled);
# 1296 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_tcp_keepalive(CassCluster* cluster,
                               cass_bool_t enabled,
                               unsigned delay_secs);
# 1314 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_timestamp_gen(CassCluster* cluster,
                               CassTimestampGen* timestamp_gen);
# 1331 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_connection_heartbeat_interval(CassCluster* cluster,
                                               unsigned interval_secs);
# 1346 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_connection_idle_timeout(CassCluster* cluster,
                                         unsigned timeout_secs);
# 1370 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_retry_policy(CassCluster* cluster,
                              CassRetryPolicy* retry_policy);
# 1391 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_cluster_set_use_schema(CassCluster* cluster,
                            cass_bool_t enabled);
# 1410 "cassandra.h"
__attribute__ ((visibility("default"))) CassSession*
cass_session_new();
# 1424 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_session_free(CassSession* session);
# 1438 "cassandra.h"
__attribute__ ((visibility("default"))) CassFuture*
cass_session_connect(CassSession* session,
                     const CassCluster* cluster);
# 1454 "cassandra.h"
__attribute__ ((visibility("default"))) CassFuture*
cass_session_connect_keyspace(CassSession* session,
                              const CassCluster* cluster,
                              const char* keyspace);
# 1473 "cassandra.h"
__attribute__ ((visibility("default"))) CassFuture*
cass_session_connect_keyspace_n(CassSession* session,
                                const CassCluster* cluster,
                                const char* keyspace,
                                size_t keyspace_length);
# 1489 "cassandra.h"
__attribute__ ((visibility("default"))) CassFuture*
cass_session_close(CassSession* session);
# 1504 "cassandra.h"
__attribute__ ((visibility("default"))) CassFuture*
cass_session_prepare(CassSession* session,
                     const char* query);
# 1521 "cassandra.h"
__attribute__ ((visibility("default"))) CassFuture*
cass_session_prepare_n(CassSession* session,
                       const char* query,
                       size_t query_length);
# 1537 "cassandra.h"
__attribute__ ((visibility("default"))) CassFuture*
cass_session_execute(CassSession* session,
                     const CassStatement* statement);
# 1552 "cassandra.h"
__attribute__ ((visibility("default"))) CassFuture*
cass_session_execute_batch(CassSession* session,
                           const CassBatch* batch);
# 1569 "cassandra.h"
__attribute__ ((visibility("default"))) const CassSchemaMeta*
cass_session_get_schema_meta(const CassSession* session);
# 1582 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_session_get_metrics(const CassSession* session,
                         CassMetrics* output);
# 1599 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_schema_meta_free(const CassSchemaMeta* schema_meta);
# 1609 "cassandra.h"
__attribute__ ((visibility("default"))) cass_uint32_t
cass_schema_meta_snapshot_version(const CassSchemaMeta* schema_meta);
# 1622 "cassandra.h"
__attribute__ ((visibility("default"))) const CassKeyspaceMeta*
cass_schema_meta_keyspace_by_name(const CassSchemaMeta* schema_meta,
                                  const char* keyspace);
# 1639 "cassandra.h"
__attribute__ ((visibility("default"))) const CassKeyspaceMeta*
cass_schema_meta_keyspace_by_name_n(const CassSchemaMeta* schema_meta,
                                    const char* keyspace,
                                    size_t keyspace_length);
# 1654 "cassandra.h"
__attribute__ ((visibility("default"))) const CassTableMeta*
cass_keyspace_meta_table_by_name(const CassKeyspaceMeta* keyspace_meta,
                                 const char* table);
# 1671 "cassandra.h"
__attribute__ ((visibility("default"))) const CassTableMeta*
cass_keyspace_meta_table_by_name_n(const CassKeyspaceMeta* keyspace_meta,
                                   const char* table,
                                   size_t table_length);
# 1686 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_keyspace_meta_user_type_by_name(const CassKeyspaceMeta* keyspace_meta,
                                     const char* type);
# 1703 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_keyspace_meta_user_type_by_name_n(const CassKeyspaceMeta* keyspace_meta,
                                       const char* type,
                                       size_t type_length);
# 1720 "cassandra.h"
__attribute__ ((visibility("default"))) const CassFunctionMeta*
cass_keyspace_meta_function_by_name(const CassKeyspaceMeta* keyspace_meta,
                                    const char* name,
                                    const char* arguments);
# 1740 "cassandra.h"
__attribute__ ((visibility("default"))) const CassFunctionMeta*
cass_keyspace_meta_function_by_name_n(const CassKeyspaceMeta* keyspace_meta,
                                      const char* name,
                                      size_t name_length,
                                      const char* arguments,
                                      size_t arguments_length);
# 1759 "cassandra.h"
__attribute__ ((visibility("default"))) const CassAggregateMeta*
cass_keyspace_meta_aggregate_by_name(const CassKeyspaceMeta* keyspace_meta,
                                     const char* name,
                                     const char* arguments);
# 1779 "cassandra.h"
__attribute__ ((visibility("default"))) const CassAggregateMeta*
cass_keyspace_meta_aggregate_by_name_n(const CassKeyspaceMeta* keyspace_meta,
                                       const char* name,
                                       size_t name_length,
                                       const char* arguments,
                                       size_t arguments_length);
# 1795 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_keyspace_meta_name(const CassKeyspaceMeta* keyspace_meta,
                        const char** name,
                        size_t* name_length);
# 1810 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_keyspace_meta_field_by_name(const CassKeyspaceMeta* keyspace_meta,
                                 const char* name);
# 1827 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_keyspace_meta_field_by_name_n(const CassKeyspaceMeta* keyspace_meta,
                                   const char* name,
                                   size_t name_length);
# 1842 "cassandra.h"
__attribute__ ((visibility("default"))) const CassColumnMeta*
cass_table_meta_column_by_name(const CassTableMeta* table_meta,
                               const char* column);
# 1859 "cassandra.h"
__attribute__ ((visibility("default"))) const CassColumnMeta*
cass_table_meta_column_by_name_n(const CassTableMeta* table_meta,
                                 const char* column,
                                 size_t column_length);
# 1873 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_table_meta_name(const CassTableMeta* table_meta,
                     const char** name,
                     size_t* name_length);
# 1886 "cassandra.h"
__attribute__ ((visibility("default"))) size_t
cass_table_meta_column_count(const CassTableMeta* table_meta);
# 1898 "cassandra.h"
__attribute__ ((visibility("default"))) const CassColumnMeta*
cass_table_meta_column(const CassTableMeta* table_meta,
                       size_t index);
# 1910 "cassandra.h"
__attribute__ ((visibility("default"))) size_t
cass_table_meta_partition_key_count(const CassTableMeta* table_meta);
# 1922 "cassandra.h"
__attribute__ ((visibility("default"))) const CassColumnMeta*
cass_table_meta_partition_key(const CassTableMeta* table_meta,
                              size_t index);
# 1934 "cassandra.h"
__attribute__ ((visibility("default"))) size_t
cass_table_meta_clustering_key_count(const CassTableMeta* table_meta);
# 1946 "cassandra.h"
__attribute__ ((visibility("default"))) const CassColumnMeta*
cass_table_meta_clustering_key(const CassTableMeta* table_meta,
                               size_t index);
# 1961 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_table_meta_field_by_name(const CassTableMeta* table_meta,
                              const char* name);
# 1978 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_table_meta_field_by_name_n(const CassTableMeta* table_meta,
                                const char* name,
                                size_t name_length);
# 1992 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_column_meta_name(const CassColumnMeta* column_meta,
                      const char** name,
                      size_t* name_length);
# 2005 "cassandra.h"
__attribute__ ((visibility("default"))) CassColumnType
cass_column_meta_type(const CassColumnMeta* column_meta);
# 2016 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_column_meta_data_type(const CassColumnMeta* column_meta);
# 2029 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_column_meta_field_by_name(const CassColumnMeta* column_meta,
                               const char* name);
# 2046 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_column_meta_field_by_name_n(const CassColumnMeta* column_meta,
                                 const char* name,
                                 size_t name_length);
# 2060 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_function_meta_name(const CassFunctionMeta* function_meta,
                        const char** name,
                        size_t* name_length);
# 2076 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_function_meta_full_name(const CassFunctionMeta* function_meta,
                             const char** full_name,
                             size_t* full_name_length);
# 2090 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_function_meta_body(const CassFunctionMeta* function_meta,
                        const char** body,
                        size_t* body_length);
# 2104 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_function_meta_language(const CassFunctionMeta* function_meta,
                            const char** language,
                            size_t* language_length);
# 2117 "cassandra.h"
__attribute__ ((visibility("default"))) cass_bool_t
cass_function_meta_called_on_null_input(const CassFunctionMeta* function_meta);
# 2128 "cassandra.h"
__attribute__ ((visibility("default"))) size_t
cass_function_meta_argument_count(const CassFunctionMeta* function_meta);
# 2143 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_function_meta_argument(const CassFunctionMeta* function_meta,
                            size_t index,
                            const char** name,
                            size_t* name_length,
                            const CassDataType** type);
# 2159 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_function_meta_argument_type_by_name(const CassFunctionMeta* function_meta,
                                         const char* name);
# 2176 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_function_meta_argument_type_by_name_n(const CassFunctionMeta* function_meta,
                                           const char* name,
                                           size_t name_length);
# 2189 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_function_meta_return_type(const CassFunctionMeta* function_meta);
# 2202 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_function_meta_field_by_name(const CassFunctionMeta* function_meta,
                                 const char* name);
# 2219 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_function_meta_field_by_name_n(const CassFunctionMeta* function_meta,
                                   const char* name,
                                   size_t name_length);
# 2233 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_aggregate_meta_name(const CassAggregateMeta* aggregate_meta,
                         const char** name,
                         size_t* name_length);
# 2249 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_aggregate_meta_full_name(const CassAggregateMeta* aggregate_meta,
                              const char** full_name,
                              size_t* full_name_length);
# 2262 "cassandra.h"
__attribute__ ((visibility("default"))) size_t
cass_aggregate_meta_argument_count(const CassAggregateMeta* aggregate_meta);
# 2274 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_aggregate_meta_argument_type(const CassAggregateMeta* aggregate_meta,
                                  size_t index);
# 2286 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_aggregate_meta_return_type(const CassAggregateMeta* aggregate_meta);
# 2297 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_aggregate_meta_state_type(const CassAggregateMeta* aggregate_meta);
# 2308 "cassandra.h"
__attribute__ ((visibility("default"))) const CassFunctionMeta*
cass_aggregate_meta_state_func(const CassAggregateMeta* aggregate_meta);
# 2319 "cassandra.h"
__attribute__ ((visibility("default"))) const CassFunctionMeta*
cass_aggregate_meta_final_func(const CassAggregateMeta* aggregate_meta);
# 2330 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_aggregate_meta_init_cond(const CassAggregateMeta* aggregate_meta);
# 2343 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_aggregate_meta_field_by_name(const CassAggregateMeta* aggregate_meta,
                                  const char* name);
# 2360 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_aggregate_meta_field_by_name_n(const CassAggregateMeta* aggregate_meta,
                                    const char* name,
                                    size_t name_length);
# 2380 "cassandra.h"
__attribute__ ((visibility("default"))) CassSsl*
cass_ssl_new();
# 2390 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_ssl_free(CassSsl* ssl);
# 2403 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_ssl_add_trusted_cert(CassSsl* ssl,
                          const char* cert);
# 2420 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_ssl_add_trusted_cert_n(CassSsl* ssl,
                            const char* cert,
                            size_t cert_length);
# 2442 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_ssl_set_verify_flags(CassSsl* ssl,
                          int flags);
# 2457 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_ssl_set_cert(CassSsl* ssl,
                  const char* cert);
# 2474 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_ssl_set_cert_n(CassSsl* ssl,
                    const char* cert,
                    size_t cert_length);
# 2490 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_ssl_set_private_key(CassSsl* ssl,
                         const char* key,
                         const char* password);
# 2510 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_ssl_set_private_key_n(CassSsl* ssl,
                           const char* key,
                           size_t key_length,
                           const char* password,
                           size_t password_length);
# 2528 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_future_free(CassFuture* future);
# 2541 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_future_set_callback(CassFuture* future,
                         CassFutureCallback callback,
                         void* data);
# 2554 "cassandra.h"
__attribute__ ((visibility("default"))) cass_bool_t
cass_future_ready(CassFuture* future);
# 2567 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_future_wait(CassFuture* future);
# 2579 "cassandra.h"
__attribute__ ((visibility("default"))) cass_bool_t
cass_future_wait_timed(CassFuture* future,
                       cass_duration_t timeout_us);
# 2595 "cassandra.h"
__attribute__ ((visibility("default"))) const CassResult*
cass_future_get_result(CassFuture* future);
# 2611 "cassandra.h"
__attribute__ ((visibility("default"))) const CassErrorResult*
cass_future_get_error_result(CassFuture* future);
# 2627 "cassandra.h"
__attribute__ ((visibility("default"))) const CassPrepared*
cass_future_get_prepared(CassFuture* future);
# 2641 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_future_error_code(CassFuture* future);
# 2655 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_future_error_message(CassFuture* future,
                          const char** message,
                          size_t* message_length);
# 2669 "cassandra.h"
__attribute__ ((visibility("default"))) size_t
cass_future_custom_payload_item_count(CassFuture* future);
# 2686 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_future_custom_payload_item(CassFuture* future,
                                size_t index,
                                const char** name,
                                size_t* name_length,
                                const cass_byte_t** value,
                                size_t* value_size);
# 2712 "cassandra.h"
__attribute__ ((visibility("default"))) CassStatement*
cass_statement_new(const char* query,
                   size_t parameter_count);
# 2729 "cassandra.h"
__attribute__ ((visibility("default"))) CassStatement*
cass_statement_new_n(const char* query,
                     size_t query_length,
                     size_t parameter_count);
# 2742 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_statement_free(CassStatement* statement);
# 2762 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_add_key_index(CassStatement* statement,
                             size_t index);
# 2779 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_set_keyspace(CassStatement* statement,
                            const char* keyspace);
# 2796 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_set_keyspace_n(CassStatement* statement,
                              const char* keyspace,
                              size_t keyspace_length);
# 2812 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_set_consistency(CassStatement* statement,
                               CassConsistency consistency);
# 2827 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_set_serial_consistency(CassStatement* statement,
                                      CassConsistency serial_consistency);
# 2842 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_set_paging_size(CassStatement* statement,
                               int page_size);
# 2856 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_set_paging_state(CassStatement* statement,
                                const CassResult* result);
# 2877 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_set_paging_state_token(CassStatement* statement,
                                      const char* paging_state,
                                      size_t paging_state_size);
# 2891 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_set_timestamp(CassStatement* statement,
                             cass_int64_t timestamp);
# 2905 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_set_retry_policy(CassStatement* statement,
                                CassRetryPolicy* retry_policy);
# 2918 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_set_custom_payload(CassStatement* statement,
                                  const CassCustomPayload* payload);
# 2931 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_null(CassStatement* statement,
                         size_t index);
# 2947 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_null_by_name(CassStatement* statement,
                                 const char* name);
# 2964 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_null_by_name_n(CassStatement* statement,
                                   const char* name,
                                   size_t name_length);
# 2979 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_int8(CassStatement* statement,
                         size_t index,
                         cass_int8_t value);
# 2997 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_int8_by_name(CassStatement* statement,
                                 const char* name,
                                 cass_int8_t value);
# 3016 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_int8_by_name_n(CassStatement* statement,
                                   const char* name,
                                   size_t name_length,
                                   cass_int8_t value);
# 3032 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_int16(CassStatement* statement,
                          size_t index,
                          cass_int16_t value);
# 3050 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_int16_by_name(CassStatement* statement,
                                  const char* name,
                                  cass_int16_t value);
# 3069 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_int16_by_name_n(CassStatement* statement,
                                    const char* name,
                                    size_t name_length,
                                    cass_int16_t value);
# 3085 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_int32(CassStatement* statement,
                          size_t index,
                          cass_int32_t value);
# 3103 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_int32_by_name(CassStatement* statement,
                                  const char* name,
                                  cass_int32_t value);
# 3122 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_int32_by_name_n(CassStatement* statement,
                                    const char* name,
                                    size_t name_length,
                                    cass_int32_t value);
# 3138 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_uint32(CassStatement* statement,
                           size_t index,
                           cass_uint32_t value);
# 3156 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_uint32_by_name(CassStatement* statement,
                                   const char* name,
                                   cass_uint32_t value);
# 3175 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_uint32_by_name_n(CassStatement* statement,
                                     const char* name,
                                     size_t name_length,
                                     cass_uint32_t value);
# 3192 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_int64(CassStatement* statement,
                          size_t index,
                          cass_int64_t value);
# 3211 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_int64_by_name(CassStatement* statement,
                                  const char* name,
                                  cass_int64_t value);
# 3230 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_int64_by_name_n(CassStatement* statement,
                                    const char* name,
                                    size_t name_length,
                                    cass_int64_t value);
# 3246 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_float(CassStatement* statement,
                          size_t index,
                          cass_float_t value);
# 3264 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_float_by_name(CassStatement* statement,
                                  const char* name,
                                  cass_float_t value);
# 3283 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_float_by_name_n(CassStatement* statement,
                                    const char* name,
                                    size_t name_length,
                                    cass_float_t value);
# 3299 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_double(CassStatement* statement,
                           size_t index,
                           cass_double_t value);
# 3317 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_double_by_name(CassStatement* statement,
                                   const char* name,
                                   cass_double_t value);
# 3336 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_double_by_name_n(CassStatement* statement,
                                     const char* name,
                                     size_t name_length,
                                     cass_double_t value);
# 3352 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_bool(CassStatement* statement,
                         size_t index,
                         cass_bool_t value);
# 3370 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_bool_by_name(CassStatement* statement,
                                 const char* name,
                                 cass_bool_t value);
# 3389 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_bool_by_name_n(CassStatement* statement,
                                   const char* name,
                                   size_t name_length,
                                   cass_bool_t value);
# 3407 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_string(CassStatement* statement,
                           size_t index,
                           const char* value);
# 3426 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_string_n(CassStatement* statement,
                             size_t index,
                             const char* value,
                             size_t value_length);
# 3447 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_string_by_name(CassStatement* statement,
                                   const char* name,
                                   const char* value);
# 3467 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_string_by_name_n(CassStatement* statement,
                                     const char* name,
                                     size_t name_length,
                                     const char* value,
                                     size_t value_length);
# 3486 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_bytes(CassStatement* statement,
                          size_t index,
                          const cass_byte_t* value,
                          size_t value_size);
# 3508 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_bytes_by_name(CassStatement* statement,
                                  const char* name,
                                  const cass_byte_t* value,
                                  size_t value_size);
# 3529 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_bytes_by_name_n(CassStatement* statement,
                                    const char* name,
                                    size_t name_length,
                                    const cass_byte_t* value,
                                    size_t value_size);
# 3546 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_uuid(CassStatement* statement,
                         size_t index,
                         CassUuid value);
# 3565 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_uuid_by_name(CassStatement* statement,
                                 const char* name,
                                 CassUuid value);
# 3584 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_uuid_by_name_n(CassStatement* statement,
                                   const char* name,
                                   size_t name_length,
                                   CassUuid value);
# 3600 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_inet(CassStatement* statement,
                         size_t index,
                         CassInet value);
# 3618 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_inet_by_name(CassStatement* statement,
                                 const char* name,
                                 CassInet value);
# 3637 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_inet_by_name_n(CassStatement* statement,
                                   const char* name,
                                   size_t name_length,
                                   CassInet value);
# 3656 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_decimal(CassStatement* statement,
                            size_t index,
                            const cass_byte_t* varint,
                            size_t varint_size,
                            cass_int32_t scale);
# 3679 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_decimal_by_name(CassStatement* statement,
                                    const char* name,
                                    const cass_byte_t* varint,
                                    size_t varint_size,
                                    cass_int32_t scale);
# 3702 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_decimal_by_name_n(CassStatement* statement,
                                      const char* name,
                                      size_t name_length,
                                      const cass_byte_t* varint,
                                      size_t varint_size,
                                      cass_int32_t scale);
# 3721 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_collection(CassStatement* statement,
                               size_t index,
                               const CassCollection* collection);
# 3740 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_collection_by_name(CassStatement* statement,
                                       const char* name,
                                       const CassCollection* collection);
# 3759 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_collection_by_name_n(CassStatement* statement,
                                         const char* name,
                                         size_t name_length,
                                         const CassCollection* collection);
# 3775 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_tuple(CassStatement* statement,
                          size_t index,
                          const CassTuple* tuple);
# 3793 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_tuple_by_name(CassStatement* statement,
                                  const char* name,
                                  const CassTuple* tuple);
# 3812 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_tuple_by_name_n(CassStatement* statement,
                                    const char* name,
                                    size_t name_length,
                                    const CassTuple* tuple);
# 3829 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_user_type(CassStatement* statement,
                              size_t index,
                              const CassUserType* user_type);
# 3844 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_user_type_by_name(CassStatement* statement,
                                      const char* name,
                                      const CassUserType* user_type);
# 3863 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_statement_bind_user_type_by_name_n(CassStatement* statement,
                                        const char* name,
                                        size_t name_length,
                                        const CassUserType* user_type);
# 3882 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_prepared_free(const CassPrepared* prepared);
# 3895 "cassandra.h"
__attribute__ ((visibility("default"))) CassStatement*
cass_prepared_bind(const CassPrepared* prepared);
# 3909 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_prepared_parameter_name(const CassPrepared* prepared,
                             size_t index,
                             const char** name,
                             size_t* name_length);
# 3925 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_prepared_parameter_data_type(const CassPrepared* prepared,
                                  size_t index);
# 3939 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_prepared_parameter_data_type_by_name(const CassPrepared* prepared,
                                          const char* name);
# 3957 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_prepared_parameter_data_type_by_name_n(const CassPrepared* prepared,
                                            const char* name,
                                            size_t name_length);
# 3978 "cassandra.h"
__attribute__ ((visibility("default"))) CassBatch*
cass_batch_new(CassBatchType type);
# 3989 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_batch_free(CassBatch* batch);
# 4001 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_batch_set_consistency(CassBatch* batch,
                           CassConsistency consistency);
# 4016 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_batch_set_serial_consistency(CassBatch* batch,
                                  CassConsistency serial_consistency);
# 4029 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_batch_set_timestamp(CassBatch* batch,
                         cass_int64_t timestamp);
# 4042 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_batch_set_retry_policy(CassBatch* batch,
                            CassRetryPolicy* retry_policy);
# 4055 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_batch_set_custom_payload(CassBatch* batch,
                              const CassCustomPayload* payload);
# 4068 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_batch_add_statement(CassBatch* batch,
                         CassStatement* statement);
# 4088 "cassandra.h"
__attribute__ ((visibility("default"))) CassDataType*
cass_data_type_new(CassValueType type);
# 4101 "cassandra.h"
__attribute__ ((visibility("default"))) CassDataType*
cass_data_type_new_from_existing(const CassDataType* data_type);
# 4114 "cassandra.h"
__attribute__ ((visibility("default"))) CassDataType*
cass_data_type_new_tuple(size_t item_count);
# 4127 "cassandra.h"
__attribute__ ((visibility("default"))) CassDataType*
cass_data_type_new_udt(size_t field_count);
# 4137 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_data_type_free(CassDataType* data_type);







__attribute__ ((visibility("default"))) CassValueType
cass_data_type_type(const CassDataType* data_type);
# 4159 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_type_name(const CassDataType* data_type,
                         const char** type_name,
                         size_t* type_name_length);
# 4173 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_set_type_name(CassDataType* data_type,
                             const char* type_name);
# 4188 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_set_type_name_n(CassDataType* data_type,
                               const char* type_name,
                               size_t type_name_length);
# 4203 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_keyspace(const CassDataType* data_type,
                        const char** keyspace,
                        size_t* keyspace_length);
# 4217 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_set_keyspace(CassDataType* data_type,
                            const char* keyspace);
# 4232 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_set_keyspace_n(CassDataType* data_type,
                              const char* keyspace,
                              size_t keyspace_length);
# 4247 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_class_name(CassDataType* data_type,
                          const char** class_name,
                          size_t* class_name_length);
# 4261 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_set_class_name(CassDataType* data_type,
                              const char* class_name);
# 4276 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_set_class_name_n(CassDataType* data_type,
                                const char* class_name,
                                size_t class_name_length);
# 4293 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_data_type_sub_data_type(const CassDataType* data_type,
                             size_t index);
# 4308 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_data_type_sub_data_type_by_name(const CassDataType* data_type,
                                     const char* name);
# 4325 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_data_type_sub_data_type_by_name_n(const CassDataType* data_type,
                                       const char* name,
                                       size_t name_length);
# 4341 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_sub_type_name(const CassDataType* data_type,
                             size_t index,
                             const char** name,
                             size_t* name_length);
# 4356 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_add_sub_type(CassDataType* data_type,
                            const CassDataType* sub_data_type);
# 4370 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_add_sub_type_by_name(CassDataType* data_type,
                                    const char* name,
                                    const CassDataType* sub_data_type);
# 4387 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_add_sub_type_by_name_n(CassDataType* data_type,
                                      const char* name,
                                      size_t name_length,
                                      const CassDataType* sub_data_type);
# 4402 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_add_sub_value_type(CassDataType* data_type,
                                  CassValueType sub_value_type);
# 4417 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_add_sub_value_type_by_name(CassDataType* data_type,
                                          const char* name,
                                          CassValueType sub_value_type);
# 4434 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_data_type_add_sub_value_type_by_name_n(CassDataType* data_type,
                                            const char* name,
                                            size_t name_length,
                                            CassValueType sub_value_type);
# 4457 "cassandra.h"
__attribute__ ((visibility("default"))) CassCollection*
cass_collection_new(CassCollectionType type,
                    size_t item_count);
# 4472 "cassandra.h"
__attribute__ ((visibility("default"))) CassCollection*
cass_collection_new_from_data_type(const CassDataType* data_type,
                                   size_t item_count);
# 4483 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_collection_free(CassCollection* collection);
# 4493 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_collection_data_type(const CassCollection* collection);
# 4505 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_int8(CassCollection* collection,
                            cass_int8_t value);
# 4518 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_int16(CassCollection* collection,
                             cass_int16_t value);
# 4531 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_int32(CassCollection* collection,
                             cass_int32_t value);
# 4544 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_uint32(CassCollection* collection,
                              cass_uint32_t value);
# 4559 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_int64(CassCollection* collection,
                             cass_int64_t value);
# 4572 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_float(CassCollection* collection,
                             cass_float_t value);
# 4585 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_double(CassCollection* collection,
                              cass_double_t value);
# 4598 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_bool(CassCollection* collection,
                            cass_bool_t value);
# 4612 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_string(CassCollection* collection,
                              const char* value);
# 4630 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_string_n(CassCollection* collection,
                                const char* value,
                                size_t value_length);
# 4646 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_bytes(CassCollection* collection,
                             const cass_byte_t* value,
                             size_t value_size);
# 4660 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_uuid(CassCollection* collection,
                            CassUuid value);
# 4673 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_inet(CassCollection* collection,
                            CassInet value);
# 4689 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_decimal(CassCollection* collection,
                               const cass_byte_t* varint,
                               size_t varint_size,
                               cass_int32_t scale);
# 4704 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_collection(CassCollection* collection,
                                  const CassCollection* value);
# 4717 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_tuple(CassCollection* collection,
                             const CassTuple* value);
# 4730 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_collection_append_user_type(CassCollection* collection,
                                 const CassUserType* value);
# 4750 "cassandra.h"
__attribute__ ((visibility("default"))) CassTuple*
cass_tuple_new(size_t item_count);
# 4763 "cassandra.h"
__attribute__ ((visibility("default"))) CassTuple*
cass_tuple_new_from_data_type(const CassDataType* data_type);
# 4773 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_tuple_free(CassTuple* tuple);
# 4783 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_tuple_data_type(const CassTuple* tuple);
# 4795 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_null(CassTuple* tuple, size_t index);
# 4808 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_int8(CassTuple* tuple,
                    size_t index,
                    cass_int8_t value);
# 4823 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_int16(CassTuple* tuple,
                     size_t index,
                     cass_int16_t value);
# 4838 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_int32(CassTuple* tuple,
                     size_t index,
                     cass_int32_t value);
# 4853 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_uint32(CassTuple* tuple,
                      size_t index,
                      cass_uint32_t value);
# 4869 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_int64(CassTuple* tuple,
                     size_t index,
                     cass_int64_t value);
# 4884 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_float(CassTuple* tuple,
                     size_t index,
                     cass_float_t value);
# 4899 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_double(CassTuple* tuple,
                      size_t index,
                      cass_double_t value);
# 4914 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_bool(CassTuple* tuple,
                    size_t index,
                    cass_bool_t value);
# 4930 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_string(CassTuple* tuple,
                      size_t index,
                      const char* value);
# 4949 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_string_n(CassTuple* tuple,
                        size_t index,
                        const char* value,
                        size_t value_length);
# 4967 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_bytes(CassTuple* tuple,
                     size_t index,
                     const cass_byte_t* value,
                     size_t value_size);
# 4983 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_uuid(CassTuple* tuple,
                    size_t index,
                    CassUuid value);
# 4998 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_inet(CassTuple* tuple,
                    size_t index,
                    CassInet value);
# 5016 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_decimal(CassTuple* tuple,
                       size_t index,
                       const cass_byte_t* varint,
                       size_t varint_size,
                       cass_int32_t scale);
# 5033 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_collection(CassTuple* tuple,
                          size_t index,
                          const CassCollection* value);
# 5048 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_tuple(CassTuple* tuple,
                     size_t index,
                     const CassTuple* value);
# 5063 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_tuple_set_user_type(CassTuple* tuple,
                         size_t index,
                         const CassUserType* value);
# 5085 "cassandra.h"
__attribute__ ((visibility("default"))) CassUserType*
cass_user_type_new_from_data_type(const CassDataType* data_type);
# 5095 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_user_type_free(CassUserType* user_type);
# 5106 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_user_type_data_type(const CassUserType* user_type);
# 5118 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_null(CassUserType* user_type,
                        size_t index);
# 5131 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_null_by_name(CassUserType* user_type,
                                const char* name);
# 5148 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_null_by_name_n(CassUserType* user_type,
                                   const char* name,
                                   size_t name_length);
# 5163 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_int8(CassUserType* user_type,
                        size_t index,
                        cass_int8_t value);
# 5178 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_int8_by_name(CassUserType* user_type,
                                const char* name,
                                cass_int8_t value);
# 5197 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_int8_by_name_n(CassUserType* user_type,
                                  const char* name,
                                  size_t name_length,
                                  cass_int8_t value);
# 5213 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_int16(CassUserType* user_type,
                         size_t index,
                         cass_int16_t value);
# 5228 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_int16_by_name(CassUserType* user_type,
                                 const char* name,
                                 cass_int16_t value);
# 5247 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_int16_by_name_n(CassUserType* user_type,
                                   const char* name,
                                   size_t name_length,
                                   cass_int16_t value);
# 5263 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_int32(CassUserType* user_type,
                         size_t index,
                         cass_int32_t value);
# 5278 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_int32_by_name(CassUserType* user_type,
                                 const char* name,
                                 cass_int32_t value);
# 5297 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_int32_by_name_n(CassUserType* user_type,
                                   const char* name,
                                   size_t name_length,
                                   cass_int32_t value);
# 5313 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_uint32(CassUserType* user_type,
                          size_t index,
                          cass_uint32_t value);
# 5328 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_uint32_by_name(CassUserType* user_type,
                                  const char* name,
                                  cass_uint32_t value);
# 5347 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_uint32_by_name_n(CassUserType* user_type,
                                    const char* name,
                                    size_t name_length,
                                    cass_uint32_t value);
# 5365 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_int64(CassUserType* user_type,
                         size_t index,
                         cass_int64_t value);
# 5381 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_int64_by_name(CassUserType* user_type,
                                 const char* name,
                                 cass_int64_t value);
# 5400 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_int64_by_name_n(CassUserType* user_type,
                                   const char* name,
                                   size_t name_length,
                                   cass_int64_t value);
# 5416 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_float(CassUserType* user_type,
                         size_t index,
                         cass_float_t value);
# 5431 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_float_by_name(CassUserType* user_type,
                                 const char* name,
                                 cass_float_t value);
# 5450 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_float_by_name_n(CassUserType* user_type,
                                   const char* name,
                                   size_t name_length,
                                   cass_float_t value);
# 5466 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_double(CassUserType* user_type,
                         size_t index,
                         cass_double_t value);
# 5481 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_double_by_name(CassUserType* user_type,
                                 const char* name,
                                 cass_double_t value);
# 5500 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_double_by_name_n(CassUserType* user_type,
                                   const char* name,
                                   size_t name_length,
                                   cass_double_t value);
# 5516 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_bool(CassUserType* user_type,
                         size_t index,
                         cass_bool_t value);
# 5531 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_bool_by_name(CassUserType* user_type,
                                 const char* name,
                                 cass_bool_t value);
# 5550 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_bool_by_name_n(CassUserType* user_type,
                                   const char* name,
                                   size_t name_length,
                                   cass_bool_t value);
# 5568 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_string(CassUserType* user_type,
                          size_t index,
                          const char* value);
# 5587 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_string_n(CassUserType* user_type,
                            size_t index,
                            const char* value,
                            size_t value_length);
# 5604 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_string_by_name(CassUserType* user_type,
                                 const char* name,
                                 const char* value);
# 5624 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_string_by_name_n(CassUserType* user_type,
                                   const char* name,
                                   size_t name_length,
                                   const char* value,
                                   size_t value_length);
# 5642 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_bytes(CassUserType* user_type,
                         size_t index,
                         const cass_byte_t* value,
                         size_t value_size);
# 5659 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_bytes_by_name(CassUserType* user_type,
                                 const char* name,
                                 const cass_byte_t* value,
                                 size_t value_size);
# 5680 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_bytes_by_name_n(CassUserType* user_type,
                                   const char* name,
                                   size_t name_length,
                                   const cass_byte_t* value,
                                   size_t value_size);
# 5697 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_uuid(CassUserType* user_type,
                         size_t index,
                         CassUuid value);
# 5712 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_uuid_by_name(CassUserType* user_type,
                                 const char* name,
                                 CassUuid value);
# 5731 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_uuid_by_name_n(CassUserType* user_type,
                                   const char* name,
                                   size_t name_length,
                                   CassUuid value);
# 5747 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_inet(CassUserType* user_type,
                         size_t index,
                         CassInet value);
# 5762 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_inet_by_name(CassUserType* user_type,
                                 const char* name,
                                 CassInet value);
# 5781 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_inet_by_name_n(CassUserType* user_type,
                                   const char* name,
                                   size_t name_length,
                                   CassInet value);
# 5799 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_decimal(CassUserType* user_type,
                           size_t index,
                           const cass_byte_t* varint,
                           size_t varint_size,
                           int scale);
# 5818 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_decimal_by_name(CassUserType* user_type,
                                   const char* name,
                                   const cass_byte_t* varint,
                                   size_t varint_size,
                                   int scale);
# 5841 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_decimal_by_name_n(CassUserType* user_type,
                                     const char* name,
                                     size_t name_length,
                                     const cass_byte_t* varint,
                                     size_t varint_size,
                                     int scale);
# 5860 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_collection(CassUserType* user_type,
                              size_t index,
                              const CassCollection* value);
# 5876 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_collection_by_name(CassUserType* user_type,
                                      const char* name,
                                      const CassCollection* value);
# 5895 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_collection_by_name_n(CassUserType* user_type,
                                        const char* name,
                                        size_t name_length,
                                        const CassCollection* value);
# 5911 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_tuple(CassUserType* user_type,
                              size_t index,
                              const CassTuple* value);
# 5926 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_tuple_by_name(CassUserType* user_type,
                                      const char* name,
                                      const CassTuple* value);
# 5945 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_tuple_by_name_n(CassUserType* user_type,
                                        const char* name,
                                        size_t name_length,
                                        const CassTuple* value);
# 5961 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_user_type(CassUserType* user_type,
                             size_t index,
                             const CassUserType* value);
# 5976 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_user_type_by_name(CassUserType* user_type,
                                     const char* name,
                                     const CassUserType* value);
# 5995 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_user_type_set_user_type_by_name_n(CassUserType* user_type,
                                       const char* name,
                                       size_t name_length,
                                       const CassUserType* value);
# 6017 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_result_free(const CassResult* result);
# 6028 "cassandra.h"
__attribute__ ((visibility("default"))) size_t
cass_result_row_count(const CassResult* result);
# 6039 "cassandra.h"
__attribute__ ((visibility("default"))) size_t
cass_result_column_count(const CassResult* result);
# 6053 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_result_column_name(const CassResult *result,
                        size_t index,
                        const char** name,
                        size_t* name_length);
# 6069 "cassandra.h"
__attribute__ ((visibility("default"))) CassValueType
cass_result_column_type(const CassResult* result,
                        size_t index);
# 6083 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_result_column_data_type(const CassResult* result, size_t index);
# 6094 "cassandra.h"
__attribute__ ((visibility("default"))) const CassRow*
cass_result_first_row(const CassResult* result);
# 6105 "cassandra.h"
__attribute__ ((visibility("default"))) cass_bool_t
cass_result_has_more_pages(const CassResult* result);
# 6126 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_result_paging_state_token(const CassResult* result,
                               const char** paging_state,
                               size_t* paging_state_size);
# 6144 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_error_result_free(const CassErrorResult* error_result);
# 6156 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_error_result_code(const CassErrorResult* error_result);
# 6178 "cassandra.h"
__attribute__ ((visibility("default"))) CassConsistency
cass_error_result_consistency(const CassErrorResult* error_result);
# 6200 "cassandra.h"
__attribute__ ((visibility("default"))) cass_int32_t
cass_error_result_responses_received(const CassErrorResult* error_result);
# 6223 "cassandra.h"
__attribute__ ((visibility("default"))) cass_int32_t
cass_error_result_responses_required(const CassErrorResult* error_result);
# 6239 "cassandra.h"
__attribute__ ((visibility("default"))) cass_int32_t
cass_error_result_num_failures(const CassErrorResult* error_result);
# 6257 "cassandra.h"
__attribute__ ((visibility("default"))) cass_bool_t
cass_error_result_data_present(const CassErrorResult* error_result);
# 6274 "cassandra.h"
__attribute__ ((visibility("default"))) CassWriteType
cass_error_result_write_type(const CassErrorResult* error_result);
# 6292 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_error_result_keyspace(const CassErrorResult* error_result,
                           const char** keyspace,
                           size_t* keyspace_length);
# 6308 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_error_result_table(const CassErrorResult* error_result,
                        const char** table,
                        size_t* table_length);
# 6324 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_error_result_function(const CassErrorResult* error_result,
                           const char** function,
                           size_t* function_length);
# 6338 "cassandra.h"
__attribute__ ((visibility("default"))) size_t
cass_error_num_arg_types(const CassErrorResult* error_result);
# 6353 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_error_result_arg_type(const CassErrorResult* error_result,
                           size_t index,
                           const char** arg_type,
                           size_t* arg_type_length);
# 6372 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_iterator_free(CassIterator* iterator);
# 6383 "cassandra.h"
__attribute__ ((visibility("default"))) CassIteratorType
cass_iterator_type(CassIterator* iterator);
# 6397 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_from_result(const CassResult* result);
# 6411 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_from_row(const CassRow* row);
# 6426 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_from_collection(const CassValue* value);
# 6441 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_from_map(const CassValue* value);
# 6456 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_from_tuple(const CassValue* value);
# 6471 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_fields_from_user_type(const CassValue* value);
# 6486 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_keyspaces_from_schema_meta(const CassSchemaMeta* schema_meta);
# 6501 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_tables_from_keyspace_meta(const CassKeyspaceMeta* keyspace_meta);
# 6516 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_user_types_from_keyspace_meta(const CassKeyspaceMeta* keyspace_meta);
# 6531 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_functions_from_keyspace_meta(const CassKeyspaceMeta* keyspace_meta);
# 6546 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_aggregates_from_keyspace_meta(const CassKeyspaceMeta* keyspace_meta);
# 6564 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_fields_from_keyspace_meta(const CassKeyspaceMeta* keyspace_meta);
# 6579 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_columns_from_table_meta(const CassTableMeta* table_meta);
# 6597 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_fields_from_table_meta(const CassTableMeta* table_meta);
# 6615 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_fields_from_column_meta(const CassColumnMeta* column_meta);
# 6632 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_fields_from_function_meta(const CassFunctionMeta* function_meta);
# 6649 "cassandra.h"
__attribute__ ((visibility("default"))) CassIterator*
cass_iterator_fields_from_aggregate_meta(const CassAggregateMeta* aggregate_meta);
# 6660 "cassandra.h"
__attribute__ ((visibility("default"))) cass_bool_t
cass_iterator_next(CassIterator* iterator);
# 6674 "cassandra.h"
__attribute__ ((visibility("default"))) const CassRow*
cass_iterator_get_row(const CassIterator* iterator);
# 6688 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_iterator_get_column(const CassIterator* iterator);
# 6702 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_iterator_get_value(const CassIterator* iterator);
# 6716 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_iterator_get_map_key(const CassIterator* iterator);
# 6731 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_iterator_get_map_value(const CassIterator* iterator);
# 6747 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_iterator_get_user_type_field_name(const CassIterator* iterator,
                                       const char** name,
                                       size_t* name_length);
# 6763 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_iterator_get_user_type_field_value(const CassIterator* iterator);
# 6777 "cassandra.h"
__attribute__ ((visibility("default"))) const CassKeyspaceMeta*
cass_iterator_get_keyspace_meta(const CassIterator* iterator);
# 6791 "cassandra.h"
__attribute__ ((visibility("default"))) const CassTableMeta*
cass_iterator_get_table_meta(const CassIterator* iterator);
# 6805 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_iterator_get_user_type(const CassIterator* iterator);
# 6819 "cassandra.h"
__attribute__ ((visibility("default"))) const CassFunctionMeta*
cass_iterator_get_function_meta(const CassIterator* iterator);
# 6833 "cassandra.h"
__attribute__ ((visibility("default"))) const CassAggregateMeta*
cass_iterator_get_aggregate_meta(const CassIterator* iterator);
# 6847 "cassandra.h"
__attribute__ ((visibility("default"))) const CassColumnMeta*
cass_iterator_get_column_meta(const CassIterator* iterator);
# 6863 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_iterator_get_meta_field_name(const CassIterator* iterator,
                                  const char** name,
                                  size_t* name_length);
# 6879 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_iterator_get_meta_field_value(const CassIterator* iterator);
# 6898 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_row_get_column(const CassRow* row,
                    size_t index);
# 6913 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_row_get_column_by_name(const CassRow* row,
                            const char* name);
# 6930 "cassandra.h"
__attribute__ ((visibility("default"))) const CassValue*
cass_row_get_column_by_name_n(const CassRow* row,
                              const char* name,
                              size_t name_length);
# 6950 "cassandra.h"
__attribute__ ((visibility("default"))) const CassDataType*
cass_value_data_type(const CassValue* value);
# 6962 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_value_get_int8(const CassValue* value,
                     cass_int8_t* output);
# 6975 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_value_get_int16(const CassValue* value,
                     cass_int16_t* output);
# 6988 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_value_get_int32(const CassValue* value,
                     cass_int32_t* output);
# 7001 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_value_get_uint32(const CassValue* value,
                      cass_uint32_t* output);
# 7014 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_value_get_int64(const CassValue* value,
                     cass_int64_t* output);
# 7027 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_value_get_float(const CassValue* value,
                     cass_float_t* output);
# 7040 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_value_get_double(const CassValue* value,
                      cass_double_t* output);
# 7053 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_value_get_bool(const CassValue* value,
                    cass_bool_t* output);
# 7066 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_value_get_uuid(const CassValue* value,
                    CassUuid* output);
# 7079 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_value_get_inet(const CassValue* value,
                    CassInet* output);
# 7093 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_value_get_string(const CassValue* value,
                      const char** output,
                      size_t* output_size);
# 7108 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_value_get_bytes(const CassValue* value,
                     const cass_byte_t** output,
                     size_t* output_size);
# 7124 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_value_get_decimal(const CassValue* value,
                       const cass_byte_t** varint,
                       size_t* varint_size,
                       cass_int32_t* scale);
# 7138 "cassandra.h"
__attribute__ ((visibility("default"))) CassValueType
cass_value_type(const CassValue* value);
# 7149 "cassandra.h"
__attribute__ ((visibility("default"))) cass_bool_t
cass_value_is_null(const CassValue* value);
# 7160 "cassandra.h"
__attribute__ ((visibility("default"))) cass_bool_t
cass_value_is_collection(const CassValue* value);
# 7171 "cassandra.h"
__attribute__ ((visibility("default"))) size_t
cass_value_item_count(const CassValue* collection);
# 7184 "cassandra.h"
__attribute__ ((visibility("default"))) CassValueType
cass_value_primary_sub_type(const CassValue* collection);
# 7197 "cassandra.h"
__attribute__ ((visibility("default"))) CassValueType
cass_value_secondary_sub_type(const CassValue* collection);
# 7223 "cassandra.h"
__attribute__ ((visibility("default"))) CassUuidGen*
cass_uuid_gen_new();
# 7238 "cassandra.h"
__attribute__ ((visibility("default"))) CassUuidGen*
cass_uuid_gen_new_with_node(cass_uint64_t node);
# 7248 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_uuid_gen_free(CassUuidGen* uuid_gen);
# 7261 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_uuid_gen_time(CassUuidGen* uuid_gen,
                   CassUuid* output);
# 7275 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_uuid_gen_random(CassUuidGen* uuid_gen,
                     CassUuid* output);
# 7290 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_uuid_gen_from_time(CassUuidGen* uuid_gen,
                        cass_uint64_t timestamp,
                        CassUuid* output);
# 7303 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_uuid_min_from_time(cass_uint64_t time,
                        CassUuid* output);
# 7315 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_uuid_max_from_time(cass_uint64_t time,
                        CassUuid* output);
# 7329 "cassandra.h"
__attribute__ ((visibility("default"))) cass_uint64_t
cass_uuid_timestamp(CassUuid uuid);
# 7340 "cassandra.h"
__attribute__ ((visibility("default"))) cass_uint8_t
cass_uuid_version(CassUuid uuid);
# 7351 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_uuid_string(CassUuid uuid,
                 char* output);
# 7365 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_uuid_from_string(const char* str,
                      CassUuid* output);
# 7382 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_uuid_from_string_n(const char* str,
                        size_t str_length,
                        CassUuid* output);
# 7405 "cassandra.h"
__attribute__ ((visibility("default"))) CassTimestampGen*
cass_timestamp_gen_server_side_new();
# 7424 "cassandra.h"
__attribute__ ((visibility("default"))) CassTimestampGen*
cass_timestamp_gen_monotonic_new();
# 7434 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_timestamp_gen_free(CassTimestampGen* timestamp_gen);
# 7464 "cassandra.h"
__attribute__ ((visibility("default"))) CassRetryPolicy*
cass_retry_policy_default_new();
# 7498 "cassandra.h"
__attribute__ ((visibility("default"))) CassRetryPolicy*
cass_retry_policy_downgrading_consistency_new();
# 7513 "cassandra.h"
__attribute__ ((visibility("default"))) CassRetryPolicy*
cass_retry_policy_fallthrough_new();
# 7530 "cassandra.h"
__attribute__ ((visibility("default"))) CassRetryPolicy*
cass_retry_policy_logging_new(CassRetryPolicy* child_retry_policy);
# 7540 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_retry_policy_free(CassRetryPolicy* policy);
# 7558 "cassandra.h"
__attribute__ ((visibility("default"))) CassCustomPayload*
cass_custom_payload_new();
# 7568 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_custom_payload_free(CassCustomPayload* payload);
# 7581 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_custom_payload_set(CassCustomPayload* payload,
                        const char* name,
                        const cass_byte_t* value,
                        size_t value_size);
# 7599 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_custom_payload_set_n(CassCustomPayload* payload,
                          const char* name,
                          size_t name_length,
                          const cass_byte_t* value,
                          size_t value_size);
# 7619 "cassandra.h"
__attribute__ ((visibility("default"))) const char*
cass_consistency_string(CassConsistency consistency);
# 7634 "cassandra.h"
__attribute__ ((visibility("default"))) const char*
cass_write_type_string(CassWriteType write_type);
# 7649 "cassandra.h"
__attribute__ ((visibility("default"))) const char*
cass_error_desc(CassError error);
# 7666 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_log_cleanup() __attribute__((deprecated));
# 7679 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_log_set_level(CassLogLevel log_level);
# 7694 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_log_set_callback(CassLogCallback callback,
                      void* data);
# 7711 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_log_set_queue_size(size_t queue_size) __attribute__((deprecated));
# 7721 "cassandra.h"
__attribute__ ((visibility("default"))) const char*
cass_log_level_string(CassLogLevel log_level);
# 7738 "cassandra.h"
__attribute__ ((visibility("default"))) CassInet
cass_inet_init_v4(const cass_uint8_t* address);
# 7749 "cassandra.h"
__attribute__ ((visibility("default"))) CassInet
cass_inet_init_v6(const cass_uint8_t* address);
# 7760 "cassandra.h"
__attribute__ ((visibility("default"))) void
cass_inet_string(CassInet inet,
                 char* output);
# 7774 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_inet_from_string(const char* str,
                      CassInet* output);
# 7791 "cassandra.h"
__attribute__ ((visibility("default"))) CassError
cass_inet_from_string_n(const char* str,
                        size_t str_length,
                        CassInet* output);
# 7810 "cassandra.h"
__attribute__ ((visibility("default"))) cass_uint32_t
cass_date_from_epoch(cass_int64_t epoch_secs);
# 7820 "cassandra.h"
__attribute__ ((visibility("default"))) cass_int64_t
cass_time_from_epoch(cass_int64_t epoch_secs);
# 7831 "cassandra.h"
__attribute__ ((visibility("default"))) cass_int64_t
cass_date_time_to_epoch(cass_uint32_t date,
                        cass_int64_t time);
