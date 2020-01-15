#include "../include/test-vector-struct-point.h"
#include "../lib/unity.h"
#include "../include/vector-struct-point.h"

void setUp() { }
void tearDown() { }
int is_equal_point(point a, point b);

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_vector_init_point);
    RUN_TEST(test_vector_init_size_point);
    RUN_TEST(test_vector_init_capacity_point);
    RUN_TEST(test_vector_push_back_point);
    RUN_TEST(test_vector_accessors_point);
    return UNITY_END();
}

void test_vector_init_point() {
    //Create and initialize test vector
    vector_point v;
    vector_init_point(&v);
   
    //Assert state of fresh vector
    TEST_ASSERT(v.head == NULL && v.avail == NULL && v.tail == NULL);

    //Free
    vector_free_point(&v);
}

void test_vector_init_size_point() {
    //Create and initialize test vector
    vector_point v;
    const size_t sz = 4;
    vector_init_size_point(&v, sz);
    
    //Assert state of newly created vector
    TEST_ASSERT(v.head != NULL && v.avail != NULL && v.tail != NULL);

    //Small test for vector_size
    TEST_ASSERT_EQUAL_UINT(sz, vector_size_point(&v));
    TEST_ASSERT_EQUAL_UINT(sz, vector_capacity_point(&v));

    //Free
    vector_free_point(&v);
}

void test_vector_init_capacity_point() {
    //Create and initialize test vector
    vector_point v;
    const size_t sz = 4;
    vector_init_capacity_point(&v, sz);
    
    //Assert state of newly created vector
    TEST_ASSERT(v.head != NULL && v.avail != NULL && v.tail != NULL);

    //Small test for vector_size
    TEST_ASSERT_EQUAL_UINT(0, vector_size_point(&v));
    TEST_ASSERT_EQUAL_UINT(sz, vector_capacity_point(&v));

    //Free
    vector_free_point(&v);
}

void test_vector_push_back_point() {
    //Create and initialize test vector
    vector_point v;
    vector_init_point(&v);

    //Try to push an element back
    const point e = (point) { "Shanghai", 0, 100 };
    vector_push_back_point(&v, e);

    //Assert state of vector post-element push
    TEST_ASSERT_EQUAL_UINT(1, vector_size_point(&v));
    TEST_ASSERT_EQUAL_UINT(1, vector_capacity_point(&v));

    //Small tests for vector_at and vector_begin
    TEST_ASSERT(is_equal_point(e, vector_at_point(&v, 0)));
    TEST_ASSERT(is_equal_point(e, *vector_begin_point(&v)));
    
    //Free
    vector_free_point(&v);
}

void test_vector_accessors_point() {
    //Create an intiialize test vector
    vector_point v;
    vector_init_point(&v);

    //Push a few elements back
    const point el[] = { { "Istanbul", 10, 50 }, { "Tokyo", 80, 80 }, { "Moscow", 100, 100 } };
    vector_push_back_point(&v, el[0]);
    vector_push_back_point(&v, el[1]);
    vector_push_back_point(&v, el[2]);

    //Assert usage of vector_at
    TEST_ASSERT(is_equal_point(el[0], vector_at_point(&v, 0)));
    TEST_ASSERT(is_equal_point(el[1], vector_at_point(&v, 1)));
    TEST_ASSERT(is_equal_point(el[2], vector_at_point(&v, 2)));
    
    //Assert usage of vector_begin and vector_end
    TEST_ASSERT(is_equal_point(el[0], *vector_begin_point(&v)));
    //Assert read of [vector_begin, vector_end)
    const point* e = el;
    for(point* b = vector_begin_point(&v); b != vector_end_point(&v); ++b, ++e) {
        TEST_ASSERT(is_equal_point(*b, *e));
    }

    //Free
    vector_free_point(&v);
}

int is_equal_point(point a, point b) {
    return a.name == b.name && a.x == b.x && a.y == b.y;
}
