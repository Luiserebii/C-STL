#include <stdio.h>
#include <string.h>

#include "../../include/algorithm.h"
#include "../include/algorithm/test-algorithm-accumulate.h"
#include "../lib/unity.h"

void setUp() {}
void tearDown() {}

int main() {

    UNITY_BEGIN();
    RUN_TEST(test_algorithm_accumulate_int);
    RUN_TEST(test_algorithm_accumulate_double);
    return UNITY_END();
}

void test_algorithm_accumulate_int() {
    //Setting up basic array to copy over
    int a1[] = {1, 2, 3};
    const int sz = sizeof a1 / sizeof(int);

    //Attempt accumulate and assert
    int sum = 0;
    algorithm_accumulate(int*, a1, a1 + sz, sum);
    TEST_ASSERT_EQUAL_INT(a1[0] + a1[1] + a1[2], sum);
}

void test_algorithm_accumulate_double() {
    //Setting up basic array to copy over
    double a1[] = {1.25, 2.5, 3.75};
    const int sz = sizeof a1 / sizeof(double);

    //Attempt accumulate and assert
    double sum = 0;
    algorithm_accumulate(double*, a1, a1 + sz, sum);
    TEST_ASSERT_EQUAL_INT(a1[0] + a1[1] + a1[2], sum);
}
