#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct {
    int* head;
    int* avail;
    int* tail;
} vector;

/**
 * Initializes an empty vector within the vector* passed.
 *
 * Note that this data structure is completely empty, and has
 * nothing allocated; not necessary to call vector_free on this
 */
void vector_init(vector* v);

/**
 * Initializes an empty vector with the size passed.
 * Memory will be allocated under the size given, so vector_free
 * is required
 */
void vector_init_size(vector* v, size_t s);

/**
 * Pushes a new element onto the vector.
 */
void vector_push_back(vector* v, int e);

/**
 * Returns the current size of the vector.
 */
size_t vector_size(vector* v);

/**
 * Returns the current total capacity of the vector,
 * which encompasses the total amount allocated.
 */
size_t vector_capacity(vector* v);

/**
 * Frees the resources allocated to the vector.
 * The vector is also cleared.
 */
void vector_free(vector* v);


/**
 * Grows the vector by 2x, or 1 if empty.
 */
static void vector_grow(vector* v);

#endif
