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

void test_string_set_cstr() {
    string s = string_init();
    
    //Test setting a c-string to an empty string
    const char* cstr = "Hello";
    const size_t sz = 5;
    string_set_cstr(s, cstr);

    TEST_ASSERT_EQUAL_CHAR_ARRAY(cstr, s->head, sz);
    TEST_ASSERT_EQUAL_INT(sz, string_size(s));

    //Test setting a larger c-string to a string with contents
    const char* cstr2 = "I am a giraffe";
    const size_t sz2 = 14;
    string_set_cstr(s, cstr2);

    TEST_ASSERT_EQUAL_CHAR_ARRAY(cstr2, s->head, sz2);
    TEST_ASSERT_EQUAL_INT(sz2, string_size(s));

    //Test setting a smaller c-string to a string with contents
    const char* cstr3 = "meme";
    const size_t sz3 = 4;
    string_set_cstr(s, cstr3);

    TEST_ASSERT_EQUAL_CHAR_ARRAY(cstr3, s->head, sz3);
    TEST_ASSERT_EQUAL_INT(sz3, string_size(s));

    string_free(s);
}

void test_string_cat() {
    string s = string_init();

    //Test concatenating a string to an empty string
    string str1 = string_init_cstr("Hello");
    size_t sz1 = 5;

    string_cat(s, str1);

    TEST_ASSERT_EQUAL_CHAR_ARRAY(str1->head, s->head, sz1);
    TEST_ASSERT_EQUAL_INT(sz1, string_size(s));

    //Test concatenating a string to a string with content
    string str2 = string_init_cstr(" world");
    size_t sz2 = 6;

    string_cat(s, str2);
   
    const char[] exp = "Hello world";  
    TEST_ASSERT_EQUAL_CHAR_ARRAY(exp, s->head, sz1 + sz2);
    TEST_ASSERT_EQUAL_INT(sz1 + sz2, string_size(s));

    string_free(s);
    string_free(str1);
    string_free(str2);
}

void test_string_cstr() {

}
