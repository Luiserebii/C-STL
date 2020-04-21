#ifndef CSTL_CSTRING_H
#define CSTL_CSTRING_H

#include <string.h>

/**
 * Guarantees copying lim-1 chars to the destination string, reserving at least
 * one for a null character ('\0'). Strings copied are thus guaranteed to be
 * null-terminated, and provides safety by truncating silently.
 */
void safestrcpy(char* dest, const char* src, size_t lim);

/**
 * Guarantees concatenating as many characters as possible from src to dest.
 * This is intended to act as a convenience macro, to mimic safestrcpy's usage.
 */
#define safestrcat(dest, src, dest_lim) strncat(dest, src, dest_lim - strlen(dest) - 1)

/**
 * fstrcat, as in, "fast" strcat.
 * Returns a pointer to the last element, to try to alleviate future O(n) calls.
 */
char* fstrcat(char* dest, const char* src);

/**
 * sfstrcat, as in, "safe-fast" strcat.
 * Guarantees concatenating as many characters as possible from src to dest.
 * Returns a pointer to the last element, to try to alleviate future O(n) calls.
 */
char* sfstrcat(char* dest, const char* src, size_t lim);

/**
 * String OO-like functions
 */


/**
 * Options for supplanting a user-defined malloc/realloc equivalent for vectors.
 */
#ifndef CSTL_MALLOC
#define CSTL_MALLOC malloc
#endif

#ifndef CSTL_REALLOC
#define CSTL_REALLOC realloc
#endif

#ifndef CSTL_FREE
#define CSTL_FREE free
#endif

/**
 * Create a new c-string.
 */
char* cstring_create(void);

/**
 * Create a new c-string, and set it to the contents of c-string s.
 */
char* cstring_create_cstr(const char* s);

/**
 * Assign an initialized c-string s1 to a new c-string s2.
 * This will cause a deallocation, if s1 already has been filled.
 */
char* cstring_asn(char* s1, const char* s2);

/**
 * Destroys and releases the memory for a c-string.
 */
void cstring_destroy(char* s);

#endif
