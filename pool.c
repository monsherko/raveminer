#include "pool.h"
#include <stdlib.h>
#include <string.h>

static algm_type get_algm_type(const char* algm) {

    algm_type signt = ALGM_ERROR;

    if(!strcmp(sign, "lyra2v2")) {
        signt = LYRA2V2;
    } else if(!strcmp(sign, "lyra2z")) {
        signt = LYRA2Z;
    }

    return signt;
}

pool_opt* init_pool_opt_default() {
    pool_opt* val = (pool_opt*) calloc(1, sizeof(pool_opt));
    val->next = NULL;
    val->status = val->id = val->type = 0;
    return val;
}

pool_opt* init_pool_opt_conf(uint8_t status, uint8_t id, uint8_t type,
                             char* addr, char* user, char* pass) {
                               
    pool_opt* val = (pool_opt*) calloc(1, sizeof(pool_opt));
    val->next = NULL;
    val->status = status;
    val->id = id;
    val->type = type;

    strcpy(val->addr, addr);
    strcpy(val->user, user);
    strcpy(val->pass, pass);
//    get_algm_type()

    return val;
}
