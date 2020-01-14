#include "vector.h"
#include <stdio.h>
void vector_print(vector* v);

int main() {

    vector v;
    vector_init(&v);
    vector_push_back(&v, 5);

    vector v2;
    vector_init_size(&v2, 2);

    vector_push_back(&v2, 10);
    vector_push_back(&v2, 10);
    vector_push_back(&v2, 10);
    
    vector_print(&v2);
    vector_push_back(&v2, 10);
    vector_push_back(&v2, 10);
    vector_push_back(&v2, 10);
    vector_print(&v2);
}

void vector_print(vector* v) {
    printf("Vector | size: %lu | capacity: %lu\n", vector_size(v), vector_capacity(v));
}
