#ifndef VECTOR_STRUCT_POINT_H
#define VECTOR_STRUCT_POINT_H

#include <cstl/vector.h>

typedef struct {
    char* name;
    int x;
    int y;
} point;

declare_vector_type(point)

#endif
