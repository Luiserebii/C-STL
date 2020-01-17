#include "../../../include/algorithm.h"
#include "../../include/algorithm/test-algorithm-accumulate.h"
#include "../../include/algorithm/test-algorithm-copy.h"
#include "../../include/algorithm/test-algorithm-count.h"
#include "../../include/algorithm/test-algorithm-equal.h"
#include "../../include/algorithm/test-algorithm-find-if.h"
#include "../../include/algorithm/test-algorithm-find.h"
#include "../../include/algorithm/test-algorithm-max.h"
#include "../../include/algorithm/test-algorithm-min.h"
#include "../../include/algorithm/test-algorithm-remove-copy-if.h"
#include "../../include/algorithm/test-algorithm-search.h"
#include "../../include/algorithm/test-algorithm-transform.h"
#include "../../lib/unity.h"

void setUp() {}
void tearDown() {}

int main() {

    UNITY_BEGIN();

    /* algorithm_copy_int */
    RUN_TEST(test_algorithm_copy_int);
    RUN_TEST(test_algorithm_copy_char);
    RUN_TEST(test_algorithm_copy_struct);

    /* algorithm_find */
    RUN_TEST(test_algorithm_find_int);
    RUN_TEST(test_algorithm_find_char);

    /* algorithm_equal */
    RUN_TEST(test_algorithm_equal_int);
    RUN_TEST(test_algorithm_equal_char);

    /* algorithm_max/min */
    RUN_TEST(test_algorithm_max);
    RUN_TEST(test_algorithm_min);

    /* algorithm_count */
    RUN_TEST(test_algorithm_count_int);
    RUN_TEST(test_algorithm_count_char);

    /* algorithm_transform */
    RUN_TEST(test_algorithm_transform_int);
    RUN_TEST(test_algorithm_transform_char);

    /* algorithm_accumulate */
    RUN_TEST(test_algorithm_accumulate_int);
    RUN_TEST(test_algorithm_accumulate_double);

    /* algorithm_remove_copy_if */
    RUN_TEST(test_algorithm_remove_copy_if_int);
    RUN_TEST(test_algorithm_remove_copy_if_char);

    /* algorithm_search */
    RUN_TEST(test_algorithm_search_int);
    RUN_TEST(test_algorithm_search_char);

    /* algorithm_find_if */
    RUN_TEST(test_algorithm_find_if_int);
    RUN_TEST(test_algorithm_find_if_char);

    return UNITY_END();
}
