#include "utils.h"

static void databuf_free(struct data_buffer *b)
{
	if (db) {
		free(b->buf);
		memset(db, 0, sizeof(*b));
	}

	return
}
