#include "../../include/algorithm/test-algorithm-find.h"
#include <cstl/algorithm.h>
#include "../../lib/unity.h"

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
