#include "../include/cstl/cstring.h"
#include <string.h>

void safestrcpy(char* dest, const char* src, size_t lim) {
    while(--lim && (*dest++ = *src++))
        ;
}

char* fstrcat(char* dest, const char* src) {
    while(*dest) {
        ++dest;
    }
    for(; *dest = *src; ++dest, ++src)
        ;
    return dest;
}

char* sfstrcat(char* dest, const char* src, size_t lim) {
    while(*dest) {
        ++dest;
    }
    for(; --lim && (*dest = *src); ++dest, ++src)
        ;
    return dest;
}

char* cstring_create(const char* s) {
    char* st = CSTL_MALLOC(strlen(s) + 1);
    strcpy(st, s);
    return st;
}

char* cstring_asn(char* s1, const char* s2) {
    CSTL_FREE(s1);
    if(s2) {
        return cstring_create_cstr(s2);
    }
}

void cstring_destroy(char* s) {
    CSTL_FREE(s);
}
