#include <ctype.h>

#include <cstl/algorithm.h>
#include "../../include/algorithm/test-algorithm-transform.h"
#include "../../lib/unity.h"

int doubleInt(int x);

void test_algorithm_transform_int() {
    //Setting up basic array
    int a1[] = {1, 2, 3};
    const int sz = sizeof a1 / sizeof(int);
    int a2[sz];

    //Attempt transformation with doubling unary
    algorithm_transform(int*, a1, a1 + sz, a2, doubleInt);

    //Assert transformation
    const int expres[] = {2, 4, 6};
    int res;
    algorithm_equal(int*, a2, a2 + sz, expres, res);
    TEST_ASSERT(res);
}

void test_algorithm_transform_char() {
    char a1[] = {'A', 'b', 'C', 'd', 'E', 'f', 'G'};
    const int sz = sizeof a1 / sizeof(char);
    char a2[sz];

    //Attempt transformation
    algorithm_transform(char*, a1, a1 + sz, a2, tolower);

    //Assert transformation
    const char expres[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    int res;
    algorithm_equal(char*, a2, a2 + sz, expres, res);
    TEST_ASSERT(res);
}

int doubleInt(int x) {
    return x * 2;
}
