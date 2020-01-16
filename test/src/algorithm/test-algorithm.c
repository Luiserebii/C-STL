#include "../../../include/algorithm.h"
#include "../../include/algorithm/test-algorithm-accumulate.h"
#include "../../include/algorithm/test-algorithm-copy.h"
#include "../../include/algorithm/test-algorithm-count.h"
#include "../../include/algorithm/test-algorithm-equal.h"
#include "../../include/algorithm/test-algorithm-find.h"
#include "../../include/algorithm/test-algorithm-max.h"
#include "../../include/algorithm/test-algorithm-min.h"
#include "../../include/algorithm/test-algorithm-transform.h"
#include "../../lib/unity.h"

void setUp() {}
void tearDown() {}

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
    RUN_TEST(test_algorithm_transform_char);
    RUN_TEST(test_algorithm_accumulate_int);
    return UNITY_END();
}
