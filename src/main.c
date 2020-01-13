#include "vector.h"
#include <stdio.h>

int main() {

    vector v = vector_init();
    vector_push_back(&v, 5);

    vector v2;
    vector_init_size(&v2, 2);

    vector_push_back(&v2, 10);
    vector_push_back(&v2, 10);
    vector_push_back(&v2, 10);

}
