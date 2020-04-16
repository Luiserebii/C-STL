#include <cstl/algorithm.h>
#include "../../include/algorithm/test-algorithm-accumulate.h"
#include "../../include/algorithm/test-algorithm-count.h"
#include "../../include/algorithm/test-algorithm-equal.h"
#include "../../include/algorithm/test-algorithm-find-if.h"
#include "../../include/algorithm/test-algorithm-find.h"
#include "../../include/algorithm/test-algorithm-max.h"
#include "../../include/algorithm/test-algorithm-min-copy.h"
#include "../../include/algorithm/test-algorithm-min.h"
#include "../../include/algorithm/test-algorithm-partition.h"
#include "../../include/algorithm/test-algorithm-remove-copy-if.h"
#include "../../include/algorithm/test-algorithm-remove-copy.h"
#include "../../include/algorithm/test-algorithm-remove-if.h"
#include "../../include/algorithm/test-algorithm-remove.h"
#include "../../include/algorithm/test-algorithm-search.h"
#include "../../include/algorithm/test-algorithm-transform.h"
#include "../../lib/unity.h"

void setUp() {}
void tearDown() {}

int main(void) {

    UNITY_BEGIN();

    /* algorithm_min_copy */
    RUN_TEST(test_algorithm_min_copy_int);
    RUN_TEST(test_algorithm_min_copy_char);
    RUN_TEST(test_algorithm_min_copy_struct);

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

    /* algorithm_remove */
    RUN_TEST(test_algorithm_remove_int);
    RUN_TEST(test_algorithm_remove_char);

    /* algorithm_remove_copy */
    RUN_TEST(test_algorithm_remove_copy_int);
    RUN_TEST(test_algorithm_remove_copy_char);

    /* algorithm_partition */
    RUN_TEST(test_algorithm_partition_int);
    RUN_TEST(test_algorithm_partition_char);

    /* algorithm_remove_if */
    RUN_TEST(test_algorithm_remove_if_int);
    RUN_TEST(test_algorithm_remove_if_char);

    return UNITY_END();
}
