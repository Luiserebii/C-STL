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

size_t vector_size(vector* v) {
    return v->avail - v->head;
}
