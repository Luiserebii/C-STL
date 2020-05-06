# C-STL
![GitHub](https://img.shields.io/github/license/Luiserebii/C-STL?color=222)
[![CircleCI](https://circleci.com/gh/Luiserebii/C-STL.svg?style=svg)](https://circleci.com/gh/Luiserebii/C-STL)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/d864f79a239d487a97c5ed0144b9a51b)](https://www.codacy.com/manual/Luiserebii/C-STL?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Luiserebii/C-STL&amp;utm_campaign=Badge_Grade)

Implementation of the C++ Standard Library in C. Can creatures armed without wings engage in flight?

## Implementations

### \<algorithm\>

Functions from the `<algorithm>` header are currently being implemented as macros, often requiring an explicit passing of the type being used. 

Example usage, which removes all vowels from a string:
```c
#include <cstl/algorithm.h>
#include <cstl/string.h>
#include <stdio.h>
int isvowel(char c);

int main() {
    string* s = string_create_cstr("Hello world");
    char* last;
    algorithm_remove_if(char*, string_begin(s), string_end(s), isvowel, last);
    string_erase_range(s, last, string_end(s));
    printf("%s\n", string_cstr(s));
    string_destroy(s);
}

int isvowel(char c) {
    char vowels[] = {'a','e','i','o','u','A','E','I','O','U'};
    char* found;
    algorithm_find(vowels, vowels + sizeof(vowels), c, found);
    return found != (vowels + sizeof(vowels));
}
```

For more, check out [algorithm.h](./include/cstl/algorithm.h).

### \<vector\>

Emulating the C++ `<vector>` in C is difficult, but macros allow us some room to play. Two macros, `declare_vector_type` and `define_vector_type`, allow us to explicitly provide a type (much like a template) and construct the rest according to our needs. These are built on `declare_vector` and `define_vector`, which allow more flexibility and power with the naming of containers and functions.

Since the declaration of the vector `struct` data type and associated functions should ideally belong in a header file, it is advised to use the `declare_vector` within one, and use `define_vector` in a matching `.c` file. For example, to create an `int` vector, one might write:

```c
/**
 * vector_int.h 
 */
#ifndef VECTOR_INT_H
#define VECTOR_INT_H

#include <cstl/vector.h>

declare_vector_type(int)

#endif
```
```c
/**
 * vector_int.c
 */
#include "vector_int.h"
#include <cstl/vector.h>

define_vector_type(int)
```

This will then expand into the appropriate vector `struct` (e.g. `vector_int`) with matching functions. All functions are appended with the type, with the general format `vector_`**[TYPE]**`_`**[FUNCTION]**. Therefore, to `push_back` on an `int` vector, one would call `vector_int_push_back`.

As `vector` relies on dynamically-allocated memory via `malloc`, a set of functions are used to allocate and release a vector after it has finished being used. To supplant a user-defined `malloc`, one can define the `CSTL_CUSTOM_MEMORY` macro and pass it in to the compiler, and implement the following functions: `cstl_malloc`, `cstl_realloc`, and `cstl_free`. To understand why this works, there is essentially a kind of conditional compilation going on. These functions are defined internally within a source file **only if** `CSTL_CUSTOM_MACRO` is not defined. Therefore, defining the macro frees up the implementation, allowing the user to supplant one easily. Through gcc, this might be done as `cc -DCSTL_CUSTOM_MACRO ...`. 

To sum up, here is some example usage with the declared `vector_int` above:
```c
#include "vector_int.h"

int main() {
    //Initializing a new vector
    vector_int v;
    vector_int_init(&v);

    //Inserting 5 of the first elements from an array
    int a[] = {10, 20, 30, 40, 50};
    vector_int_insert_range(&v, vector_int_begin(&v), a, a + (sizeof(a) / sizeof(a[0])));

    //Printing vector contents to the console
    for(int* it = vector_int_begin(&v); it != vector_int_end(&v); ++it) {
        printf("%d\n", *it);
    }

    vector_int_deinit(&v);
}
```
Further documentation on the currently implemented functions can be found in [vector.h](./cstl/include/vector.h).

### \<string\>

The flexible, dynamically-allocated C++ `std::string` is emulated by expanding on the vector macro, and adding additional functions useful for interaction with C-strings. All functions available to vectors are equally available to the C-STL string type (e.g. `string_push_back(char c)`). Information on the additional functions can be found in [string.h](./include/cstl/string.h).

Example usage:
```c
#include <cstl/string.h>

int main() {
    //Initializing our string to a C-string
    string s;
    string_init_cstr(&s, "Hello world");

    //Setting our string to a new C-string
    string_asn_cstr(&s, "I need a string that can expand!");

    //And concatenating it with a C-string
    string_cat_cstr(&s, " And concatenate, too!");

    //Exporting our string as a C-string
    printf("%s", string_cstr(&s));

    string_deinit(&s);
}
```

## Useful C Additions

Alongside constructs which exist in the C++ STL and standard library, some functions have been written to better interact with "native" C constructs (such as C-strings).

### \<cstring\>

This module offers an interface to easily reason through heap-allocated C-strings, which may be struct members. The functions ensure that an initialized C-string is either `NULL` or a `char*` to a valid null-terminated string. In this paradigm, testing if a string is empty/non-existent is as easy as testing the pointer itself, and no unnecessary memory has to be allocated to simply represent an empty C-string. This works particularly well, as `NULL` is a valid argument for `free()`. 

The only minor cost is a branch in C-string assignment (`cstring_asn`), in order to accept a valid, intialized string (which may be `NULL`). The reasoning behind this is to allow implementing the assignment of a struct to another struct easily; since it is possible for the string to be `NULL`, we don't want `cstring_asn` to break assuming the value is allocated.

Example usage:
```c
#include <cstl/cstring.h>

int main() {
    //Initializing a C-string
    char* s;
    cstring_init(s);

    //Assigning it a value
    cstring_asn(s, "A new value!");

    //Printing it as we usually would
    printf("%s", s);
    
    cstring_destroy(s);
}
```

A small set of functions are also avaliable within this header, which are much more useful globally. `safestrcpy` and `safestrcat` allow specifying a limit to protect from overwriting buffers, where `lim - 1` characters are copied max.

Example usage:
```c
#include <cstl/cstring.h>
#define BUF_MAX 8
char buf[BUF_MAX];

int main() {
    char s[] = "I can't not easily overrun the buffer above";
    
    //Perform a safestrcpy to prevent it!
    safestrcpy(buf, s, BUF_MAX);

    //Let's check to see if our buffer is safe: (prints "I can't")
    puts(buf);
}
```

More can be found in [cstring.h](./include/cstl/cstring.h).

**NOTE:** This module is constantly changing and improving, this document attempts to work as a good starting point with as much as correct as possible, but the source of truth should rest in the library's comments themselves. This README is not guaranteed to contain up-to-date information with the latest `master` build.

## Testing
The [`test/`](test) directory contains tests which intend to exercise typical usage. To run all tests, simply use the command `make test`, which also includes diagnostic information from valgrind to ensure resources are being freed properly. The simple test framework [Unity](https://github.com/ThrowTheSwitch/Unity) is used to write them.

## License
This code has been licensed under the GNU General Public License v3.0.
