#include <ctype.h>

#include <cstl/algorithm.h>
#include "../../include/algorithm/test-algorithm-partition.h"
#include "../../lib/unity.h"

int _tap_isEven(int x);

void test_algorithm_partition_int() {
    //Setting up initial array
    int a1[] = {1, 2, 3, 4, 5, 6};
    const int sz = sizeof a1 / sizeof(int);

    //Attempt partition with isEven
    int* partEnd;
    algorithm_partition(int*, a1, a1 + sz, int, _tap_isEven, partEnd);

    //Assert that all items in the range [begin, partEnd) are even
    int* res;
    algorithm_find_if(a1, partEnd, _tap_isEven, res);
    TEST_ASSERT_EQUAL_PTR(partEnd, res);
}

void test_algorithm_partition_char() {
    //Setting up initial array
    char a1[] = {'A', 'b', 'C', 'd', 'E', 'f'};
    const int sz = sizeof a1 / sizeof(char);

    //Attempt partition with isLower
    char* partEnd;
    algorithm_partition(char*, a1, a1 + sz, char, islower, partEnd);

    //Assert that all items in the range [begin, partEnd) are lowercase
    char* res;
    algorithm_find_if(a1, partEnd, islower, res);
    TEST_ASSERT_EQUAL_PTR(partEnd, res);
}

int _tap_isEven(int x) {
    return !(x & 1);
}
