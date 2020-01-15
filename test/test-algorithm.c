#include <stdio.h>
#include <string.h>

#include "./lib/unity.h"
#include "../src/algorithm.h"

struct point {
    int x;
    int y;
};

void test_algorithm_copy_int();
void test_algorithm_copy_char();
void test_algorithm_copy_struct();

void setUp() { }
void tearDown() { }

int main() {

    UNITY_BEGIN();
    RUN_TEST(test_algorithm_copy_int);
    RUN_TEST(test_algorithm_copy_char);
    RUN_TEST(test_algorithm_copy_struct);
    return UNITY_END();

}

void test_algorithm_copy_int() {
    //Setting up basic array to copy over
    int a1[] = { 1, 2, 3 };
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
    char a1[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
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
