#include "../../include/algorithm/test-algorithm-count.h"
#include <cstl/algorithm.h>
#include "../../lib/unity.h"

void test_algorithm_count_int() {
    //Basic setup
    int a[] = {1, 2, 1, 2, 1};
    int sz = sizeof a / sizeof(int);
    int count;

    //Attempt count of 1
    algorithm_count(int*, a, a + sz, 1, count);
    TEST_ASSERT_EQUAL_INT(3, count);

    //Attempt count of non-existing
    algorithm_count(int*, a, a + sz, 0, count);
    TEST_ASSERT_EQUAL_INT(0, count);
}

void test_algorithm_count_char() {
    //Basic setup
    char a[] = {'a', 'b', 'c', 'd', 'a', 'd', 'c'};
    int sz = sizeof a / sizeof(char);
    int count;

    //Attempt count of c
    algorithm_count(char*, a, a + sz, 'c', count);
    TEST_ASSERT_EQUAL_INT(2, count);

    //Attempt count of non-existing
    algorithm_count(char*, a, a + sz, 'z', count);
    TEST_ASSERT_EQUAL_INT(0, count);
}
