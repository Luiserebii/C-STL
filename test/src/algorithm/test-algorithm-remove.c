#include <ctype.h>

#include <cstl/algorithm.h>
#include "../../include/algorithm/test-algorithm-remove.h"
#include "../../lib/unity.h"

void test_algorithm_remove_int() {
    //Setting up initial array
    int a1[] = {1, 2, 1, 2, 1};
    const int sz1 = sizeof a1 / sizeof(int);

    //Attempt to remove all 2s with algorithm_remove
    int* res;
    algorithm_remove(int*, a1, a1 + sz1, 2, res);

    //Assert iterator and new range
    TEST_ASSERT_EQUAL_PTR(a1 + 3, res);
    int expran[] = {1, 1, 1};
    TEST_ASSERT_EQUAL_INT_ARRAY(a1, expran, sizeof expran / sizeof(int));
}

void test_algorithm_remove_char() {
    //Setting up initial array
    char a1[] = {'a', 'b', 'c', 'a', 'b'};
    const int sz1 = sizeof a1 / sizeof(char);

    //Attempt to remove all bs with algorithm_remove
    char* res;
    algorithm_remove(char*, a1, a1 + sz1, 'b', res);

    //Assert iterator and new range
    TEST_ASSERT_EQUAL_PTR(a1 + 3, res);
    char expran[] = {'a', 'c', 'a'};
    TEST_ASSERT_EQUAL_CHAR_ARRAY(a1, expran, sizeof expran / sizeof(char));
}
