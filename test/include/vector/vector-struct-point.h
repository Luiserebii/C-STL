#ifndef VECTOR_STRUCT_POINT_H
#define VECTOR_STRUCT_POINT_H

#include "../../../include/vector.h"

typedef struct {
    char* name;
    int x;
    int y;
} point;

declare_vector(vector_, _point, vector_point, point)

#endif
