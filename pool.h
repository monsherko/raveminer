#ifndef __POOL_H__
#define __POOL_H__


#include <curl/curl.h>
#include <stdint.h>
/*
        list pools;
*/

#define BASIC_SIZE_STR 32
#define BASIC_SIZE_URL 256

typedef enum algorithm_t {
    ALGM_ERROR = -1,
    LYRA2V2 = 0,
    LYRA2Z
} algm_type;

typedef struct session_ctx {
    CURL *curl;
    char *curl_url;
    char *sockbuf;
    curl_socket_t sock;
    size_t sock_buf_size;
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

    algm_type sign;

    curl_session val;
    pthread_mutex_t sock_lock;

} pool_opt;



//initialization basic pool option
pool_opt* init_pool_opt_default();
//initialization with params
pool_opt* init_pool_opt_conf(uint8_t, uint8_t, uint8_t,char*,char*,char*);

//insert
void pool_insert(pool_opt*, pool_opt*);
//delete
void pool_delete(pool_opt*);
//set option
void set_pool_opt(pool_opt*);
//create connection


#endif /* __MINER_H__ */
