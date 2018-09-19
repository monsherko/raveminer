#ifndef __MINER_H__
#define __MINER_H__



/*
    list pools;
*/

#define BASIC_SIZE_STR 32
#define BASIC_SIZE_URL 256

typedef struct Curl_session {
  CURL *curl;
  char *sockbuf;
  curl_socket_t sock;
  size_t sockbuf_size;
  uint8_t type_error;
} curl_session;

typedef struct pool_option {
  struct pool_option* next;
/*
    pool identificator
*/
  uint8_t status;
  uint8_t id;
  uint8_t type;
/*
    basic info
*/
  char addr[BASIC_SIZE_URL];
  char user[BASIC_SIZE_STR];
  char pass[BASIC_SIZE_STR];

  curl_session val;

} pool_opt;
/*
    basic operation with array
*/

//initialization basic pool option
pool_opt* init_pool_opt_default();
//initialization with params
pool_opt* init_pool_opt_conf(uint8_t, uint8_t, uint8_t, char*, char*, char*, curl_session*);

//insert
void pool_insert(pool_opt*, pool_opt*);
//delete
void pool_del(pool_opt*);
//set option
void set_pool_opt(pool_opt*);

#define init_pool_opt(...) OVERLOAD(init_pool_opt, (__VA_ARGS__), \
    (init_pool_opt_default, (void)), \
    (init_pool_opt_conf, (uint8_t, uint8_t, uint8_t, char*, char*, char*, curl_session*)), \

)

#endif /* __MINER_H__ */
