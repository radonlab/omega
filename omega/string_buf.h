// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef OMEGA_STRING_BUF_H_
#define OMEGA_STRING_BUF_H_

#include <stddef.h>

typedef struct omg_string_buf {
  char* data;
  size_t size;
  size_t capacity;
} omg_string_buf;

omg_string_buf omg_string_buf_new(void);
omg_string_buf omg_string_buf_new_with_capacity(size_t cap);
omg_string_buf omg_string_buf_new_from_string(const char* str);
omg_string_buf omg_string_buf_clone(const omg_string_buf* src);
void omg_string_buf_free(omg_string_buf buf);

void omg_string_buf_append(omg_string_buf* buf, const char* str);
void omg_string_buf_nappend(omg_string_buf* buf, const char* str, size_t len);
void omg_string_buf_prepend(omg_string_buf* buf, const char* str);
void omg_string_buf_nprepend(omg_string_buf* buf, const char* str, size_t len);

#endif  // OMEGA_STRING_BUF_H_
