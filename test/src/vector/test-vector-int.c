#include "../../include/vector/test-vector-int.h"
#include "../../include/vector/vector-int.h"
#include "../../lib/unity.h"

void setUp() {}
void tearDown() {}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_vector_int_create);
    RUN_TEST(test_vector_int_create_size);
    RUN_TEST(test_vector_int_create_capacity);
    RUN_TEST(test_vector_int_copy);
    RUN_TEST(test_vector_int_assign);
    RUN_TEST(test_vector_int_set);
    RUN_TEST(test_vector_int_push_back);
    RUN_TEST(test_vector_int_insert);
    RUN_TEST(test_vector_int_erase);
    RUN_TEST(test_vector_int_erase_range);
    RUN_TEST(test_vector_int_accessors);
    RUN_TEST(test_vector_int_idioms);
    return UNITY_END();
}

void test_vector_int_create() {
    //Create and initialize test vector
    vector_int* v = vector_int_create();

    //Assert state of fresh vector
    TEST_ASSERT(v->head == NULL && v->avail == NULL && v->tail == NULL);

    //Free
    vector_int_destroy(v);
}

void test_vector_int_create_size() {
    //Create and initialize test vector
    const size_t sz = 4;
    vector_int* v = vector_int_create_size(sz);

    //Assert state of newly created vector
    TEST_ASSERT(v->head != NULL && v->avail != NULL && v->tail != NULL);

    //Small test for vector_size
    TEST_ASSERT_EQUAL_UINT(sz, vector_int_size(v));
    TEST_ASSERT_EQUAL_UINT(sz, vector_int_capacity(v));

    //Free
    vector_int_destroy(v);
}

void test_vector_int_create_capacity() {
    //Create and initialize test vector
    const size_t sz = 4;
    vector_int* v = vector_int_create_capacity(sz);

    //Assert state of newly created vector
    TEST_ASSERT(v->head != NULL && v->avail != NULL && v->tail != NULL);

    //Small test for vector_size
    TEST_ASSERT_EQUAL_UINT(0, vector_int_size(v));
    TEST_ASSERT_EQUAL_UINT(sz, vector_int_capacity(v));

    //Free
    vector_int_destroy(v);
}

void test_vector_int_copy() {
    //Create and initialize test vector
    vector_int *v, *copy;
    v = vector_int_create();

    //Push a few elements back
    const int el[] = {10, 20, 30};
    vector_int_push_back(v, el[0]);
    vector_int_push_back(v, el[1]);
    vector_int_push_back(v, el[2]);

    //Copy vector over
    copy = vector_int_copy(v);

    //Assert equality
    int res;
    algorithm_equal(int*, vector_int_begin(v), vector_int_end(v), vector_int_begin(copy), res);
    TEST_ASSERT(res);

    //Ensure pointers are truly seperate
    vector_int_set(copy, 1, 40);
    TEST_ASSERT(vector_int_at(v, 1) != vector_int_at(copy, 1));
    const int expEl[] = {10, 40, 30};
    algorithm_equal(int*, vector_int_begin(copy), vector_int_end(copy), expEl, res);
    TEST_ASSERT(res);

    //Free
    vector_int_destroy(v);
    vector_int_destroy(copy);
}
void test_vector_int_assign() {
    vector_int v;
    vector_int_init(&v);

    //Test assigning to an empty vector
    const int el[] = {10, 20, 30, 40, 50};
    const int sz = 5;
    vector_int_assign(&v, el, el + sz);

    TEST_ASSERT_EQUAL_INT_ARRAY(el, vector_int_begin(&v), sz);
    TEST_ASSERT_EQUAL_INT(sz, vector_int_size(&v));

    //Test assigning to a vector with some size (capacity should be unchanged)
    size_t old_cap = vector_int_capacity(&v);
    vector_int_assign(&v, el, el + 3);
    size_t new_cap = vector_int_capacity(&v);

    TEST_ASSERT_EQUAL_INT_ARRAY(el, vector_int_begin(&v), 3);
    TEST_ASSERT_EQUAL_INT(3, vector_int_size(&v));
    TEST_ASSERT_EQUAL_INT(old_cap, new_cap);

    vector_int_deinit(&v);
}

void test_vector_int_set() {
    //Declare (onto the stack) and intiailize test vector
    vector_int v;
    vector_int_init(&v);

    //Push a few elements back
    const int el[] = {10, 20, 30};
    const int newEl[] = {10, 40, 30};
    vector_int_push_back(&v, el[0]);
    vector_int_push_back(&v, el[1]);
    vector_int_push_back(&v, el[2]);

    //Try setting the second element
    vector_int_set(&v, 1, newEl[1]);

    //Assert the element has been set
    TEST_ASSERT_EQUAL_INT(newEl[1], vector_int_at(&v, 1));

    //Furthermore, assert that the full set of stuff has been unmodified
    int res;
    algorithm_equal(int*, vector_int_begin(&v), vector_int_end(&v), newEl, res);
    TEST_ASSERT(res);

    //Free
    vector_int_deinit(&v);
}

void test_vector_int_push_back() {
    //Declare (onto the stack) and intiailize test vector
    vector_int v;
    vector_int_init(&v);

    //Try to push an element back
    const int e = 10;
    vector_int_push_back(&v, e);

    //Assert state of vector post-element push
    TEST_ASSERT_EQUAL_UINT(1, vector_int_size(&v));
    TEST_ASSERT_EQUAL_UINT(1, vector_int_capacity(&v));

    //Small tests for vector_at and vector_begin
    TEST_ASSERT_EQUAL_UINT(e, vector_int_at(&v, 0));
    TEST_ASSERT_EQUAL_UINT(e, *vector_int_begin(&v));

    //Free
    vector_int_deinit(&v);
}

void test_vector_int_insert() {
    //Declare (onto the stack) and intiailize test vector
    vector_int v;
    vector_int_init(&v);

    //Insert multiple elements in
    const int n = 4;
    const int el[] = {10, 20, 30, 40};
    vector_int_insert_range(&v, v.head, el, el + n);

    //Assert elements and size
    TEST_ASSERT_EQUAL_INT_ARRAY(el, v.head, n);
    TEST_ASSERT_EQUAL_INT(n, vector_int_size(&v));

    //Insert a selection of elements in
    const int exp1[] = {10, 20, 10, 20, 30, 30, 40};
    vector_int_insert_range(&v, v.head + 2, el, el + 3);

    //Assert elements and size
    TEST_ASSERT_EQUAL_INT_ARRAY(exp1, v.head, 7);
    TEST_ASSERT_EQUAL_INT(7, vector_int_size(&v));

    //Insert a simple element in
    const int exp2[] = {10, 20, 10, 20, 500, 30, 30, 40};
    vector_int_insert(&v, v.head + 4, 500);
    TEST_ASSERT_EQUAL_INT_ARRAY(exp2, v.head, 8);
    TEST_ASSERT_EQUAL_INT(8, vector_int_size(&v));

    //Free
    vector_int_deinit(&v);
}

void test_vector_int_erase() {
    //Declare (onto the stack) and intiailize test vector
    vector_int v;
    vector_int_init(&v);

    //Push a few elements back
    const int el[] = {10, 20, 30};
    vector_int_push_back(&v, el[0]);
    vector_int_push_back(&v, el[1]);
    vector_int_push_back(&v, el[2]);

    //Attempt erasure of second element
    int* newEnd = vector_int_erase(&v, vector_int_begin(&v) + 1);

    //Assert newEnd is valid
    TEST_ASSERT_EQUAL_PTR(newEnd, vector_int_begin(&v) + 2);

    //Assert elements have changed (this also tests size implicitly)
    const int newEl[] = {10, 30};
    int isEqual;
    algorithm_equal(int*, vector_int_begin(&v), vector_int_end(&v), newEl, isEqual);
    TEST_ASSERT(isEqual);

    //Free
    vector_int_deinit(&v);
}

void test_vector_int_erase_range() {
    //Declare (onto the stack) and intialize test vector
    vector_int v;
    vector_int_init(&v);

    //Push some elements back
    const int el[] = {10, 20, 30, 40, 50};
    vector_int_push_back(&v, el[0]);
    vector_int_push_back(&v, el[1]);
    vector_int_push_back(&v, el[2]);
    vector_int_push_back(&v, el[3]);
    vector_int_push_back(&v, el[4]);

    //Attempt erasure of [2, 4)
    int* newEnd = vector_int_erase_range(&v, vector_int_begin(&v) + 2, vector_int_begin(&v) + 4);

    //Assert newEnd is valid
    TEST_ASSERT_EQUAL_PTR(newEnd, vector_int_begin(&v) + 3);

    //Assert elements have changed (this also tests size implicitly)
    const int newEl[] = {10, 20, 50};
    int isEqual;
    algorithm_equal(int*, vector_int_begin(&v), vector_int_end(&v), newEl, isEqual);
    TEST_ASSERT(isEqual);

    //Free
    vector_int_deinit(&v);
}

void test_vector_int_accessors() {
    //Declare (onto the stack) and intiailize test vector
    vector_int v;
    vector_int_init(&v);

    //Push a few elements back
    const int el[] = {10, 20, 30};
    vector_int_push_back(&v, el[0]);
    vector_int_push_back(&v, el[1]);
    vector_int_push_back(&v, el[2]);

    //Assert usage of vector_at
    TEST_ASSERT_EQUAL_UINT(el[0], vector_int_at(&v, 0));
    TEST_ASSERT_EQUAL_UINT(el[1], vector_int_at(&v, 1));
    TEST_ASSERT_EQUAL_UINT(el[2], vector_int_at(&v, 2));

    //Assert usage of vector_begin and vector_end
    TEST_ASSERT_EQUAL_UINT(el[0], *vector_int_begin(&v));
    //Assert read of [vector_begin, vector_end)
    const int* e = el;
    for(int *b = vector_int_begin(&v); b != vector_int_end(&v); ++b, ++e) {
        TEST_ASSERT_EQUAL_UINT(*b, *e);
    }

    //Free
    vector_int_deinit(&v);
}

void test_vector_int_idioms() {
    //Declare (onto the stack) and intiailize test vector
    vector_int v;
    vector_int_init(&v);

    //Push some elements back
    const int el[] = {15, 30, 45, 60, 75};
    vector_int_push_back(&v, el[0]);
    vector_int_push_back(&v, el[1]);
    vector_int_push_back(&v, el[2]);
    vector_int_push_back(&v, el[3]);
    vector_int_push_back(&v, el[4]);

    //Attempt to remove all even nums from vector
    int isEven(int x);
    int* lastIt;
    algorithm_remove_if(int*, vector_int_begin(&v), vector_int_end(&v), isEven, lastIt);
    vector_int_erase_range(&v, lastIt, vector_int_end(&v));

    //Now, assert the new vector:
    const int expEl[] = {15, 45, 75};
    int isEqual;
    algorithm_equal(int*, vector_int_begin(&v), vector_int_end(&v), expEl, isEqual);
    TEST_ASSERT(isEqual);

    //Free
    vector_int_deinit(&v);
}

int isEven(int x) {
    return !(x & 1);
}
