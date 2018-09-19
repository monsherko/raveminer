/*
 *  monsherko && ashpooljh
 *
 */

#include <iostream>
#include <curl.h>
#include "pool.hpp"


pool_opt* init_pool_opt_default();
pool_opt* init_pool_opt_conf(uint8_t, uint8_t, uint8_t, char*, char*, char*, curl_session*);

/*
    Thoughts about overloading of functions(Unfinished version)
*/

#define init_pool_opt(...) OVERLOAD(init_pool_opt, (__VA_ARGS__), \
    (init_pool_opt_default, (void)), \
    (init_pool_opt_conf, (uint8_t, uint8_t, uint8_t, char*, char*, char*, curl_session*)), \
)

int main(int argc, char **argv)
{

  std::cout << "was being developed..." << std::endl;

  return 0;

}
