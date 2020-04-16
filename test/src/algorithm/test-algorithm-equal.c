#include "../../include/algorithm/test-algorithm-equal.h"
#include <cstl/algorithm.h>
#include "../../lib/unity.h"

void test_algorithm_equal_int() {
    //Setting basic arrays
    int a[] = {10, 20, 30};
    int sz = sizeof a / sizeof(int);
    int b[] = {10, 20, 50};
    int res;

    //Compare [a, a + sz -1) for both arrays
    int* e1 = a + sz - 1;
    algorithm_equal(int*, a, e1, b, res);
    TEST_ASSERT_TRUE(res);

    //Compare [a, a + sz) for both arrays
    int* e2 = a + sz;
    algorithm_equal(int*, a, e2, b, res);
    TEST_ASSERT_FALSE(res);
}

void test_algorithm_equal_char() {
    //Setting basic arrays
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int sz = sizeof a / sizeof(char);
    char b[] = {'a', 'b', 'c', 'd', 'q'};
    int res;

    //Compare [a, a + sz - 2) for both arrays
    char* e1 = a + sz - 2;
    algorithm_equal(char*, a, e1, b, res);
    TEST_ASSERT_TRUE(res);

    //Compare [a, a + sz - 1) for both arrays
    char* e2 = a + sz - 1;
    algorithm_equal(char*, a, e2, b, res);
    TEST_ASSERT_FALSE(res);
}
