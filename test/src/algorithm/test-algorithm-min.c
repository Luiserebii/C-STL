#include "../../include/algorithm/test-algorithm-min.h"
#include <cstl/algorithm.h>
#include "../../lib/unity.h"

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
