#include <ctype.h>

#include <cstl/algorithm.h>
#include "../../include/algorithm/test-algorithm-remove-copy.h"
#include "../../lib/unity.h"

void test_algorithm_remove_copy_int() {
    //Setting up initial array
    const int a1[] = {1, 2, 3, 2, 3, 2};
    const int sz = sizeof a1 / sizeof(int);
    int a2[3];

    //Attempt remove_copy with 2
    algorithm_remove_copy(int*, a1, a1 + sz, a2, 2) const int expres[] = {1, 3, 3};
    TEST_ASSERT_EQUAL_INT_ARRAY(expres, a2, sizeof expres / sizeof(int));
}

void test_algorithm_remove_copy_char() {
    //Setting up initial array
    const char a1[] = {'a', 'b', 'b', 'a', 'e', 'f'};
    const int sz = sizeof a1 / sizeof(char);
    char a2[4];

    //Attempt remove_copy_if with islower
    algorithm_remove_copy(char*, a1, a1 + sz, a2, 'a');
    const char expres[] = {'b', 'b', 'e', 'f'};
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expres, a2, sizeof expres / sizeof(char));
}
