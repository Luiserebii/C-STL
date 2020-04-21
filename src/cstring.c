#include "../include/cstl/cstring.h"

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
