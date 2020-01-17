#include <ctype.h>

#include "../../../include/algorithm.h"
#include "../../include/algorithm/test-algorithm-search.h"
#include "../../lib/unity.h"

void test_algorithm_search_int() {
    //Setting up initial array
    const int a1[] = {1, 2, 3, 4, 5, 6};
    const int sz1 = sizeof a1 / sizeof(int);
    const int a2[] = {3, 4, 5};
    const int sz2 = sizeof a2 / sizeof(int);

    //Attempt algorithm_search, looking for a2 in a1
    const int* res;
    algorithm_search(int*, a1, a1 + sz1, a2, a2 + sz2, res);
    TEST_ASSERT_EQUAL_PTR(a1 + 2, res);
    TEST_ASSERT_EQUAL_INT(a1[2], *res);

    //Attempt algorithm_search once more, looking for a1 in a2
    //This should "break" within and return the last
    algorithm_search(int*, a2, a2 + sz2, a1, a1 + sz1, res);
    TEST_ASSERT_EQUAL_PTR(a2 + sz2, res);
}

void test_algorithm_search_char() {}
