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

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <c-template/base.h>
#include <c-template/c_str.h>

typedef struct CStr {
    char* data;
    size_t length;
    size_t capacity;
} CStr;


CStr* cstr_new(const char* init_str, size_t length){
    CStr* str = NEW_PTR(str);
    if (init_str && length > 0) {
        str->capacity = length + 1; // +1 for null terminator
        str->data = (char*)malloc(str->capacity);
        if (!str->data) {
            fprintf(stderr, "Memory allocation failed\n");
            goto ALLOC_ERROR;
        }
        memcpy(str->data, init_str, length);
        str->data[length] = '\0';
        str->length = length;
    } else {
        str->capacity = 16; // initial capacity
        str->data = (char*)malloc(str->capacity);
        if (!str->data) {
            fprintf(stderr, "Memory allocation failed\n");
            goto ALLOC_ERROR;
        }
        str->data[0] = '\0';
        str->length = 0;
    }
    return str;
ALLOC_ERROR:
    if(NOT_NULL(str)) {
        cstr_free(&str);
    }
    return NULL;
};

void cstr_free(CStr** str){
    if (str && *str) {
        FREE_PTR(&((*str)->data));
        FREE_PTR(str);
    }
};

const char* cstr_data(const CStr* str){
    if (str) {
        return str->data;
    }
    return NULL;
};


size_t cstr_length(const CStr* str){
    if (str) {
        return str->length;
    }
    return 0;
}


void cstr_append(CStr* str, const char* suffix, size_t length){
    if (str && suffix && length > 0) {
        if (str->length + length + 1 > str->capacity) {
            size_t new_capacity = (str->length + length + 1) * 2;
            char* new_data = (char*)realloc(str->data, new_capacity);
            if (!new_data) {
                fprintf(stderr, "Memory allocation failed in cstr_append\n");
                return;
            }
            str->data = new_data;
            str->capacity = new_capacity;
        }
        memcpy(str->data + str->length, suffix, length);
        str->length += length;
        str->data[str->length] = '\0';
    }
}

void cstr_clear(CStr* str){
    if (str) {
        str->length = 0;
        if (str->data) {
            str->data[0] = '\0';
        }
    }
};

CStr* cstr_clone(const CStr* str){
    if (str) {
        return cstr_new(str->data, str->length);
    }
    return NULL;
}

int cstr_compare(const CStr* str1, const CStr* str2){
    if (str1 && str2) {
        size_t min_length = (str1->length < str2->length) ? str1->length : str2->length;
        int cmp = memcmp(str1->data, str2->data, min_length);
        if (cmp == 0) {
            if (str1->length < str2->length) return -1;
            if (str1->length > str2->length) return 1;
            return 0;
        }
        return cmp;
    }
    if (str1 == NULL && str2 == NULL) return 0;
    if (str1 == NULL) return -1;
    return 1;
}

