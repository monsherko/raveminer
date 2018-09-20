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

pool_opt* init_pool_opt_default();

/*
    Thoughts about overloading of functions(Unfinished version)
*/
/*
#define init_pool_opt(...) OVERLOAD(init_pool_opt, (__VA_ARGS__), \
    (init_pool_opt_default, (void)), \
    (init_pool_opt_conf, (uint8_t, uint8_t, uint8_t, char*, char*, char*)), \
)
*/

static char const usage[] = "\
Usage: ./raveminer [OPTIONS]\n\
Options:\n\
  --url     addr of mining server \n\
  --algorithm  specify the hash algorithm to use\n\
      lyra2v2 vtc(vertcoin)\n\
  --user user profile\n\
  --password password\n\
  --version  version information\n\
  --help this help text\n";

static char const str_help[] ="\
Use flag --help, for more details\n\
./raveminer --help\n";

int main(int argc, char **argv)
{

    char str_args_h;
    args_opt ctx;
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

    if((args_get_elem(&ctx, "--url", "%s", (void *)val->addr) < 0) || (args_get_elem(&ctx, "--user", "%s", (void *)val->user) < 0)
                                                                   || (args_get_elem(&ctx, "--password", "%s", (void *)val->pass) < 0)) {
        fprintf(stderr, "%s\n", str_help);
        return -1;
    }

//    if(args_get_elem(&ctx, "--algorithm", "%s", (void *)alg) < 0) {
//        return -1;
//    }





    fprintf(stderr, "get param url:%s user:%s password:%s\n",val->addr,val->user, val->pass);

//    pthread_mutex_init(val->sock_lock, NULL);

//  if (option_fast_cool)
//     pthread_mutex_init(...)
//  else
//    fprintf(stderr, "fast cool is disabled, please sledite za T vashih ystroustv")''
//  init_opt_settings()




    return 0;
}
