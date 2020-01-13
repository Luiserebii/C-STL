#include "vector.h"

vector vector_init() {
    vector v = { NULL, NULL, NULL };
    return v;
}

void vector_push_back(vector* v) {
    
}

size_t vector_size(vector* v) {
    return v->head - v->avail;
}
