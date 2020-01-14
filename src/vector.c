#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

vector vector_init() {
    vector v = { NULL, NULL, NULL };
    return v;
}

void vector_init_size(vector* v, size_t s) {
    v->head = v->avail = (int*) malloc(sizeof(int) * s);
    v->tail = v->head + s;
}

void vector_push_back(vector* v, int e) {
    if(v->avail != v->tail) {
        *(v->avail) = e;
        ++v->avail;
    } else {
        printf("We're full at max capacity! Current size: %lu\n", vector_size(v));
    }
}

void vector_grow(vector* v) {
    //Determine new size
    size_t old_size = vector_size(v);
    size_t n_size = v->head ? 1 : old_size * 2;

    //Allocate new
    int* n_head = (int*) malloc(sizeof(int) * n_size);

    //Copy
    for(int* i = v->head, * n = n_head; i != v->avail;) {
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

void vector_free(vector* v) {
    free(v->head);
    v->head = v->avail = v->tail = NULL;
}
