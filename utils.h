#ifndef __UTILS_H__
#define __UTILS_H__

#define CONST_BUFFER_SIZE 128

typedef struct data_buffer {
    void		*buf;
    size_t		len;
} data_buff;

typedef struct upload_buffer {
    const void	*buf;
    size_t		len;
    size_t		pos;
} upload_buff;

typedef struct header_info {
    char		*lp_path;
    char		*reason;
    char		*stratum_url;
} header_data;

typedef struct tq_ent {
    void			*data;
    struct list_head	q_node;
} tq_t;

typedef struct thread_q {
    struct list_head	q;

    bool frozen;

    pthread_mutex_t		mutex;
    pthread_cond_t		cond;
} thr_q;

static void databuf_free(struct data_buffer*);


enum arr_error {
  CURL_INIT = 0,
  CURL_SOCK_BUF
} curl_err;

uint8_t stratum_connect(pool_opt*, const char*);

#endif
