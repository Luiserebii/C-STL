#include "../../include/algorithm/test-algorithm-max.h"
#include <cstl/algorithm.h>
#include "../../lib/unity.h"

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
