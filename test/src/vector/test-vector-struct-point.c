#include "../../include/vector/test-vector-struct-point.h"
#include "../../include/vector/vector-struct-point.h"
#include "../../lib/unity.h"

void setUp() {}
void tearDown() {}
int is_equal_point(point a, point b);

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_vector_point_create);
    RUN_TEST(test_vector_point_create_size);
    RUN_TEST(test_vector_point_create_capacity);
    RUN_TEST(test_vector_point_push_back);
    RUN_TEST(test_vector_point_accessors);
    return UNITY_END();
}

void test_vector_point_create() {
    //Create and initialize test vector
    vector_point* v = vector_point_create();

    //Assert state of fresh vector
    TEST_ASSERT(v->head == NULL && v->avail == NULL && v->tail == NULL);

    //Free
    vector_point_destroy(v);
}

void test_vector_point_create_size() {
    //Create and initialize test vector
    const size_t sz = 4;
    vector_point* v = vector_point_create_size(sz);

    //Assert state of newly created vector
    TEST_ASSERT(v->head != NULL && v->avail != NULL && v->tail != NULL);

    //Small test for vector_size
    TEST_ASSERT_EQUAL_UINT(sz, vector_point_size(v));
    TEST_ASSERT_EQUAL_UINT(sz, vector_point_capacity(v));

    //Free
    vector_point_destroy(v);
}

void test_vector_point_create_capacity() {
    //Create and initialize test vector
    const size_t sz = 4;
    vector_point* v = vector_point_create_capacity(sz);

    //Assert state of newly created vector
    TEST_ASSERT(v->head != NULL && v->avail != NULL && v->tail != NULL);

    //Small test for vector_size
    TEST_ASSERT_EQUAL_UINT(0, vector_point_size(v));
    TEST_ASSERT_EQUAL_UINT(sz, vector_point_capacity(v));

    //Free
    vector_point_destroy(v);
}

void test_vector_point_push_back() {
    vector_point v;
    vector_point_init(&v);

    //Try to push an element back
    const point e = (point){"Shanghai", 0, 100};
    vector_point_push_back(&v, e);

    //Assert state of vector post-element push
    TEST_ASSERT_EQUAL_UINT(1, vector_point_size(&v));
    TEST_ASSERT_EQUAL_UINT(1, vector_point_capacity(&v));

    //Small tests for vector_at and vector_begin
    TEST_ASSERT(is_equal_point(e, vector_point_at(&v, 0)));
    TEST_ASSERT(is_equal_point(e, *vector_point_begin(&v)));

    //Free
    vector_point_deinit(&v);
}

void test_vector_point_accessors() {
    vector_point v;
    vector_point_init(&v);

    //Push a few elements back
    const point el[] = {{"Istanbul", 10, 50}, {"Tokyo", 80, 80}, {"Moscow", 100, 100}};
    vector_point_push_back(&v, el[0]);
    vector_point_push_back(&v, el[1]);
    vector_point_push_back(&v, el[2]);

    //Assert usage of vector_at
    TEST_ASSERT(is_equal_point(el[0], vector_point_at(&v, 0)));
    TEST_ASSERT(is_equal_point(el[1], vector_point_at(&v, 1)));
    TEST_ASSERT(is_equal_point(el[2], vector_point_at(&v, 2)));

    //Assert usage of vector_begin and vector_end
    TEST_ASSERT(is_equal_point(el[0], *vector_point_begin(&v)));
    //Assert read of [vector_begin, vector_end)
    const point* e = el;
    for(point *b = vector_point_begin(&v); b != vector_point_end(&v); ++b, ++e) {
        TEST_ASSERT(is_equal_point(*b, *e));
    }

    //Free
    vector_point_deinit(&v);
}

int is_equal_point(point a, point b) {
    return a.name == b.name && a.x == b.x && a.y == b.y;
}
