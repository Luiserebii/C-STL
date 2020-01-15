#include <stdio.h>
#include <string.h>

#include "./lib/unity.h"
#include "../src/algorithm.h"

void test_algorithm_copy_int();
void test_algorithm_copy_char();

void setUp() { }
void tearDown() { }

int main() {

    UNITY_BEGIN();
    RUN_TEST(test_algorithm_copy_int);
    RUN_TEST(test_algorithm_copy_char);
    return UNITY_END();

}

void test_algorithm_copy_int() {
    //Setting up basic array to copy over
    int a1[] = { 1, 2, 3 };
    const int sz = sizeof a1 / sizeof(int);
    int a2[sz];

    //Attempt copying of a1 into a2
    TEST_ASSERT(memcmp(a1, a2, sizeof a1) != 0);
    printf("MEMCMP: %d", memcmp(a1, a2, sizeof a1));
    algorithm_copy(int*, a1, a1 + sz, a2);

    //Assert copied values
    TEST_ASSERT_EQUAL_INT_ARRAY(a1, a2, sz);
    TEST_ASSERT(memcmp(a1, a2, sizeof a1) == 0);
    printf("MEMCMP: %d", memcmp(a1, a2, sizeof a1));
}

void test_algorithm_copy_char() {
    //Setting up basic array to copy over
    char a1[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    const int sz = sizeof a1 / sizeof(char);
    char a2[sz];

    //Attempt copying of a1 into a2
    TEST_ASSERT(memcmp(a1, a2, sizeof a1) != 0);
    printf("MEMCMP: %d", memcmp(a1, a2, sizeof a1));
    algorithm_copy(char*, a1, a1 + sz, a2);

    //Assert copied values
    TEST_ASSERT_EQUAL_CHAR_ARRAY(a1, a2, sz);
    TEST_ASSERT(memcmp(a1, a2, sizeof a1) == 0);
    printf("MEMCMP: %d", memcmp(a1, a2, sizeof a1));
}
