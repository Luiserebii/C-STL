/**
 * vector.h of the C STL.
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

#ifndef VECTOR_H
#define VECTOR_H

#include <assert.h>
#include <stdlib.h>
#include "algorithm.h"

/**
 * MACRO: declare_vector_type(vector_type)
 *
 * Declares an entire set of vector declarations for a specific type.
 *
 * Ex: declare_vector_type(int)
 *
 * Whenever a vector is needed to be declared, this is probably what you want!
 **/
#define declare_vector_type(vector_type) declare_vector_class(vector_##vector_type, vector_type)

/**
 * MACRO: define_vector_type(vector_type)
 *
 * Defines an entire set of vector declarations for a specific type.
 *
 * Ex: define_vector_type(int)
 **/
#define define_vector_type(vector_type) define_vector_class(vector_##vector_type, vector_type)

/**
 * MACRO: declare_vector_class(name, vector_type)
 *
 * Declares an entire set of vector declarations for a specific classname,
 * uses the name both as a prefix and as the struct_name generated.
 *
 * Ex: declare_vector_type(string, char)
 *
 * Whenever a vector is needed to be declared, this is probably what you want!
 **/
#define declare_vector_class(name, vector_type) declare_vector(name##_, , name, vector_type)

/**
 * MACRO: define_vector_class(name, vector_type)
 *
 * Defines an entire set of vector declarations for a specific classname.
 *
 * Ex: define_vector_type(string, char)
 **/
#define define_vector_class(name, vector_type) define_vector(name##_, , name, vector_type)

/**
 * MACRO: declare_vector(prefix, suffix, struct_name, vector_type)
 *
 * Declares an entire set of vector declarations based on the arguments passed.
 * 
 * The prefix/suffix determines the text to place before or after each set of
 * vector functions available. For example, with a prefix of "string_", and no
 * suffix, the init function would generate as "string_init".
 *
 * struct_name determines the name of the data type used internally, and vector_type
 * specifies the type used within the vector.
 *
 * This is intended to allow for the most amount of control in generating
 * definitions for a vector-like object.
 *
 * Ex: declare_vector(vector_, _int, vector_int, int)
 *
 **/
#define declare_vector(prefix, suffix, struct_name, vector_type)                                         \
    typedef struct {                                                                                     \
        vector_type* head;                                                                               \
        vector_type* avail;                                                                              \
        vector_type* tail;                                                                               \
    } struct_name;                                                                                       \
                                                                                                         \
    /*                                                                                                   \
     * Initializes an empty vector within the vector* passed.                                            \
     *                                                                                                   \
     * Note that although this data structure is completely empty, and has                               \
     * no elements allocated, the struct itself is, so vector_free is necessary                          \
     * for cleanup afterwards.                                                                           \
     */                                                                                                  \
    struct_name* prefix##init##suffix(void);                                                             \
                                                                                                         \
    /*                                                                                                   \
     * Initializes an empty vector with the size passed.                                                 \
     * Memory will be allocated under the size given, so vector_free                                     \
     * is required.                                                                                      \
     */                                                                                                  \
    struct_name* prefix##init_size##suffix(size_t s);                                                    \
                                                                                                         \
    /*                                                                                                   \
     * Intiailizes an empty vector with the size passed.                                                 \
     * Unlike vector_init_size, this function will fill the capacity.                                    \
     */                                                                                                  \
    struct_name* prefix##init_capacity##suffix(size_t s);                                                \
                                                                                                         \
    /*                                                                                                   \
     * Intializes a new vector, and fills it with n elements, each with value val.                       \
     */                                                                                                  \
    struct_name* prefix##init_fill##suffix(size_t n, vector_type val);                                   \
                                                                                                         \
    /*                                                                                                   \
     * Initializes a new vector, and fills it with the range [first, last) passed.                       \
     */                                                                                                  \
    struct_name* prefix##init_range##suffix(vector_type* first, vector_type* last);                      \
                                                                                                         \
    /*                                                                                                   \
     * Creates a fresh copy of a vector. If the dest contains a pre-existing vector,                     \
     * it will not be freed, so please release if not empty.                                             \
     */                                                                                                  \
    struct_name* prefix##copy##suffix(const struct_name* src);                                           \
                                                                                                         \
    /*                                                                                                   \
     * Sets an element of the vector to the value passed.                                                \
     */                                                                                                  \
    void prefix##set##suffix(struct_name* v, size_t pos, vector_type val);                               \
                                                                                                         \
    /*                                                                                                   \
     * Pushes a new element onto the vector.                                                             \
     */                                                                                                  \
    void prefix##push_back##suffix(struct_name* v, vector_type e);                                       \
                                                                                                         \
    /*                                                                                                   \
     * Pushes a new element onto the vector, using the pointer e's value passed.                         \
     *                                                                                                   \
     * For complex data type vectors, this is more space-efficient than the copy                         \
     * performed by push_back.                                                                           \
     */                                                                                                  \
    void prefix##push_back_r##suffix(struct_name* v, const vector_type* e);                              \
                                                                                                         \
    /*                                                                                                   \
     * Inserts a new element before the pointer passed.                                                  \
     */                                                                                                  \
    void prefix##insert##suffix(struct_name* v, vector_type val);                                        \
                                                                                                         \
    /*                                                                                                   \
     * Inserts a new element before the pointer passed, using the pointer v's value passed.              \
     *                                                                                                   \
     * For complex data type vectors, this is more space-efficient than the copy                         \
     * performed by insert.                                                                              \
     */                                                                                                  \
    void prefix##insert_r##suffix(struct_name* v, const vector_type* val);                               \
                                                                                                         \
    /*                                                                                                   \
     * Inserts the range of values in [first, last), before the pointer passed.                          \
     */                                                                                                  \
    void prefix##insert_range##suffix(struct_name* v, const vector_type* begin, const vector_type* end); \
                                                                                                         \
    /*                                                                                                   \
     * Pops the last element off the vector.                                                             \
     *                                                                                                   \
     * NOTE: If the vector is empty, the vector will be left in an invalid state and will                \
     * likely produce undesired results. In other words, the behavior is undefined.                      \
     */                                                                                                  \
    void prefix##pop_back##suffix(struct_name* v);                                                       \
                                                                                                         \
    /*                                                                                                   \
     * Erases an element at the pointer passed from the vector. Returns a pointer to the                 \
     * new end of the vector.                                                                            \
     */                                                                                                  \
    vector_type* prefix##erase##suffix(struct_name* v, vector_type* pos);                                \
                                                                                                         \
    /*                                                                                                   \
     * Erases a range of elements [begin, end) from the vector. Returns a pointer to the                 \
     * new end of the vector.                                                                            \
     */                                                                                                  \
    vector_type* prefix##erase_range##suffix(struct_name* v, vector_type* begin, vector_type* end);      \
                                                                                                         \
    /*                                                                                                   \
     * Returns the first pointer in the vector's sequence.                                               \
     */                                                                                                  \
    vector_type* prefix##begin##suffix(struct_name* v);                                                  \
                                                                                                         \
    /*                                                                                                   \
     * Returns the last pointer in the vector's sequence.                                                \
     */                                                                                                  \
    vector_type* prefix##end##suffix(struct_name* v);                                                    \
                                                                                                         \
    /*                                                                                                   \
     * Returns the current size of the vector.                                                           \
     */                                                                                                  \
    size_t prefix##size##suffix(const struct_name* v);                                                   \
                                                                                                         \
    /*                                                                                                   \
     * Returns the current total capacity of the vector,                                                 \
     * which encompasses the total amount allocated.                                                     \
     */                                                                                                  \
    size_t prefix##capacity##suffix(const struct_name* v);                                               \
                                                                                                         \
    /*                                                                                                   \
     * Returns the element found at the specified location passed.                                       \
     */                                                                                                  \
    vector_type prefix##at##suffix(const struct_name* v, size_t n);                                      \
                                                                                                         \
    /*                                                                                                   \
     * Resizes the vector to n elements. If n is less than the current size of the vector, any           \
     * extra elements will be destroyed. Conversely, if n is greater, the capacity of the vector         \
     * will expand, and any pre-existing elements will be kept.                                          \
     *                                                                                                   \
     * This function causes a reallocation via realloc if more space is necessary.                       \
     */                                                                                                  \
    void prefix##resize##suffix(struct_name* v, size_t n);                                               \
                                                                                                         \
    /*                                                                                                   \
     * Resizes the vector by growing it to n elements. This function causes a reallocation               \
     * via realloc. It should not change the size of the vector, simply expanding the capacity.          \
     *                                                                                                   \
     * If the n is less than the current size of the vector, it will be left in an invalid state         \
     * and the behavior is undefined.                                                                    \
     */                                                                                                  \
    void prefix##grow##suffix(struct_name* v, size_t n);                                                 \
                                                                                                         \
    /*                                                                                                   \
     * Resizes the vector by shrinking it to n elements.                                                 \
     *                                                                                                   \
     * This function does not change the capacity of the vector, only size.                              \
     *                                                                                                   \
     * If the n is greater than the current size of the vector, it will be left                          \
     * in an invalid state and the behavior is undefined.                                                \
     */                                                                                                  \
    void prefix##shrink##suffix(struct_name* v, size_t n);                                               \
                                                                                                         \
    /*                                                                                                   \
     * Clears all elements allocated to the vector, but does not deallocate                              \
     * the vector itself.                                                                                \
     */                                                                                                  \
    void prefix##clear##suffix(struct_name* v);                                                          \
                                                                                                         \
    /*                                                                                                   \
     * Frees the resources allocated to the vector, including the vector itself.                         \
     */                                                                                                  \
    void prefix##free##suffix(struct_name* v);

/**
 * MACRO: define_vector(prefix, suffix, struct_name, vector_type)
 *
 * Generates an entire set of definitions for a vector based on parameters passed.
 *
 * Ex: define_vector(vector_, _int, vector_int, int)
 */
#define define_vector(prefix, suffix, struct_name, vector_type)                                      \
    /*                                                                                               \
     * Grows the vector by 2x, or 1 if empty.                                                        \
     */                                                                                              \
    static void prefix##autogrow##suffix(struct_name* v);                                            \
                                                                                                     \
    struct_name* prefix##init##suffix(void) {                                                        \
        /* Allocate memory for vector struct */                                                      \
        struct_name* v = (struct_name*) malloc(sizeof(struct_name));                                 \
        v->head = v->avail = v->tail = NULL;                                                         \
        return v;                                                                                    \
    }                                                                                                \
                                                                                                     \
    struct_name* prefix##init_size##suffix(size_t s) {                                               \
        struct_name* v = (struct_name*) malloc(sizeof(struct_name));                                 \
        v->head = (vector_type*) malloc(sizeof(vector_type) * s);                                    \
        v->tail = v->avail = v->head + s;                                                            \
        return v;                                                                                    \
    }                                                                                                \
                                                                                                     \
    struct_name* prefix##init_capacity##suffix(size_t s) {                                           \
        struct_name* v = (struct_name*) malloc(sizeof(struct_name));                                 \
        v->head = v->avail = (vector_type*) malloc(sizeof(vector_type) * s);                         \
        v->tail = v->head + s;                                                                       \
        return v;                                                                                    \
    }                                                                                                \
                                                                                                     \
    struct_name* prefix##init_fill##suffix(size_t n, vector_type val) {                              \
        struct_name* v = prefix##init_size##suffix(n);                                               \
        algorithm_fill(vector_type*, v->head, v->tail, val);                                         \
        return v;                                                                                    \
    }                                                                                                \
                                                                                                     \
    struct_name* prefix##init_range##suffix(vector_type* first, vector_type* last) {                 \
        struct_name* v = prefix##init_size##suffix(last - first);                                    \
        algorithm_min_copy(vector_type*, first, last, v->head);                                      \
        return v;                                                                                    \
    }                                                                                                \
                                                                                                     \
    struct_name* prefix##copy##suffix(const struct_name* src) {                                      \
        if(src->head == NULL) {                                                                      \
            return prefix##init##suffix();                                                           \
        }                                                                                            \
        /* Initialize a fresh vector using original's size */                                        \
        struct_name* copy = prefix##init_size##suffix(prefix##size##suffix(src));                    \
        /* Copy over values */                                                                       \
        algorithm_min_copy(vector_type*, src->head, src->avail, copy->head);                         \
        return copy;                                                                                 \
    }                                                                                                \
                                                                                                     \
    void prefix##set##suffix(struct_name* v, size_t pos, vector_type val) { v->head[pos] = val; }    \
                                                                                                     \
    void prefix##push_back##suffix(struct_name* v, vector_type e) {                                  \
        if(v->avail == v->tail) {                                                                    \
            prefix##autogrow##suffix(v);                                                             \
        }                                                                                            \
        *(v->avail++) = e;                                                                           \
    }                                                                                                \
                                                                                                     \
    void prefix##push_back_r##suffix(struct_name* v, const vector_type* e) {                         \
        if(v->avail == v->tail) {                                                                    \
            prefix##autogrow##suffix(v);                                                             \
        }                                                                                            \
        *(v->avail++) = *e;                                                                          \
    }                                                                                                \
                                                                                                     \
    void prefix##pop_back##suffix(struct_name* v) {                                                  \
        assert(prefix##size##suffix(v) != 0);                                                        \
        --v->avail;                                                                                  \
        return;                                                                                      \
    }                                                                                                \
                                                                                                     \
    vector_type* prefix##erase##suffix(struct_name* v, vector_type* pos) {                           \
        for(; pos + 1 != v->avail; ++pos) {                                                          \
            *pos = *(pos + 1);                                                                       \
        }                                                                                            \
        return --v->avail;                                                                           \
    }                                                                                                \
                                                                                                     \
    vector_type* prefix##erase_range##suffix(struct_name* v, vector_type* begin, vector_type* end) { \
        size_t diff = end - begin;                                                                   \
        for(; begin + diff != v->avail; ++begin) {                                                   \
            *begin = *(begin + diff);                                                                \
        }                                                                                            \
        return v->avail -= diff;                                                                     \
    }                                                                                                \
                                                                                                     \
    vector_type* prefix##begin##suffix(struct_name* v) { return v->head; }                           \
                                                                                                     \
    vector_type* prefix##end##suffix(struct_name* v) { return v->avail; }                            \
                                                                                                     \
    void prefix##autogrow##suffix(struct_name* v) {                                                  \
        size_t old_sz = prefix##size##suffix(v);                                                     \
        size_t n_size = v->head ? old_sz * 2 : 1;                                                    \
                                                                                                     \
        v->head = (vector_type*) realloc(v->head, sizeof(vector_type) * n_size);                     \
        v->avail = v->head + old_sz;                                                                 \
        v->tail = v->head + n_size;                                                                  \
    }                                                                                                \
                                                                                                     \
    size_t prefix##size##suffix(const struct_name* v) { return v->avail - v->head; }                 \
                                                                                                     \
    size_t prefix##capacity##suffix(const struct_name* v) { return v->tail - v->head; }              \
                                                                                                     \
    vector_type prefix##at##suffix(const struct_name* v, size_t n) { return *(v->head + n); }        \
                                                                                                     \
    void prefix##resize##suffix(struct_name* v, size_t n) {                                          \
        size_t old_sz = prefix##size##suffix(v);                                                     \
        if(n > old_sz) {                                                                             \
            v->head = (vector_type*) realloc(v->head, sizeof(vector_type) * n);                      \
            v->avail = v->head + old_sz;                                                             \
            v->tail = v->head + n;                                                                   \
        } else {                                                                                     \
            v->avail -= (old_sz - n);                                                                \
        }                                                                                            \
    }                                                                                                \
                                                                                                     \
    void prefix##grow##suffix(struct_name* v, size_t n) {                                            \
        size_t old_sz = prefix##size##suffix(v);                                                     \
        assert(n > old_sz);                                                                          \
        /* Realloc and set pointers as appropriate */                                                \
        v->head = (vector_type*) realloc(v->head, sizeof(vector_type) * n);                          \
        v->avail = v->head + old_sz;                                                                 \
        v->tail = v->head + n;                                                                       \
    }                                                                                                \
                                                                                                     \
    void prefix##shrink##suffix(struct_name* v, size_t n) {                                          \
        assert(n < prefix##size##suffix(v));                                                         \
        v->avail -= (prefix##size##suffix(v) - n);                                                   \
    }                                                                                                \
                                                                                                     \
    void prefix##clear##suffix(struct_name* v) {                                                     \
        free(v->head);                                                                               \
        v->head = v->avail = v->tail = NULL;                                                         \
    }                                                                                                \
                                                                                                     \
    void prefix##free##suffix(struct_name* v) {                                                      \
        free(v->head);                                                                               \
        free(v);                                                                                     \
    }

#endif
