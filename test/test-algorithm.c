#include <stdio.h>

#include "./lib/unity.h"
#include "../src/algorithm.h"

void test_algorithm_h();

void setUp() { }
void tearDown() { }

int main() {

    UNITY_BEGIN();
    RUN_TEST(test_algorithm_h);
    return UNITY_END();
    
}

void test_algorithm_h() {
    
    //Testing algorithm.h
    int testArr[] = { 1, 2, 3 };
    const int sz = sizeof testArr / sizeof(int);
    int meme[sz];

    //Attempt copying of testArr into meme
    TEST_ASSERT_FALSE_INT_ARRAY(testArr, meme, sz);
    algorithm_copy(int*, testArr, testArr + sz, meme);

    //Assert copied value
    TEST_ASSERT_EQUAL_INT_ARRAY(testArr, meme, sz);
}
