#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "args.h"

typedef enum {
    SIGN_ERR = -1,
    SIGN_CHAR = 0,
    SIGN_SHORT,
    SIGN_INT,
    SIGN_UINT,
    SIGN_LONG,
    SIGN_STRING,
} sign_type;

static sign_type get_sign_type(const char *sign) {

    sign_type signt = SIGN_ERR;

    if(!strcmp(sign, "%c")) {
        signt = SIGN_CHAR;
    } else if(!strcmp(sign, "%d")) {
        signt = SIGN_INT;
    } else if(!strcmp(sign, "%u")) {
        signt = SIGN_UINT;
    } else if(!strcmp(sign, "%s")) {
        signt = SIGN_STRING;
    }

    return signt;
}



int argparse_init(args_opt *ctx, int argc, char **argv) {

    int sign = !ctx ? -1 : 0;

    if(sign == 0) {
        ctx->argv = argv;
        ctx->argc = argc;
    }

    return sign;
}

int args_get_elem(args_opt *ctx, const char *param, const char *sign, void *value) {

    sign_type signt;

    for(int i = 0; i < ctx->argc; ++i) {
        if(!strcmp(ctx->argv[i], param)) {
            signt = get_sign_type(sign);
            switch(signt) {
                case SIGN_ERR:
                    break;
                case SIGN_CHAR:
                    *((char *)value) = ctx->argv[i+1][0];
                    return 0;
                case SIGN_INT:
                    *((int *)value) = atoi(ctx->argv[i+1]);
                    return 0;
                case SIGN_STRING:
                    strcpy((char *)value, ctx->argv[i+1]);
                    return 0;
                default:
                    break;
            }
        }
    }
    return -1;
}
