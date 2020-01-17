#include <ctype.h>

#include "../../../include/algorithm.h"
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
/*    const char a1[] = {'A', 'b', 'C', 'd', 'E', 'f'};
    const int sz = sizeof a1 / sizeof(char);

    //Attempt remove_copy_if with islower
    algorithm_remove_copy_if(char*, a1, a1 + sz, a2, islower);
    const char expres[] = {'A', 'C', 'E'};
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expres, a2, sizeof expres / sizeof(char));
*/}

int _tap_isEven(int x) {
    return !(x & 1);
}
