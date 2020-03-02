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

#include "../include/string.h"
#include "../include/vector.h"
#include "../include/algorithm.h"

#include <string.h>

/**
 * Generate a set of vector functions for our string
 */
// clang-format off
define_vector(string_, , string, char)
// clang-format on

string* string_init_cstr(const char* s) {
    string* str = string_init_size(strlen(s));
    algorithm_min_copy(char*, s, s + strlen(s), str->head);
    return str;
}

void string_set_cstr(string* str, const char* s) {
    if(string_size(str) < strlen(s)) {
        str->head = (char*) realloc(str->head, sizeof(string) * strlen(s));
    }
    algorithm_min_copy(char*, s, s + strlen(s), str->head)
}

void string_to_cstr(const string* str, char* dest) {
    char* end;
    algorithm_copy(char*, str->head, str->avail, dest, end);
    end = '\0';
}
