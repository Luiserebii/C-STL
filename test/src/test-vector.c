#include "../include/test-vector.h"
#include "../lib/unity.h"
#include "../include/vector-int.h"

void setUp() { }
void tearDown() { }

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_vector_init);
    RUN_TEST(test_vector_init_size);
    RUN_TEST(test_vector_init_capacity);
    RUN_TEST(test_vector_push_back);
    RUN_TEST(test_vector_accessors);
    return UNITY_END();
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

void test_vector_init_size() {
    //Create and initialize test vector
    vector_int v;
    const size_t sz = 4;
    vector_init_size_int(&v, sz);
    
    //Assert state of newly created vector
    TEST_ASSERT(v.head != NULL && v.avail != NULL && v.tail != NULL);

    //Small test for vector_size
    TEST_ASSERT_EQUAL_UINT(sz, vector_size_int(&v));
    TEST_ASSERT_EQUAL_UINT(sz, vector_capacity_int(&v));

    //Free
    vector_free_int(&v);
}

void test_vector_init_capacity() {
    //Create and initialize test vector
    vector_int v;
    const size_t sz = 4;
    vector_init_capacity_int(&v, sz);
    
    //Assert state of newly created vector
    TEST_ASSERT(v.head != NULL && v.avail != NULL && v.tail != NULL);

    //Small test for vector_size
    TEST_ASSERT_EQUAL_UINT(0, vector_size_int(&v));
    TEST_ASSERT_EQUAL_UINT(sz, vector_capacity_int(&v));

    //Free
    vector_free_int(&v);
}

void test_vector_push_back() {
    //Create and initialize test vector
    vector_int v;
    vector_init_int(&v);

    //Try to push an element back
    const int e = 10;
    vector_push_back_int(&v, e);

    //Assert state of vector post-element push
    TEST_ASSERT_EQUAL_UINT(1, vector_size_int(&v));
    TEST_ASSERT_EQUAL_UINT(1, vector_capacity_int(&v));

    //Small tests for vector_at and vector_begin
    TEST_ASSERT_EQUAL_UINT(e, vector_at_int(&v, 0));
    TEST_ASSERT_EQUAL_UINT(e, *vector_begin_int(&v));

    //Free
    vector_free_int(&v);
}

void test_vector_accessors() {
    //Create an intiialize test vector
    vector_int v;
    vector_init_int(&v);

    //Push a few elements back
    const int el[] = { 10, 20, 30 };
    vector_push_back_int(&v, el[0]);
    vector_push_back_int(&v, el[1]);
    vector_push_back_int(&v, el[2]);

    //Assert usage of vector_at
    TEST_ASSERT_EQUAL_UINT(el[0], vector_at_int(&v, 0));
    TEST_ASSERT_EQUAL_UINT(el[1], vector_at_int(&v, 1));
    TEST_ASSERT_EQUAL_UINT(el[2], vector_at_int(&v, 2));
    
    //Assert usage of vector_begin and vector_end
    TEST_ASSERT_EQUAL_UINT(el[0], *vector_begin_int(&v));
    //Assert read of [vector_begin, vector_end)
    const int* e = el;
    for(int* b = vector_begin_int(&v); b != vector_end_int(&v); ++b, ++e) {
        TEST_ASSERT_EQUAL_UINT(*b, *e);
    }

    //Free
    vector_free_int(&v);
}
