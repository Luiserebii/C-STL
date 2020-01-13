#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct {
    int* head;
    int* avail;
    int* tail;
} vector;

vector vector_init();
void vector_push_back(vector* v);
size_t vector_size(vector* v);

#endif
