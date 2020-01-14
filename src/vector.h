#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct {
    void* head;
    void* avail;
    void* tail;
    size_t type_size;
} vector;

/**
 * Initializes an empty vector within the vector* passed.
 *
 * Note that this data structure is completely empty, and has
 * nothing allocated; not necessary to call vector_free on this
 *
 * Second parameter refers to type size (e.g. typeof(int))
 */
void vector_init(vector* v, size_t t_sz);

/**
 * Initializes an empty vector with the size passed.
 * Memory will be allocated under the size given, so vector_free
 * is required.
 *
 * The second param (t_sz) is the type size, and the third
 * refers to the number of elements to initialize the vector with.
 */
void vector_init_size(vector* v, size_t t_sz, size_t n);

/**
 * Pushes a new element onto the vector.
 */
void vector_push_back(vector* v, const void* e);

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
