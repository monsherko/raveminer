#include <stdio.h>

#include "../args.h"
#include "../pool.h"

pool_opt* init_pool_opt_default();

int main(int argc, char **argv)
{
    args_opt ctx;
    pool_opt* val = init_pool_opt_default();


    argparse_init(&ctx, argc, argv);

    if(args_get_elem(&ctx, "--url", "%s", (void *)val->addr) < 0) {
        return -1;
    }


    if(args_get_elem(&ctx, "--user", "%s", (void *)val->user) < 0) {
        return -1;
    }

    if(args_get_elem(&ctx, "--password", "%s", (void *)val->pass) < 0) {
        return -1;
    }


    fprintf(stderr, "get param url:%s user:%s password:%s\n",val->addr,val->user, val->pass);

    return 0;
}
