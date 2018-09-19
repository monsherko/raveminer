#include "pool.hpp"

pool_opt* init_pool_opt_default() {
    pool_opt* val = (pool_opt*) calloc(1, sizeof(pool_opt));
    val->next = NULL;
    val->status = 0;
    val->id = 0;
    val->type = 0;
//  lol, memsetim vse chto ne nado, and all chto nado
// but this ne tochno
    memset(val->addr, 0, BASIC_SIZE_URL);
    memset(val->user, 0, BASIC_SIZE_STR);
    memset(val->pass, 0, BASIC_SIZE_STR);
    return val;
}

pool_opt* init_pool_opt_conf(uint8_t status, uint8_t id, uint8_t type, char* addr, char* user, char* pass, curl_session* tmp) {
  pool_opt* val = (pool_opt*) calloc(1, sizeof(pool_opt));
  val->next = NULL;
  val->status = status;
  val->id = id;
  val->type = type;
//  lol, memsetim vse chto ne nado, and all chto nado
// but this ne tochno

  memcpy(val->addr, addr, BASIC_SIZE_URL);
  memcpy(val->user, user, BASIC_SIZE_STR);
  memcpy(val->pass, pass, BASIC_SIZE_STR);
  return val;
}
