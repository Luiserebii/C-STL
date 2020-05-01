/**
 * string.c of the C STL.
 *
 * Copyright (C) 2020 Luiserebii
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "../include/cstl/string.h"
#include "../include/cstl/algorithm.h"
#include "../include/cstl/vector.h"

#include <string.h>

/**
 * Generate a set of vector functions for our string
 */

static void string_autogrow(string* v);
void string_init(string* v) {
    v->head = v->avail = v->tail = ((void*) 0);
}
void string_init_size(string* v, size_t s) {
    v->head = (char*) safemalloc(sizeof(char) * s + STRING_CAPACITY_EXTRA);
    v->tail = v->avail = v->head + s;
}
void string_init_capacity(string* v, size_t s) {
    v->head = v->avail = (char*) safemalloc(sizeof(char) * s + STRING_CAPACITY_EXTRA);
    v->tail = v->head + s;
}
void string_init_fill(string* v, size_t n, char val) {
    string_init_size(v, n);
    {
        for(char* _alg_copy_it = v->head; _alg_copy_it != v->tail; *_alg_copy_it++ = val)
            ;
    };
}
void string_init_range(string* v, const char* first, const char* last) {
    string_init_size(v, last - first);
    {
        const char* _alg_copy_it = first;
        for(char* _alg_copy_dest = v->head; _alg_copy_it != last; *_alg_copy_dest++ = *_alg_copy_it++)
            ;
    };
}
string* string_create(void) {
    string* v = (string*) safemalloc(sizeof(string));
    string_init(v);
    return v;
}
string* string_create_size(size_t s) {
    string* v = (string*) safemalloc(sizeof(string));
    string_init_size(v, s);
    return v;
}
string* string_create_capacity(size_t s) {
    string* v = (string*) safemalloc(sizeof(string));
    string_init_capacity(v, s);
    return v;
}
string* string_create_fill(size_t n, char val) {
    string* v = string_create_size(n);
    string_init_fill(v, n, val);
    return v;
}
string* string_create_range(const char* first, const char* last) {
    string* v = string_create_size(last - first);
    string_init_range(v, first, last);
    return v;
}
string* string_copy(const string* src) {
    if(src->head == ((void*) 0)) {
        return string_create();
    }
    string* copy = string_create_size(string_size(src));
    {
        const char* _alg_copy_it = src->head;
        for(char* _alg_copy_dest = copy->head; _alg_copy_it != src->avail; *_alg_copy_dest++ = *_alg_copy_it++)
            ;
    };
    return copy;
}
void string_asn(string* dest, const string* src) {
    string_assign(dest, string_begin(src), string_end(src));
}
void string_assign(string* v, const char* first, const char* last) {
    size_t sz = last - first;
    if(string_capacity(v) < sz) {
        v->head = (char*) saferealloc(v->head, sizeof(char) * sz + STRING_CAPACITY_EXTRA);
        v->tail = v->head + sz;
    }
    {
        const char* _alg_copy_it = first;
        for(char* _alg_copy_dest = v->head; _alg_copy_it != last; *_alg_copy_dest++ = *_alg_copy_it++)
            ;
    };
    v->avail = v->head + sz;
}
void string_set(string* v, size_t pos, char val) {
    v->head[pos] = val;
}
void string_push_back(string* v, char e) {
    if(v->avail == v->tail) {
        string_autogrow(v);
    }
    *(v->avail++) = e;
}
void string_push_back_r(string* v, const char* e) {
    if(v->avail == v->tail) {
        string_autogrow(v);
    }
    *(v->avail++) = *e;
}
void string_insert(string* v, char* p, char val) {
    size_t pos = p - v->head;
    if(v->avail == v->tail) {
        string_grow(v, string_capacity(v) + 1);
    }
    p = v->head + pos;
    char* it = v->avail;
    for(; it != p; --it) {
        *it = *(it - 1);
    }
    *p = val;
    ++v->avail;
}
void string_insert_r(string* v, char* p, const char* val) {
    size_t pos = p - v->head;
    if(v->avail == v->tail) {
        string_grow(v, string_capacity(v) + 1);
    }
    p = v->head + pos;
    char* it = v->avail;
    for(; it != p; --it) {
        *it = *(it - 1);
    }
    *p = *val;
    ++v->avail;
}
void string_insert_range(string* v, char* p, const char* begin, const char* end) {
    size_t pos = p - v->head;
    size_t sz = end - begin;
    if(v->avail == v->tail) {
        string_grow(v, string_capacity(v) + sz);
    }
    p = v->head + pos;
    char* it = v->avail;
    for(; it != p; --it) {
        *(it + sz - 1) = *(it - 1);
    }
    {
        const char* _alg_copy_it = begin;
        for(char* _alg_copy_dest = p; _alg_copy_it != end; *_alg_copy_dest++ = *_alg_copy_it++)
            ;
    };
    v->avail += sz;
}
void string_pop_back(string* v) {
    ((string_size(v) != 0)
         ? (void) (0)
         : __assert_fail("string_size(v) != 0", "/home/luiserebii/github/gitid/./src/cli.c", 71, __PRETTY_FUNCTION__));
    --v->avail;
    return;
}
char* string_erase(string* v, char* pos) {
    for(; pos + 1 != v->avail; ++pos) {
        *pos = *(pos + 1);
    }
    return --v->avail;
}
char* string_erase_range(string* v, char* begin, char* end) {
    size_t diff = end - begin;
    for(; begin + diff != v->avail; ++begin) {
        *begin = *(begin + diff);
    }
    return v->avail -= diff;
}
char* string_begin(const string* v) {
    return v->head;
}
char* string_end(const string* v) {
    return v->avail;
}
void string_autogrow(string* v) {
    size_t old_sz = string_size(v);
    size_t n_size = v->head ? old_sz * 2 : 1;
    v->head = (char*) saferealloc(v->head, sizeof(char) * n_size + STRING_CAPACITY_EXTRA);
    v->avail = v->head + old_sz;
    v->tail = v->head + n_size;
}
size_t string_size(const string* v) {
    return v->avail - v->head;
}
size_t string_capacity(const string* v) {
    return v->tail - v->head;
}
char string_at(const string* v, size_t n) {
    return *(v->head + n);
}
void string_resize(string* v, size_t n) {
    size_t old_sz = string_size(v);
    if(n > old_sz) {
        v->head = (char*) saferealloc(v->head, sizeof(char) * n + STRING_CAPACITY_EXTRA);
        v->avail = v->head + old_sz;
        v->tail = v->head + n;
    } else {
        v->avail -= (old_sz - n);
    }
}
void string_grow(string* v, size_t n) {
    size_t old_sz = string_size(v);
    ((n >= old_sz) ? (void) (0) : __assert_fail("n >= old_sz", "/home/luiserebii/github/gitid/./src/cli.c", 71,
                                                __PRETTY_FUNCTION__));
    v->head = (char*) saferealloc(v->head, sizeof(char) * n + STRING_CAPACITY_EXTRA);
    v->avail = v->head + old_sz;
    v->tail = v->head + n;
}
void string_shrink(string* v, size_t n) {
    ((n < string_size(v))
         ? (void) (0)
         : __assert_fail("n < string_size(v)", "/home/luiserebii/github/gitid/./src/cli.c", 71, __PRETTY_FUNCTION__));
    v->avail -= (string_size(v) - n);
}
void string_clear(string* v) {
    v->avail = v->head;
}
void string_deinit(string* v) {
    free(v->head);
}
void string_destroy(string* v) {
    string_deinit(v);
    free(v);
}

void string_init_cstr(string* str, const char* s) {
    size_t len = strlen(s);
    string_init_size(str, len);
    algorithm_min_copy(char*, s, s + len, str->head);
}

string* string_create_cstr(const char* s) {
    size_t len = strlen(s);
    string* str = string_create_size(len);
    algorithm_min_copy(char*, s, s + len, str->head);
    return str;
}

void string_cat(string* dest, const string* src) {
    string_insert_range(dest, dest->avail, src->head, src->avail);
}

void string_asn_cstr(string* str, const char* s) {
    const char* end = s;
    for(; *end != '\0'; ++end)
        ;
    string_assign(str, s, end);
}

void string_cat_cstr(string* str, const char* s) {
    const char* end = s;
    for(; *end != '\0'; ++end)
        ;
    string_insert_range(str, string_end(str), s, end);
}

int string_cmp_cstr(const string* s1, const char* s2) {
    const char* it1 = string_begin(s1);
    const char* end1 = string_end(s1);
    for(; it1 != end1 && *s2 != '\0'; ++it1, ++s2) {
        if(*it1 != *s2) {
            return *it1 - *s2;
        }
    }
    if(it1 == end1 && *s2 == '\0') {
        return 0;
    }
    if(it1 == end1) {
        return -1;
    }
    return 1;
}

int string_cmp(const string* s1, const string* s2) {
    const char* it1 = string_begin(s1);
    const char* it2 = string_begin(s2);
    const char* end1 = string_end(s1);
    const char* end2 = string_end(s2);
    for(; it1 != end1 && it2 != end2; ++it1, ++it2) {
        if(*it1 != *it2) {
            return *it1 - *it2;
        }
    }
    if(it1 == end1 && it2 == end2) {
        return 0;
    }
    if(it1 == end1) {
        return -1;
    }
    return 1;
}

const char* string_cstr(const string* str) {
    //Set a null-terminator at avail
    *(str->avail) = '\0';
    return str->head;
}
