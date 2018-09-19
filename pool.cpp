#include "pool.hpp"

pool_opt* init_pool_opt_default() {
    pool_opt* val = (pool_opt*) calloc(1, sizeof(pool_opt));
    val->next = NULL;
    val->status = 0;
    val->id = 0;
    val->type = 0;
    memset(val->addr, 0, BASIC_SIZE_URL);
    memset(val->user, 0, BASIC_SIZE_STR);
    memset(val->pass, 0, BASIC_SIZE_STR);
    return val;
}
