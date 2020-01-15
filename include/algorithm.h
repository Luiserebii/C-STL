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
        type _alg_copy_it = begin;                                                                \
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
#define algorithm_equal(type, begin, end, begin2, res)                               \
    {                                                                                \
        res = 1;                                                                     \
        type _alg_eq_b = begin;                                                      \
        for(type _alg_eq_b2 = begin2; _alg_eq_b != end; ++_alg_eq_b, ++_alg_eq_b2) { \
            if(*_alg_eq_b != *_alg_eq_b2) {                                          \
                res = 0;                                                             \
                break;                                                               \
            }                                                                        \
        }                                                                            \
    }

#endif
