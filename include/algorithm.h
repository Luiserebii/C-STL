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
#define algorithm_copy(type, begin, end, dest) \
    { \
        type alg_copy_it = begin; \
        for(type alg_copy_dest = dest; alg_copy_it != end; *alg_copy_dest++ = *alg_copy_it++) \
            ;   \
    } \


#endif
