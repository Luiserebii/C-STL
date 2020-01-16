#include <stdio.h>
#include <string.h>

#include "../../../include/algorithm.h"
#include "../../include/algorithm/test-algorithm-transform.h"
#include "../../lib/unity.h"

void setUp() {}
void tearDown() {}

int main() {

    UNITY_BEGIN();
    RUN_TEST(test_algorithm_transform_int);
    return UNITY_END();
}

int doubleInt(int x);

void test_algorithm_transform_int() {
    //Setting up basic array to copy over
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

int doubleInt(int x) {
    return x * 2;
}
