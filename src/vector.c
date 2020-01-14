#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

void vector_init(vector* v, size_t t_sz) {
    *v = (vector) { NULL, NULL, NULL, t_sz };
}

void vector_init_size(vector* v, size_t t_sz, size_t n) {
    v->head = v->avail = malloc(t_sz * n);
    v->tail = v->head + n;
    v->type_size = t_sz;
}

void vector_push_back(vector* v, const void* e) {
    if(v->avail == v->tail) {
        vector_grow(v);
    }
    //Append
    *(v->avail++) = *e;
}

void vector_grow(vector* v) {
    //Determine new size
    size_t old_size = vector_size(v);
    size_t n_size = v->head ? old_size * 2 : 1;

    //Allocate new
    void* n_head = malloc(v->type_size * n_size);

    //Copy
    for(void* i = v->head, * n = n_head; i != v->avail;) {
        *n++ = *i++;
    }

    //Destroy
    free(v->head);
    v->head = n_head;
    v->avail = n_head + old_size;
    v->tail = n_head + n_size;
}

size_t vector_size(vector* v) {
    return v->avail - v->head;
}

size_t vector_capacity(vector* v) {
    return v->tail - v->head;
}

void vector_free(vector* v) {
    free(v->head);
    v->head = v->avail = v->tail = NULL;
}
