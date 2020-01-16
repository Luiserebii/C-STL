#include <stdio.h>
#include <string.h>

#include "../../include/algorithm.h"
#include "../include/test-algorithm.h"
#include "../lib/unity.h"

void setUp() {}
void tearDown() {}
void test_algorithm_find_int();
void test_algorithm_find_char();
void test_algorithm_equal_int();
void test_algorithm_equal_char();
void test_algorithm_max();
void test_algorithm_min();
void test_algorithm_count_int();
void test_algorithm_count_char();
void test_algorithm_transform_int();
void test_algorithm_accumulate_int();
void test_algorithm_accumulate_double();

int main() {

    UNITY_BEGIN();
    RUN_TEST(test_algorithm_copy_int);
    RUN_TEST(test_algorithm_copy_char);
    RUN_TEST(test_algorithm_copy_struct);
    RUN_TEST(test_algorithm_find_int);
    RUN_TEST(test_algorithm_find_char);
    RUN_TEST(test_algorithm_equal_int);
    RUN_TEST(test_algorithm_equal_char);
    RUN_TEST(test_algorithm_max);
    RUN_TEST(test_algorithm_min);
    RUN_TEST(test_algorithm_count_int);
    RUN_TEST(test_algorithm_count_char);
    RUN_TEST(test_algorithm_transform_int);
    RUN_TEST(test_algorithm_accumulate_int);
    RUN_TEST(test_algorithm_accumulate_double);
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

void test_algorithm_equal_int() {
    //Setting basic arrays
    int a[] = {10, 20, 30};
    int sz = sizeof a / sizeof(int);
    int b[] = {10, 20, 50};
    int res;

    //Compare [a, a + sz -1) for both arrays
    int* e1 = a + sz - 1;
    algorithm_equal(int*, a, e1, b, res);
    TEST_ASSERT_TRUE(res);

    //Compare [a, a + sz) for both arrays
    int* e2 = a + sz;
    algorithm_equal(int*, a, e2, b, res);
    TEST_ASSERT_FALSE(res);
}

void test_algorithm_equal_char() {
    //Setting basic arrays
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int sz = sizeof a / sizeof(char);
    char b[] = {'a', 'b', 'c', 'd', 'q'};
    int res;

    //Compare [a, a + sz - 2) for both arrays
    char* e1 = a + sz - 2;
    algorithm_equal(char*, a, e1, b, res);
    TEST_ASSERT_TRUE(res);

    //Compare [a, a + sz - 1) for both arrays
    char* e2 = a + sz - 1;
    algorithm_equal(char*, a, e2, b, res);
    TEST_ASSERT_FALSE(res);
}

void test_algorithm_max() {
    //Testing max on int
    int a = algorithm_max(1, 2);
    int b = algorithm_max(15, 0);
    int c = algorithm_max(100, 100);

    //Asserting max on int
    TEST_ASSERT_EQUAL_INT(2, a);
    TEST_ASSERT_EQUAL_INT(15, b);
    TEST_ASSERT_EQUAL_INT(100, c);

    //Testin max on char
    char d = algorithm_max('a', 'b');
    char e = algorithm_max('e', 'c');
    char f = algorithm_max('z', 'z');

    //Asserting max on char
    TEST_ASSERT_EQUAL_CHAR('b', d);
    TEST_ASSERT_EQUAL_CHAR('e', e);
    TEST_ASSERT_EQUAL_CHAR('z', f);
}

void test_algorithm_min() {
    //Testing max on int
    int a = algorithm_min(1, 2);
    int b = algorithm_min(15, 0);
    int c = algorithm_min(100, 100);

    //Asserting max on int
    TEST_ASSERT_EQUAL_INT(1, a);
    TEST_ASSERT_EQUAL_INT(0, b);
    TEST_ASSERT_EQUAL_INT(100, c);

    //Testin max on char
    char d = algorithm_min('a', 'b');
    char e = algorithm_min('e', 'c');
    char f = algorithm_min('z', 'z');

    //Asserting max on char
    TEST_ASSERT_EQUAL_CHAR('a', d);
    TEST_ASSERT_EQUAL_CHAR('c', e);
    TEST_ASSERT_EQUAL_CHAR('z', f);
}

void test_algorithm_count_int() {
    //Basic setup
    int a[] = {1, 2, 1, 2, 1};
    int sz = sizeof a / sizeof(int);
    int count;

    //Attempt count of 1
    algorithm_count(int*, a, a + sz, 1, count);
    TEST_ASSERT_EQUAL_INT(3, count);

    //Attempt count of non-existing
    algorithm_count(int*, a, a + sz, 0, count);
    TEST_ASSERT_EQUAL_INT(0, count);
}

void test_algorithm_count_char() {
    //Basic setup
    char a[] = {'a', 'b', 'c', 'd', 'a', 'd', 'c'};
    int sz = sizeof a / sizeof(char);
    int count;

    //Attempt count of c
    algorithm_count(char*, a, a + sz, 'c', count);
    TEST_ASSERT_EQUAL_INT(2, count);

    //Attempt count of non-existing
    algorithm_count(char*, a, a + sz, 'z', count);
    TEST_ASSERT_EQUAL_INT(0, count);
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

int doubleInt(int x) {
    return x * 2;
}
