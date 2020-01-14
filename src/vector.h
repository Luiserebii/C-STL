#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct {
    int* head;
    int* avail;
    int* tail;
} vector;

vector vector_init();
void vector_init_size(vector* v, size_t s);
void vector_push_back(vector* v, int e);
size_t vector_size(vector* v);
void vector_free(vector* v);

static void vector_grow(vector* v);

#endif
