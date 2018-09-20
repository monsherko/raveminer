#include "utils.h"

uint8_t stratum_connect(pool_opt* v, const char* url) {

    CURL* curl;
/*
    1. thread lock
    2. init curl params
    3. return 0
    -1. return -1 (if error)
*/
    pthread_mutex_lock(v->sock_lock);
    if (v->curl) {
        curl_easy_cleanup(v->curl);
    }

    v->curl = curl_easy_init();

    if (!v->curl) {
      return -1;
    }

    curl = v->curl;

}
