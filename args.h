#ifndef __ARGS_H
#define __ARGS_H

typedef struct args_t {
    int  argc;
    char **argv;
} args_opt;

static sign_type get_sign_type(const char *);


int argparse_init(args_opt*, int, char**);


int args_get_elem(args_opt*, const char *, const char*, void*);

#endif
