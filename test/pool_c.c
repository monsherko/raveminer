#include <curl/curl.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
/*
        list pools;
*/

#define BASIC_SIZE_STR 128
#define BASIC_SIZE_URL 256

typedef enum algorithm_t {
    ALGM_ERROR = -1,
    LYRA2V2 = 0,
    LYRA2Z
} algm_type;

typedef struct Curl_session {

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

static curl_socket_t opensocket_grab_cb(void *clientp, curlsocktype purpose,
	struct curl_sockaddr *addr)
{
	curl_socket_t *sock = (curl_socket_t*) clientp;
	*sock = socket(addr->family, addr->socktype, addr->protocol);
	return *sock;
}

uint8_t stratum_connect(pool_opt* v, const char* url) {
    CURL *curl;
  	int rc;

//  	pthread_mutex_lock(&v->sock_lock);
  	if (v->val.curl)
  		curl_easy_cleanup(v->val.curl);
  	v->val.curl = curl_easy_init();
  	if (!v->val.curl) {
  //		pthread_mutex_unlock(&v->sock_lock);
  		return 0;
  	}
  	curl = v->val.curl;
  	if (!v->val.sockbuf) {
  		v->val.sockbuf = (char*) calloc(64, 1);
  		v->val.sock_buf_size = 64;
  	}
    v->val.sockbuf[0] = '\0';
//    pthread_mutex_unlock(&v->sock_lock);

      free(v->val.curl_url);
      v->val.curl_url = (char*) malloc(strlen(url));
      sprintf(v->val.curl_url, "http%s", strstr(url, "://"));


    	curl_easy_setopt(curl, CURLOPT_URL, v->val.curl_url);
    	curl_easy_setopt(curl, CURLOPT_FRESH_CONNECT, 1);
    	curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 30);
    	curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
    	curl_easy_setopt(curl, CURLOPT_TCP_NODELAY, 1);
    	curl_easy_setopt(curl, CURLOPT_HTTPPROXYTUNNEL, 1);

    #if LIBCURL_VERSION_NUM >= 0x071101
    	curl_easy_setopt(curl, CURLOPT_OPENSOCKETFUNCTION, opensocket_grab_cb);
    	curl_easy_setopt(curl, CURLOPT_OPENSOCKETDATA, &v->val.sock);
    #endif
    	curl_easy_setopt(curl, CURLOPT_CONNECT_ONLY, 1);

    	rc = curl_easy_perform(curl);
    	if (rc) {
    		curl_easy_cleanup(curl);
    		v->val.curl = NULL;
    		return 0;
    	}

    #if LIBCURL_VERSION_NUM < 0x071101
    	/* CURLINFO_LASTSOCKET is broken on Win64; only use it as a last resort */
    	curl_easy_getinfo(curl, CURLINFO_LASTSOCKET, (long *)&v->val.sock);
    #endif

    	return 1;
}

int main() {
    pool_opt* conn = calloc(1,sizeof(struct pool_option));
    strcpy(conn->user, "VxXUmkcdTSGggmEWs7b5YpCyUdCQjp1ecM");
    const char ss[] = "stratum+tcp://p2pool.e-pool.net:5865";
    printf("%d\n", stratum_connect(conn,ss ));
}
