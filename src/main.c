#include <stdio.h>

#include "vector.h"
#include "algorithm.h"

declare_vector(int)
define_vector(int)

void vector_print(vector_int* v);
void array_print(int* arr, int n);

int main() {

    vector_int v;
    vector_init_int(&v);

    vector_push_back_int(&v, 5);

    vector_int v2;
    vector_init_size_int(&v2, 2);

    vector_push_back_int(&v2, 0);
    vector_push_back_int(&v2, 10);
    vector_push_back_int(&v2, 20);
    
    vector_print(&v2);
    vector_push_back_int(&v2, 30);
    vector_push_back_int(&v2, 40);
    vector_push_back_int(&v2, 50);
    vector_print(&v2);
    printf("Element at pos 5: %d\n", vector_at_int(&v2, 5));

    //Testing algorithm.h
    int testArr[] = { 1, 2, 3 };
    int meme[sizeof testArr/sizeof(int)];
    array_print(testArr, 3);
    array_print(meme, 3);
    algorithm_copy(int*, testArr, testArr + 3, meme);
    array_print(meme, 3);
    
}

void vector_print(vector_int* v) {
    printf("Vector | size: %lu | capacity: %lu\n", vector_size_int(v), vector_capacity_int(v));
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
