/**
 * string.h of the C STL.
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

#ifndef STRING_H
#define STRING_H

#include "vector.h"

/**
 * Generate a set of vector functions for our string
 */
declare_vector(string_, , string, char)

    /**
 * Intiailizes an empty string with the contents of the char* passed. 
 * It is assumed that that char* is valid.
 */
    string* string_init_cstr(char* s);

/**
 * Sets the string to the char* passed. If there is not enough space,
 * the string will expand to fit the string.
 */
void string_set_cstr(string* str, char* s);

/**
 * TODO: Should there be a string-specific strcat? Isn't this
 * a combination of algorithm_copy along with other stuff?
 */

#endif
