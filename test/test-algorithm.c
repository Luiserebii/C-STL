#include <stdio.h>

#include "./lib/unity.h"
#include "../src/algorithm.h"

void array_print(int* arr, int n);
void test_algorithm_h();
void test_meme();

void setUp() { }
void tearDown() { }


int main() {

    UNITY_BEGIN();
    RUN_TEST(test_meme);
    return UNITY_END();
    
}

void test_meme() {
    TEST_ASSERT(1 == 1);
}

void test_algorithm_h() {
    //Testing algorithm.h
    int testArr[] = { 1, 2, 3 };
    int meme[sizeof testArr/sizeof(int)];
    array_print(testArr, 3);
    array_print(meme, 3);
    algorithm_copy(int*, testArr, testArr + 3, meme);
    array_print(meme, 3);
}

void array_print(int* arr, int n) {
    printf("Array:");
    while(n--) {
        printf(" %d", *arr++);
    }
    putchar('\n');
}
