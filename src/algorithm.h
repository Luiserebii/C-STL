#ifndef ALGORITHM_H
#define ALGORITHM_H

#define copy(type, begin, end, dest) \
    { \
        for(type *alg_copy_it = begin, *alg_copy_dest = dest; alg_copy_it != end; *alg_copy_dest++ = *alg_copy_it++) \
            ;   \
    } \


#endif
