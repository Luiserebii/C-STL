/**
 * algorithm.h of the C STL.
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

#ifndef ALGORITHM_H
#define ALGORITHM_H

/**
 * algorithm_copy(type, begin, end, dest)
 *
 * Takes a pointer type as the first parameter, which is to be substituted as a generic for the values
 * of begin and dest. Essentially, the range [begin, end) is copied into dest.
 *
 * Ex: algorithm_copy(int*, months, months + 12, words)
 */
#define algorithm_copy(type, begin, end, dest)                                                    \
    {                                                                                             \
        const type _alg_copy_it = begin;                                                          \
        for(type _alg_copy_dest = dest; _alg_copy_it != end; *_alg_copy_dest++ = *_alg_copy_it++) \
            ;                                                                                     \
    }

/**
 * algorithm_find(begin, end, val, res)
 *
 * Searches through [begin, end) for val. Returns a pointer to the found value through
 * res, or end if nothing found. 
 */
#define algorithm_find(begin, end, val, res) \
    {                                        \
        res = begin;                         \
        while(res != end && *res != val) {   \
            ++res;                           \
        }                                    \
    }

/**
 * algorithm_equal(type, begin, end, begin2, res)
 *
 * Searches and compares [begin, end) to [begin2, x), where x is end - begin. 
 * Returns a boolean value into res representing the equivalence of the range.
 */
#define algorithm_equal(type, begin, end, begin2, res)                                     \
    {                                                                                      \
        res = 1;                                                                           \
        const type _alg_eq_b = begin;                                                      \
        for(const type _alg_eq_b2 = begin2; _alg_eq_b != end; ++_alg_eq_b, ++_alg_eq_b2) { \
            if(*_alg_eq_b != *_alg_eq_b2) {                                                \
                res = 0;                                                                   \
                break;                                                                     \
            }                                                                              \
        }                                                                                  \
    }

/**
 * algorithm_max(a, b)
 *
 * Returns the greater of the two values by resolving into an expression.
 */
#define algorithm_max(a, b) (a > b) ? a : b

/**
 * algorithm_min(a, b)
 *
 * Returns the lesser of the two values by resolving into an expression.
 */
#define algorithm_min(a, b) (a < b) ? a : b

/**
 * algorithm_count(type, begin, end, val, res)
 *
 * Returns the number of times val appears in [begin, end) into res.
 */
#define algorithm_count(type, begin, end, val, res)                                    \
    {                                                                                  \
        res = 0;                                                                       \
        for(const type _alg_count_it = begin; _alg_count_it != end; ++_alg_count_it) { \
            if(*_alg_count_it == val) {                                                \
                ++res;                                                                 \
            }                                                                          \
        }                                                                              \
    }

/**
 * algorithm_transform(type, begin, end, dest, f)
 *
 * Apply the unary function f to the range [begin, end), storing the result
 * in a range [dest, end - begin).
 */
#define algorithm_transform(type, begin, end, dest, f) \
    {                                                  \
        const type _alg_tr_it = begin;                 \
        type _alg_tr_dest = dest;                      \
        while(_alg_tr_it != end) {                     \
            *_alg_tr_dest++ = f(*_alg_tr_it++);        \
        }                                              \
    }

/**
 * algorithm_accumulate(type, begin, end, res)
 *
 * Add all values found in the range [begin, end) and return in res.
 * 
 * Aside from storing the result of the computation, the initial value of res
 * will be used within the sum. Typically, res should therefore be 0.
 */
#define algorithm_accumulate(type, begin, end, res) \
    {                                               \
        const type _alg_acc_it = begin;             \
        while(_alg_acc_it != end) {                 \
            res += *_alg_acc_it++;                  \
        }                                           \
    }
/**
 * algorithm_remove_copy_if(type, begin, end, dest, f)
 *
 * Copies all values in the range [begin, end) to dest which
 * do not match the predicate f passed. 
 *
 * Alternatively, this function removes any elements which match
 * the predicate and places this new range in dest.
 *
 * Ex: algorithm_remove_copy_if(char*, a, a + sz, b, islower)
 */
#define algorithm_remove_copy_if(type, begin, end, dest, f) \
    { \
        const type _alg_cpif_it = begin; \
        type _alg_cpif_dest = dest; \
        while(_alg_cpif_it != end) { \
            if(!f(*_alg_cpif_it)) { \
                *_alg_cpif_dest++ = *_alg_cpif_it; \
            } \
            ++_alg_cpif_it; \
        } \
    }

/**
 * algorithm_search(type, begin, end, begin2, end2, res) 
 *
 *
 */
#define algorithm_search(type, begin, end, begin2, end2, res) \
    { \
        for(const type _alg_search_b1 = begin; _alg_search_b1 != end; ++_alg_search_b1) { \
            type _alg_search_it1 = begin; \
            type _alg_search_it2 = begin2; \
            while(*_alg_search_it1 == *_alg_search_it2) { \
                if(_alg_search_it2 == end2) { \
                    res = _alg_search_b1; \
                    goto _algorithm_search_end; \
                } \
                if(_alg_search_it1 == end) { \
                    res = end; \
                    goto _algorithm_search_end; \
                } \
                ++_alg_search_it1, ++_alg_search_it2; \
            } \
        } \
        res = end; \
        _algorithm_search_end: \
    }

/**
 * algorithm_find_if(begin, end, f, res)
 *
 * Searches through [begin, end) for the first element in which the
 * predicate f returns true. Returns a pointer to the found value through
 * res, or end if nothing found.
 */
#define algorithm_find_if(begin, end, f, res) \
    { \
        res = begin; \
        while(res != end && !f(*res)) {   \
            ++res;                           \
        }                                    \
    }

#endif
