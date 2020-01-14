#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
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
 * is required \
 */ \
void vector_init_size_##vector_type(vector_##vector_type* v, size_t s); \
\
/** \
 * Pushes a new element onto the vector. \
 */ \
void vector_push_back_##vector_type(vector_##vector_type* v, vector_type e); \
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
 * Frees the resources allocated to the vector. \
 * The vector is also cleared. \
 */ \
void vector_free_##vector_type(vector_##vector_type* v); \
\
/** \
 * Grows the vector by 2x, or 1 if empty. \
 */ \
static void vector_grow_##vector_type(vector_##vector_type* v); \

#endif
