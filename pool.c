#include "pool.h"
#include <stdlib.h>
#include <string.h>


pool_opt* init_pool_opt_default() {

    pool_opt* val   = (pool_opt*) calloc(1, sizeof(pool_opt));
    val->next       = NULL;
    val->status     = 0;
    val->id         = 0;
    val->type       = 0;

    return val;
}

pool_opt* init_pool_opt_conf(uint8_t status, uint8_t id, uint8_t type,
                             char* addr, char* user, char* pass) {

    pool_opt* val  = (pool_opt*) calloc(1, sizeof(pool_opt));
    val->next      = NULL;
    val->status    = status;
    val->id        = id;
    val->type      = type;

    strcpy(val->addr, addr);
    strcpy(val->user, user);
    strcpy(val->pass, pass);

    return val;
}

void pool_insert(pool_opt* val, pool_opt* next) {
    next        = val->next;
    next->next  = NULL;
}

void pool_delete(pool_opt* val) {
    if (val->next) {
        pool_opt* tmp = val;
        val = val->next;
    }

    free(val);
}
