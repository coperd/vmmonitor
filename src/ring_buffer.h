#ifndef __RING_BUFFER_H
#define __RING_BUFFER_H

#include <stdlib.h>
#include "monitor.h"

/* 
 * change "double" to the corresponding data type you want, elemtype is used as
 * the common data type represented for a specific data type such as double. We
 * do the alias to make the API versatile.
 */
typedef struct mach_load elemtype;

/*
 * This is my version of ring buffer implementation
 * @buff: the buffer area used to store the data
 * @size: indicate the buffer area size
 * @start: the current start position of buff where the read starts
 * @end: the current end positon of buff where the write starts
 *
 * An extra opening slot is added to distinguish the ring buffer is full or 
 * empty
 */
struct ring_buffer 
{
    elemtype *buff;
    int size;
    int start;
    int end;
};

void rb_init(struct ring_buffer *rb, int size)
{
    rb->size = size + 1;
    rb->start = 0;
    rb->end = 0;
    rb->buff = (elemtype *)malloc(sizeof(elemtype) * rb->size);
}

void rb_free(struct ring_buffer *rb)
{
    /* if rb->buff == NULL, nothing happens */
    free(rb->buff);
}

int rb_is_full(struct ring_buffer *rb)
{
    return (rb->end + 1) % rb->size == rb->start;
}

int rb_is_empty(struct ring_buffer *rb)
{
    return rb->end == rb->start;
}

/* 
 * by default, if ring buffer is full overwrite would happen caller can call 
 * rb_is_full() to avoid overwrite
 */
void rb_write(struct ring_buffer *rb, elemtype *val)
{
    rb->buff[rb->end] = *val;
    rb->end = (rb->end + 1) % rb->size;
    if (rb->end == rb->start)
        /* overwrite */
        rb->start = (rb->start + 1) % rb->size;
}

/*
 * before calling rb_read, caller should ensure !rb_is_empty() first 
 */
void rb_read(struct ring_buffer *rb, elemtype *val)
{
    *val = rb->buff[rb->start];
    rb->start = (rb->start + 1) % rb->size;
}

/*
 * read the second to last value from the buffer
 * NO changes in the start/end position
 */
void rb_read_last(struct ring_buffer *rb, elemtype *val)
{
    int last_val_pos = (rb->end - 1 + rb->size) % rb->size;
    *val = rb->buff[last_val_pos];
}

#endif
