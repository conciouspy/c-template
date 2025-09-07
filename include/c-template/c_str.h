// Copyright (c) 2025, github/conciouspy
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef __C_TEMPLATE_C_STR_H__
#define __C_TEMPLATE_C_STR_H__
#include <stddef.h>

/**
  * @file c_str.h 
  * @brief A simple C string library. 
  * @author github/conciouspy 
  * This library provides a simple C string implementation with basic functionalities.
  */ 
typedef struct CStr CStr;

/**
  * @brief Create a new CStr instance. 
  * @param init_str Initial string to copy into the CStr. 
  * @param length Length of the initial string. 
  * @return Pointer to the newly created CStr instance, or NULL on failure. 
  */
CStr* cstr_new(const char* init_str, size_t length);

/**
  * @brief Free a CStr instance. Deallocates memory and sets the pointer to NULL.
  * @param str Pointer to the pointer to the CStr instance to free. 
  */
void cstr_free(CStr** str);

/**
  * @brief Get the C string data from the CStr instance. Ensures the returned string is null-terminated.
  * @param str Pointer to the CStr instance. 
  * @return Pointer to the internal C string data, or NULL if str is NULL. 
  */
const char* cstr_data(const CStr* str);

/**
  * @brief Get the length of the C string in the CStr instance. 
  * @param str Pointer to the CStr instance. 
  * @return Length of the string, or 0 if str is NULL. 
  */
size_t cstr_length(const CStr* str);

/**
  * @brief Append a suffix to the CStr instance. 
  * @param str Pointer to the CStr instance. 
  * @param suffix Suffix string to append. 
  * @param length Length of the suffix string. 
  */
void cstr_append(CStr* str, const char* suffix, size_t length);

/**
  * @brief Clear the contents of the CStr instance. 
  * @param str Pointer to the CStr instance. 
  */
void cstr_clear(CStr* str);

/**
  * @brief Clone a CStr instance. 
  * @param str Pointer to the CStr instance to clone. 
  * @return Pointer to the newly cloned CStr instance, or NULL on failure. 
  */
CStr* cstr_clone(const CStr* str);

/**
  * @brief Compare two CStr instances lexicographically. 
  * @param str1 Pointer to the first CStr instance. 
  * @param str2 Pointer to the second CStr instance. 
  * @return Negative value if str1 < str2, zero if str1 == str2, positive value if str1 > str2. 
  */
int cstr_compare(const CStr* str1, const CStr* str2);

#endif // __C_TEMPLATE_C_STR_H__
