#include "../../include/string/test-string.h"
#include "../../lib/unity.h"

void setUp() {}
void tearDown() {}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_string_init);
    RUN_TEST(test_string_set_cstr);
    RUN_TEST(test_string_cat);
    RUN_TEST(test_string_cstr);
    return UNITY_END();
}


void test_string_init() {
    const char* cstr = "Hello";
    const size_t sz = 5;
    string s = string_init_cstr(cstr);

    //Assert the string's contents and size
    TEST_ASSERT_EQUAL_CHAR_ARRAY(cstr, s->head, sz);
    TEST_ASSERT_EQUAL_INT(sz, string_size(s));

    string_free(s);
}
