# C-STL
![GitHub](https://img.shields.io/github/license/Luiserebii/C-STL?color=red)
[![CircleCI](https://circleci.com/gh/Luiserebii/C-STL.svg?style=svg)](https://circleci.com/gh/Luiserebii/C-STL)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/d864f79a239d487a97c5ed0144b9a51b)](https://www.codacy.com/manual/Luiserebii/C-STL?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Luiserebii/C-STL&amp;utm_campaign=Badge_Grade)

Implementation of the C++ Standard Library in C. Can creatures armed without wings engage in flight?

## Implementations

### \<algorithm\>

Functions from the `<algorithm>` header are currently being implemented as macros, often requiring an explicit passing of the type being used. For more, check out [algorithm.h](https://github.com/Luiserebii/C-STL/blob/master/include/algorithm.h).

### \<vector\>

Emulating the C++ `<vector>` in C is difficult, but macros allow us some room to play. Two macros, `declare_vector` and `define_vector`, allow us to explicitly provide a type (much like a template) and construct the rest according to our needs.

Since the declaration of the vector `struct` data type and associated functions should ideally belong in a header file, it is advised to use the `declare_vector` within one, and use `define_vector` in a matching `.c` file. For example, to create an `int` vector, one might write:

```c
/* vector_int.h */
#ifndef VECTOR_INT_H
#define VECTOR_INT_H

#include "vector.h"

declare_vector(int)

#endif
```
```c
/* vector_int.c */
#include "vector_int.h"
#include "vector.h"

define_vector(int)
```

This will then expand into the appropriate vector `struct` (e.g. `vector_int`) with matching functions. All functions are appended with the type, with the general format `vector_FUNCTION_TYPE`. Therefore, to `push_back` on an `int` vector, one would call `vector_push_back_int`.

As `vector` relies on dynamically-allocated memory via `malloc`, a convenience function `vector_free_TYPE` has been provided to release a vector after it has finished being used.

Further documentation on the currently implemented functions can be found in [vector.h](https://github.com/Luiserebii/C-STL/blob/master/include/vector.h).

## Testing
The [`test/`](test) directory contains tests which intend to exercise typical usage. To run all tests, simply use the command `make test`, which also includes diagnostic information from valgrind to ensure resources are being freed properly. The simple test framework [Unity](https://github.com/ThrowTheSwitch/Unity) is currently being used to write them.

## License
This code has been licensed under the GNU General Public License v3.0.
