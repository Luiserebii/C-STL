#include <ctype.h>

#include "../../../include/algorithm.h"
#include "../../include/algorithm/test-algorithm-find-if.h"
#include "../../lib/unity.h"

int _ta_isEven(int x);

void test_algorithm_find_if_int() {
    //Setting up initial array
    int a1[] = {1, 3, 4, 5, 6};
    const int sz1 = sizeof a1 / sizeof(int);
   
    //Attempt find_if of first isEven 
    int* res;
    algorithm_find_if(a1, a1 + sz1, _ta_isEven, res);

    //Assert finding the proper one
    TEST_ASSERT_EQUAL_PTR(a1 + 2, res);
    TEST_ASSERT_EQUAL_INT(a1[2], *res);

    //Attempt find_if on array with no even numbers
    int a2[] = {1, 3, 5, 5, 7};
    const int sz2 = sizeof a1 / sizeof(int);
    algorithm_find_if(a2, a2 + sz2, _ta_isEven, res);

    //Assert return of end
    TEST_ASSERT_EQUAL_PTR(a2 + sz2, res);
}

void test_algorithm_find_if_char() {
}

int _ta_isEven(int x) {
    return !(x & 1);
}
