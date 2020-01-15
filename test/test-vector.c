#include <stdio.h>

#include "./lib/unity.h"
#include "../src/vector.h"

//Macros to setup vector of int
declare_vector(int)
define_vector(int)

void test_vector_init();

void setUp() { }
void tearDown() { }

int main() {

    UNITY_BEGIN();
    RUN_TEST(test_vector_init);
    return UNITY_END();
/*
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

    vector_free_int(&v);
    vector_free_int(&v2);*/
}

void test_vector_init() {
    //Create and initialize test vector
    vector_int v;
    vector_init_int(&v);
   
    //Assert state of fresh vector
    TEST_ASSERT(v.head == NULL && v.avail == NULL && v.tail == NULL);

    //Free
    vector_free_int(&v);
}
