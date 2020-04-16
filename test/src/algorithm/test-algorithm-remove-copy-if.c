#include <ctype.h>

#include <cstl/algorithm.h>
#include "../../include/algorithm/test-algorithm-remove-copy-if.h"
#include "../../lib/unity.h"

int isEven(int x);

void test_algorithm_remove_copy_if_int() {
    //Setting up initial array
    const int a1[] = {1, 2, 3, 4, 5, 6};
    const int sz = sizeof a1 / sizeof(int);
    int a2[sz];

    //Attempt remove_copy_if with isEven
    algorithm_remove_copy_if(int*, a1, a1 + sz, a2, isEven);
    const int expres[] = {1, 3, 5};
    TEST_ASSERT_EQUAL_INT_ARRAY(expres, a2, sizeof expres / sizeof(int));
}

void test_algorithm_remove_copy_if_char() {
    //Setting up initial array
    const char a1[] = {'A', 'b', 'C', 'd', 'E', 'f'};
    const int sz = sizeof a1 / sizeof(char);
    char a2[3];

    //Attempt remove_copy_if with islower
    algorithm_remove_copy_if(char*, a1, a1 + sz, a2, islower);
    const char expres[] = {'A', 'C', 'E'};
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expres, a2, sizeof expres / sizeof(char));
}

int isEven(int x) {
    return !(x & 1);
}
