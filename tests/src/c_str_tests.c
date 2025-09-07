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

#include "tests.h"
#include <stdlib.h>
#include <string.h>
#include <c-template/base.h>
#include <c-template/c_str.h>

TEST_BEGIN(c_str_creation_test)
CStr* str = cstr_new("Hello, World!", 13);
ASSERT(NOT_NULL(str), "CStr instance should not be NULL");
ASSERT(cstr_length(str) == 13, "CStr length should be 13");
ASSERT(strcmp(cstr_data(str), "Hello, World!") == 0, "CStr data should match the initial string");
cstr_free(&str);
ASSERT(IS_NULL(str), "CStr pointer should be NULL after free");
TEST_END

TEST_BEGIN(c_str_empty_creation_test)
CStr* str = cstr_new(NULL, 0);
ASSERT(NOT_NULL(str), "CStr instance should not be NULL");
ASSERT(cstr_length(str) == 0, "CStr length should be 0");
ASSERT(strcmp(cstr_data(str), "") == 0, "CStr data should be an empty string");
cstr_free(&str);
ASSERT(IS_NULL(str), "CStr pointer should be NULL after free");
TEST_END

TEST_BEGIN(c_str_null_creation_test)
CStr* str = cstr_new(NULL, 10);
ASSERT(NOT_NULL(str), "CStr instance should not be NULL");
ASSERT(cstr_length(str) == 0, "CStr length should be 0");
ASSERT(strcmp(cstr_data(str), "") == 0, "CStr data should be an empty string");
cstr_free(&str);
ASSERT(IS_NULL(str), "CStr pointer should be NULL after free");
TEST_END

TEST_BEGIN(c_str_concat_test)
CStr* str = cstr_new("Hello", 5);
ASSERT(NOT_NULL(str), "CStr instance should not be NULL");
cstr_append(str, ", World!", 8);
ASSERT(cstr_length(str) == 13, "CStr length should be 13 after append");
ASSERT(strcmp(cstr_data(str), "Hello, World!") == 0, "CStr data should match the concatenated string");
cstr_free(&str);
ASSERT(IS_NULL(str), "CStr pointer should be NULL after free");
TEST_END

TEST_BEGIN(c_str_clone_test)
CStr* str = cstr_new("Hello, World!", 13);
ASSERT(NOT_NULL(str), "CStr instance should not be NULL");
CStr* clone = cstr_clone(str);
ASSERT(NOT_NULL(clone), "Cloned CStr instance should not be NULL");
ASSERT(cstr_length(clone) == 13, "Cloned CStr length should be 13");
ASSERT(strcmp(cstr_data(clone), "Hello, World!") == 0, "Cloned CStr data should match the original string");
cstr_free(&str);
cstr_free(&clone);
ASSERT(IS_NULL(str), "Original CStr pointer should be NULL after free");
ASSERT(IS_NULL(clone), "Cloned CStr pointer should be NULL after free");
TEST_END

RUN_TESTS(c_str_creation_test, 
          c_str_empty_creation_test, 
          c_str_null_creation_test, 
          c_str_concat_test, 
          c_str_clone_test)

