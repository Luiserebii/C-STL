#include <stdio.h>
#include <string.h>

#include "../../include/algorithm.h"
#include "../include/test-algorithm.h"
#include "../lib/unity.h"

void setUp() {}
void tearDown() {}
void test_algorithm_find_int();

int main() {

    UNITY_BEGIN();
    RUN_TEST(test_algorithm_copy_int);
    RUN_TEST(test_algorithm_copy_char);
    RUN_TEST(test_algorithm_copy_struct);
    RUN_TEST(test_algorithm_find_int);
    return UNITY_END();
}

void test_algorithm_copy_int() {
    //Setting up basic array to copy over
    int a1[] = {1, 2, 3};
    const int sz = sizeof a1 / sizeof(int);
    int a2[sz];

    //Attempt copying of a1 into a2
    TEST_ASSERT(memcmp(a1, a2, sizeof a1) != 0);
    algorithm_copy(int*, a1, a1 + sz, a2);

    //Assert copied values
    TEST_ASSERT_EQUAL_INT_ARRAY(a1, a2, sz);
}

void test_algorithm_copy_char() {
    //Setting up basic array to copy over
    char a1[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    const int sz = sizeof a1 / sizeof(char);
    char a2[sz];

    //Attempt copying of a1 into a2
    TEST_ASSERT(memcmp(a1, a2, sizeof a1) != 0);
    algorithm_copy(char*, a1, a1 + sz, a2);

    //Assert copied values
    TEST_ASSERT_EQUAL_CHAR_ARRAY(a1, a2, sz);
}

void test_algorithm_copy_struct() {
    //Setting up basic array of structs to copy over
    struct point a1[] = {{1, 2}, {4, 5}, {10, 10}};
    const int sz = sizeof a1 / sizeof(struct point);
    struct point a2[sz];

    //Attempt copying of a1 into a2
    TEST_ASSERT(memcmp(a1, a2, sizeof a1) != 0);
    algorithm_copy(struct point*, a1, a1 + sz, a2);

    //Assert copied values
    TEST_ASSERT(memcmp(a1, a2, sizeof a1) == 0);
}

void test_algorithm_find_int() {
    //Setting up basic array to look for a value
    int a[] = {10, 20, 30};
    const int sz = sizeof a / sizeof(int);
    int* found;
     
    //Look for second element
    algorithm_find(a, a + sz, a[1], found);
    TEST_ASSERT_EQUAL_INT(a[1], *found);

    //Look for non-existing element
    algorithm_find(a, a + sz, 1000, found);
    TEST_ASSERT_EQUAL_PTR(a + sz, found);
}
