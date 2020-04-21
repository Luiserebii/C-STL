#include "../../include/string/test-string.h"
#include "../../lib/unity.h"

#include <cstl/string.h>
#include <string.h>

void setUp() {}
void tearDown() {}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_string_init);
    RUN_TEST(test_string_asn_cstr);
    RUN_TEST(test_string_cat);
    RUN_TEST(test_string_cmp);
    RUN_TEST(test_string_cat_cstr);
    RUN_TEST(test_string_cmp_cstr);
    RUN_TEST(test_string_cat_cstr);
    RUN_TEST(test_string_cstr);
    return UNITY_END();
}

void test_string_init() {
    const char* cstr = "Hello";
    const size_t sz = 5;
    string s;
    string_init_cstr(&s, cstr);

    //Assert the string's contents and size
    TEST_ASSERT_EQUAL_CHAR_ARRAY(cstr, string_begin(&s), sz);
    TEST_ASSERT_EQUAL_INT(sz, string_size(&s));

    string_deinit(&s);
}

void test_string_asn_cstr() {
    string s;
    string_init(&s);

    //Test setting a c-string to an empty string
    const char* cstr = "Hello";
    const size_t sz = 5;
    string_asn_cstr(&s, cstr);

    TEST_ASSERT_EQUAL_CHAR_ARRAY(cstr, string_begin(&s), sz);
    TEST_ASSERT_EQUAL_INT(sz, string_size(&s));

    //Test setting a larger c-string to a string with contents
    const char* cstr2 = "I am a giraffe";
    const size_t sz2 = 14;
    string_asn_cstr(&s, cstr2);

    TEST_ASSERT_EQUAL_CHAR_ARRAY(cstr2, string_begin(&s), sz2);
    TEST_ASSERT_EQUAL_INT(sz2, string_size(&s));

    //Test setting a smaller c-string to a string with contents
    const char* cstr3 = "meme";
    const size_t sz3 = 4;
    string_asn_cstr(&s, cstr3);

    TEST_ASSERT_EQUAL_CHAR_ARRAY(cstr3, string_begin(&s), sz3);
    TEST_ASSERT_EQUAL_INT(sz3, string_size(&s));

    string_deinit(&s);
}

void test_string_cat() {
    string s;
    string_init(&s);

    //Test concatenating a string to an empty string
    string str1;
    string_init_cstr(&str1, "Hello");
    size_t sz1 = 5;

    string_cat(&s, &str1);

    TEST_ASSERT_EQUAL_CHAR_ARRAY(string_begin(&str1), string_begin(&s), sz1);
    TEST_ASSERT_EQUAL_INT(sz1, string_size(&s));

    //Test concatenating a string to a string with content
    string str2;
    string_init_cstr(&str2, " world");
    size_t sz2 = 6;

    string_cat(&s, &str2);

    const char exp[] = "Hello world";
    TEST_ASSERT_EQUAL_CHAR_ARRAY(exp, string_begin(&s), sz1 + sz2);
    TEST_ASSERT_EQUAL_INT(sz1 + sz2, string_size(&s));

    string_deinit(&s);
    string_deinit(&str1);
    string_deinit(&str2);
}

void test_string_cmp() {
    string s1, s2;
    string_init(&s1), string_init(&s2);

    //Test comparing two empty strings to each other
    TEST_ASSERT_EQUAL_INT(0, string_cmp(&s1, &s2));

    //Test comparing an empty string to one with content
    string_asn_cstr(&s2, "banana");
    TEST_ASSERT_EQUAL_INT(-1, string_cmp(&s1, &s2));
    TEST_ASSERT_EQUAL_INT(1, string_cmp(&s2, &s1));

    //Test comparing two filled strings, where s1 < s2
    string_asn_cstr(&s1, "apple");
    TEST_ASSERT_EQUAL_INT(-1, string_cmp(&s1, &s2));

    //Test comparing two filled strings, where s1 > s2
    TEST_ASSERT_EQUAL_INT(1, string_cmp(&s2, &s1));

    //Test comparing two equal strings
    string_asn_cstr(&s2, "apple");
    TEST_ASSERT_EQUAL_INT(0, string_cmp(&s1, &s2));

    string_deinit(&s1);
    string_deinit(&s2);
}

void test_string_cat_cstr() {
    string s;
    string_init(&s);

    //Test concatenating an empty c-string to an empty string
    string_cat_cstr(&s, "");
    TEST_ASSERT_EQUAL_INT(0, string_size(&s));

    //Test concatenating a filled c-string to an empty string
    const char cs[] = "apple";
    const size_t sz1 = 5;
    string_cat_cstr(&s, cs);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(cs, string_begin(&s), sz1);
    TEST_ASSERT_EQUAL_INT(sz1, string_size(&s));

    //Test concatenating a filled string with an empty c-string
    string_cat_cstr(&s, "");
    TEST_ASSERT_EQUAL_CHAR_ARRAY(cs, string_begin(&s), sz1);
    TEST_ASSERT_EQUAL_INT(sz1, string_size(&s));

    //Test concatentating a filled c-string to a filled string
    const char cs2[] = "banana";
    const size_t sz2 = 6;
    string_cat_cstr(&s, cs2);
    const char exp[] = "applebanana";
    TEST_ASSERT_EQUAL_CHAR_ARRAY(exp, string_begin(&s), sz1 + sz2);
    TEST_ASSERT_EQUAL_INT(sz1 + sz2, string_size(&s));

    string_deinit(&s);
}

void test_string_cmp_cstr() {
    string s1;
    string_init(&s1);

    //Test comparing an empty string and empty c-string to each other
    TEST_ASSERT_EQUAL_INT(0, string_cmp_cstr(&s1, ""));

    //Test comparing an empty string to a c-string with content
    TEST_ASSERT_EQUAL_INT(-1, string_cmp_cstr(&s1, "banana"));

    //Test comparing an filled string, to an empty c-string
    string_asn_cstr(&s1, "banana");
    TEST_ASSERT_EQUAL_INT(1, string_cmp_cstr(&s1, ""));

    //Test comparing a filled string and c-string, where s1 < s2
    TEST_ASSERT_EQUAL_INT(-13, string_cmp_cstr(&s1, "orange"));

    //Test comparing two filled strings, where s1 > s2
    TEST_ASSERT_EQUAL_INT(1, string_cmp_cstr(&s1, "apple"));

    //Test comparing two equal strings
    TEST_ASSERT_EQUAL_INT(0, string_cmp_cstr(&s1, "banana"));

    string_deinit(&s1);
}

void test_string_cstr() {
    //Test obtaining a c-string from an empty string and consuming it
    string s;
    string_init(&s);
    char buf[1000] = "Meme";
    size_t sz = 4;

    strcat(buf, string_cstr(&s));

    TEST_ASSERT_EQUAL_CHAR_ARRAY("Meme", buf, sz);
    TEST_ASSERT_EQUAL_INT(sz, strlen(buf));

    //Test obtaining a c-string from a string with contents and consuming it
    string name;
    string_init_cstr(&name, ": OwO");
    size_t sz_n = 5;

    strcat(buf, string_cstr(&name));

    TEST_ASSERT_EQUAL_CHAR_ARRAY("Meme: OwO", buf, sz + sz_n);
    TEST_ASSERT_EQUAL_INT(sz + sz_n, strlen(buf));

    string_deinit(&s);
    string_deinit(&name);
}
