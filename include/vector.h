#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include "algorithm.h"

/**
 * MACRO: declare_vector(vector_type)
 *
 * Declares an entire set of vector declarations for a specific type.
 *
 * Ex: declare_vector(int)
 *
 * Whenever a vector is needed to be declared, this is probably what you want!
 **/
#define declare_vector(vector_type) \
    \
typedef struct { \
    vector_type* head; \
    vector_type* avail; \
    vector_type* tail; \
} vector_##vector_type; \
\
/** \
 * Initializes an empty vector within the vector* passed. \
 * \
 * Note that this data structure is completely empty, and has \
 * nothing allocated; not necessary to call vector_free on this \
 */ \
void vector_init_##vector_type(vector_##vector_type* v); \
/** \
 * Initializes an empty vector with the size passed. \
 * Memory will be allocated under the size given, so vector_free \
 * is required. \
 */ \
void vector_init_size_##vector_type(vector_##vector_type* v, size_t s); \
\
/** \
 * Intiailizes an empty vector with the size passed. \
 * Unlike vector_init_size, this function will fill the capacity. \
 */ \
void vector_init_capacity_##vector_type(vector_##vector_type* v, size_t s); \
\
/** \
 * Pushes a new element onto the vector. \
 */ \
void vector_push_back_##vector_type(vector_##vector_type* v, vector_type e); \
\
/** \
 * Returns the first pointer in the vector's sequence. \
 */ \
vector_type* vector_begin_##vector_type(vector_##vector_type* v); \
\
/** \
 * Returns the last pointer in the vector's sequence. \
 */ \
vector_type* vector_end_##vector_type(vector_##vector_type* v); \
\
/** \
 * Returns the current size of the vector. \
 */ \
size_t vector_size_##vector_type(vector_##vector_type* v); \
\
/** \
 * Returns the current total capacity of the vector, \
 * which encompasses the total amount allocated. \
 */ \
size_t vector_capacity_##vector_type(vector_##vector_type* v); \
\
/** \
 * Returns the element found at the specified location passed. \
 */ \
vector_type vector_at_##vector_type(vector_##vector_type* v, size_t n); \
\
/** \
 * Frees the resources allocated to the vector. \
 * The vector is also cleared. \
 */ \
void vector_free_##vector_type(vector_##vector_type* v); \
\
/** \
 * Grows the vector by 2x, or 1 if empty. \
 */ \
static void vector_grow_##vector_type(vector_##vector_type* v); \



/**
 * MACRO: define_vector(vector_type)
 *
 * Generates an entire set of definitions for a specific vector type.
 *
 * Ex: define_vector(int)
 */
#define define_vector(vector_type) \
void vector_init_##vector_type(vector_##vector_type* v) { \
    *v = (vector_##vector_type) { NULL, NULL, NULL }; \
} \
\
void vector_init_size_##vector_type(vector_##vector_type* v, size_t s) { \
    v->head = (vector_type*) malloc(sizeof(vector_type) * s); \
    v->tail = v->avail = v->head + s; \
} \
\
void vector_init_capacity_##vector_type(vector_##vector_type* v, size_t s) { \
    v->head = v->avail = (vector_type*) malloc(sizeof(vector_type) * s); \
    v->tail = v->head + s; \
} \
\
void vector_push_back_##vector_type(vector_##vector_type* v, vector_type e) { \
    if(v->avail == v->tail) { \
        vector_grow_##vector_type(v); \
    } \
    *(v->avail++) = e; \
} \
\
vector_type* vector_begin_##vector_type(vector_##vector_type* v) { \
    return v->head; \
} \
\
vector_type* vector_end_##vector_type(vector_##vector_type* v) { \
    return v->avail; \
} \
\
void vector_grow_##vector_type(vector_##vector_type* v) { \
    size_t old_size = vector_size_##vector_type(v); \
    size_t n_size = v->head ? old_size * 2 : 1; \
\
    vector_type* n_head = (vector_type*) malloc(sizeof(vector_type) * n_size); \
\
    algorithm_copy(vector_type*, v->head, v->avail, n_head); \
\
    free(v->head); \
    v->head = n_head; \
    v->avail = n_head + old_size; \
    v->tail = n_head + n_size; \
} \
\
size_t vector_size_##vector_type(vector_##vector_type* v) { \
    return v->avail - v->head; \
} \
\
size_t vector_capacity_##vector_type(vector_##vector_type* v) { \
    return v->tail - v->head; \
} \
\
vector_type vector_at_##vector_type(vector_##vector_type* v, size_t n) { \
    return *(v->head + n); \
} \
\
void vector_free_##vector_type(vector_##vector_type* v) { \
    free(v->head); \
    v->head = v->avail = v->tail = NULL; \
} 


#endif