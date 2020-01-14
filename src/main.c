#include <stdio.h>

//#define VECTOR_TYPE int
#include "vector.h"
#include "algorithm.h"

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

    //Testing algorithm.h
    int testArr[] = { 1, 2, 3 };
    int meme[sizeof testArr/sizeof(int)];
    array_print(testArr, 3);
    array_print(meme, 3);
    copy(int, testArr, testArr + 3, meme)
    array_print(meme, 3);

}

void vector_print(vector* v) {
    printf("Vector | size: %lu | capacity: %lu\n", vector_size(v), vector_capacity(v));
    printf("Elements:");
    for(int* i = v->head; i != v->avail; ++i) {
        printf(" %d", *i);
    }
    putchar('\n');
}

void array_print(int* arr, int n) {
    printf("Array:");
    while(n--) {
        printf(" %d", *arr++);
    }
    putchar('\n');
}
