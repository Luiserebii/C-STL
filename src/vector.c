#include <stdlib.h>
#include <stdio.h>

#include "vector.h"
#include "algorithm.h"

declare_vector(int)

#define define_vector(vector_type) \
void vector_init_##vector_type(vector_##vector_type* v) { \
    *v = (vector_##vector_type) { NULL, NULL, NULL }; \
} \
\
void vector_init_size_##vector_type(vector_##vector_type* v, size_t s) { \
    v->head = v->avail = (vector_type*) malloc(sizeof(vector_type) * s); \
    v->tail = v->head + s; \
} \
\
void vector_push_back_##vector_type(vector_##vector_type* v, vector_type e) { \
    if(v->avail == v->tail) { \
        vector_grow_##vector_type(v); \
    } \
    //Append \
    *(v->avail++) = e; \
} \
\
void vector_grow_##vector_type(vector_##vector_type* v) { \
    //Determine new size \
    size_t old_size = vector_size_##vector_type(v); \
    size_t n_size = v->head ? old_size * 2 : 1; \
\
    //Allocate new \
    vector_type* n_head = (vector_type*) malloc(sizeof(vector_type) * n_size); \
\
    //Copy \
    algorithm_copy(vector_type*, v->head, v->avail, n_head); \
\
    //Destroy \
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
void vector_free_##vector_type(vector_##vector_type* v) { \
    free(v->head); \
    v->head = v->avail = v->tail = NULL; \
} \
