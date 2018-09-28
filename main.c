/*
 *  monsherko && ashpooljh
 *
 */

//gcc main.c args.c  pool.c -o test/args_2 -pthread

#include <stdio.h>

#include <pthread.h>
#include <string.h>
#include "args.h"
#include "pool.h"


static char const usage[] = "";


static char const help_str[] =""


pool_opt* init_pool_opt_default();

pool_opt* init_pool_opt_conf(uint8_t, uint8_t, uint8_t,char*,char*,char*);


/*
    Thoughts about overloading of functions(Unfinished version)
*/

#define init_pool_opt(...) OVERLOAD(init_pool_opt, (__VA_ARGS__), \
    (init_pool_opt_default, (void)), \
    (init_pool_opt_conf, (uint8_t, uint8_t, uint8_t, char*, char*, char*)), \
)

void args_parse_config(char* path_f, pool_opt* val) {

}

static algm_type get_algm_type(const char* algm) {

    algm_type signt = ALGM_ERROR;

    if(!strcmp(algm, "lyra2v2")) {
        signt = LYRA2V2;
    } else if(!strcmp(algm, "lyra2z")) {
        signt = LYRA2Z;
    }

    return signt;
}



int main(int argc, char **argv)
{

    args_opt  ctx;
    pool_opt* val = init_pool_opt_default();


    if(argc < 2) {
      fprintf(stderr, "%s\n", str_help);
      return -1;
    }

    argparse_init(&ctx, argc, argv);

    if(!strcmp(argv[1],"--help")) {
      fprintf(stderr, "%s\n", usage);
      return -1;
    }

    if((args_get_elem(&ctx, "--config", "%s", (void*) val->addr)) > 0) {
    // parse config file
    //args_parse_config("", void);
    } else if((args_get_elem(&ctx, "--url", "%s", (void *)val->addr) < 0) ||
              (args_get_elem(&ctx, "--user", "%s", (void *)val->user) < 0) ||
              (args_get_elem(&ctx, "--password", "%s", (void *)val->pass) < 0))
    {
        fprintf(stderr, "%s\n", str_help);
        return -1;
    }

//    if(args_get_elem(&ctx, "--algorithm", "%s", (void *)alg) < 0) {
//        return -1;
//    }

    fprintf(stderr, "get param url:%s user:%s password:%s\n",val->addr,val->user, val->pass);

    if (pthread_mutex_init(val->sock_lock, NULL) != 0) {
//    error init pthread
      return -1;
    }

//  if (option_fast_cool)
//     pthread_mutex_init(...)
//  else
//    fprintf(stderr, "fast cool is disabled, please sledite za T vashih ystroustv")''
//  init_opt_settings()

//  for(pool_opt* beg = begin; beg != NULL; beg = beg->next) {
/*        switch beg->sign: {
        case LYRA2V2:
        //function for mining vtc
        // get_block()?  send_block()?
    }
 */
    return 0;
}
