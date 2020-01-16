#include "../../include/vector/test-vector-int.h"
#include "../../include/vector/vector-int.h"
#include "../../lib/unity.h"

void setUp() {}
void tearDown() {}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_vector_init_int);
    RUN_TEST(test_vector_init_size_int);
    RUN_TEST(test_vector_init_capacity_int);
    RUN_TEST(test_vector_copy_int);
    RUN_TEST(test_vector_set_int);
    RUN_TEST(test_vector_push_back_int);
    RUN_TEST(test_vector_accessors_int);
    return UNITY_END();
}

void test_vector_init_int() {
    //Create and initialize test vector
    vector_int v;
    vector_init_int(&v);

    //Assert state of fresh vector
    TEST_ASSERT(v.head == NULL && v.avail == NULL && v.tail == NULL);

    //Free
    vector_free_int(&v);
}

void test_vector_init_size_int() {
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

void test_vector_init_capacity_int() {
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

void test_vector_copy_int() {
    //Create and initialize test vector
    vector_int v, copy;
    vector_init_int(&v);

    //Push a few elements back
    const int el[] = {10, 20, 30};
    vector_push_back_int(&v, el[0]);
    vector_push_back_int(&v, el[1]);
    vector_push_back_int(&v, el[2]);

    //Copy vector over
    vector_copy_int(&copy, &v);

    //Assert equality
    int res;
    algorithm_equal(int*, vector_begin_int(&v), vector_end_int(&v), vector_begin_int(&copy), res);
    TEST_ASSERT(res);

    //Ensure pointers are truly seperate
    vector_set_int(&copy, 1, 40);
    TEST_ASSERT(vector_at_int(&v, 1) != vector_at_int(&copy, 1));
    const int expEl[] = {10, 40, 30};
    algorithm_equal(int*, vector_begin_int(&copy), vector_end_int(&copy), expEl, res);
    TEST_ASSERT(res);
}

void test_vector_set_int() {
    //Create and intiailize test vector
    vector_int v, copy;
    vector_init_int(&v);

    //Push a few elements back
    const int el[] = {10, 20, 30};
    const int newEl[] = {10, 40, 30};
    vector_push_back_int(&v, el[0]);
    vector_push_back_int(&v, el[1]);
    vector_push_back_int(&v, el[2]);

    //Try setting the second element
    vector_set_int(&v, 1, newEl[1]);

    //Assert the element has been set
    TEST_ASSERT_EQUAL_INT(newEl[1], vector_at_int(&v, 1));

    //Furthermore, assert that the full set of stuff has been unmodified
    int res;
    algorithm_equal(int*, vector_begin_int(&v), vector_end_int(&v), newEl, res);
    TEST_ASSERT(res);
}

void test_vector_push_back_int() {
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

void test_vector_accessors_int() {
    //Create an intiialize test vector
    vector_int v;
    vector_init_int(&v);

    //Push a few elements back
    const int el[] = {10, 20, 30};
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
    for(int *b = vector_begin_int(&v); b != vector_end_int(&v); ++b, ++e) {
        TEST_ASSERT_EQUAL_UINT(*b, *e);
    }

    //Free
    vector_free_int(&v);
}
