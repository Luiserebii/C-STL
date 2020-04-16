#include <ctype.h>

#include <cstl/algorithm.h>
#include "../../include/algorithm/test-algorithm-remove-if.h"
#include "../../lib/unity.h"

int _tari_isEven(int x);

void test_algorithm_remove_if_int() {
    //Setting up initial array
    int a1[] = {1, 2, 3, 4, 5, 6, 7};
    const int sz1 = sizeof a1 / sizeof(int);

    //Attempt to remove all evens with algorithm_remove_if
    int* res;
    algorithm_remove_if(int*, a1, a1 + sz1, _tari_isEven, res);

    //Assert iterator and new range
    TEST_ASSERT_EQUAL_PTR(a1 + 4, res);
    int expran[] = {1, 3, 5, 7};
    TEST_ASSERT_EQUAL_INT_ARRAY(a1, expran, sizeof expran / sizeof(int));
}

void test_algorithm_remove_if_char() {
    //Setting up initial array
    char a1[] = {'A', 'B', 'c', 'D', 'e', 'f'};
    const int sz1 = sizeof a1 / sizeof(char);

    //Attempt to remove all uppercase with algorithm_remove
    char* res;
    algorithm_remove_if(char*, a1, a1 + sz1, isupper, res);

    //Assert iterator and new range
    TEST_ASSERT_EQUAL_PTR(a1 + 3, res);
    char expran[] = {'c', 'e', 'f'};
    TEST_ASSERT_EQUAL_CHAR_ARRAY(a1, expran, sizeof expran / sizeof(char));
}

int _tari_isEven(int x) {
    return !(x & 1);
}
