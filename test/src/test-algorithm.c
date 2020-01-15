#include <stdio.h>
#include <string.h>

#include "../../include/algorithm.h"
#include "../include/test-algorithm.h"
#include "../lib/unity.h"

void setUp() {}
void tearDown() {}
void test_algorithm_find_int();
void test_algorithm_find_char();
void test_algorithm_find_struct();

int main() {

    UNITY_BEGIN();
    RUN_TEST(test_algorithm_copy_int);
    RUN_TEST(test_algorithm_copy_char);
    RUN_TEST(test_algorithm_copy_struct);
    RUN_TEST(test_algorithm_find_int);
    RUN_TEST(test_algorithm_find_char);
    //RUN_TEST(test_algorithm_find_struct);
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

void test_algorithm_find_char() {
    //Setting up basic char array
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    const int sz = sizeof a / sizeof(char);
    char* found;

    //Look for fourth element
    algorithm_find(a, a + sz, a[3], found);
    TEST_ASSERT_EQUAL_CHAR(a[3], *found);

    //Look for non-existing element
    algorithm_find(a, a + sz, 'z', found);
    TEST_ASSERT_EQUAL_PTR(a + sz, found);
}
/*
void test_algorithm_find_struct() {
    //Setting up basic array of structs
    struct point a[] = {{1, 2}, {4, 5}, {10, 10}};
    const int sz = sizeof a / sizeof(struct point);
    struct point* found;
    
    //Look for second element
    algorithm_find(a, a + sz, a[1], found);
    TEST_ASSERT_EQUAL_MEMORY(a + 1, found, sizeof(struct point));

    //Look for non-existing element
    //algorithm_find(a, a + sz, (struct point){2, 3}, found);
    //TEST_ASSERT_EQUAL_PTR(a + sz, found);
}*/

void test_algorithm_equal_int() {
    //Setting basic arrays
    int a[] = {10, 20, 30};
    int sz = sizeof a / sizeof(int);
    int b[] = {10, 20, 50};
    int res;

    //Compare [a, a + sz -1) for both arrays
    algorithm_equal(int*, a, a + sz - 1, b, res);
    TEST_ASSERT_TRUE(res);

    //Compare [a, a + sz) for both arrays
    algorithm_equal(int*, a, a + sz, b, res);
    TEST_ASSERT_FALSE(res);
}
