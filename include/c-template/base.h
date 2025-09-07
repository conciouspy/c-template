#ifndef __C_TEMPLATE_BASE_H__
#define __C_TEMPLATE_BASE_H__
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
/**
 * @file base.h
 * @brief Base utilities for CLI tools.
 * @author github/conciouspy
 *
 * This header file declares basic functions and macros used across various CLI tools.
 */
int base_add(int a, int b);

#define NEW_PTR(p)                                         \
        p = malloc(sizeof(*(p)));                          \
        if (p) {                                           \
            memset(p, 0, sizeof(*(p)));                    \
        } else {                                           \
            fprintf(stderr, "Memory allocation failed\n"); \
            goto ALLOC_ERROR;                              \
        }                                          

// Takes in a pointer to a pointer and frees the memory, setting the pointer to NULL
#define FREE_PTR(pp)                                       \
        if(*(pp)) {                                        \
            free(*(pp));                                   \
            *(pp) = NULL;                                  \
        }

#define IS_NULL(p) ((p) == NULL)
#define NOT_NULL(p) ((p) != NULL)
#define IS_WHITE_SPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r')
#endif // __C_TEMPLATE_BASE_H__
