// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "omega/string_buf.h"

#include <string.h>

#include "omega/memory.h"
#include "omega/utility.h"

#define DEFAULT_CAPACITY 16
#define ENLARGE_CAPACITY(x) (x + ((x + 1) >> 1))

omg_string_buf omg_string_buf_new(void) {
  return omg_string_buf_new_with_capacity(DEFAULT_CAPACITY);
}

omg_string_buf omg_string_buf_new_with_capacity(size_t capacity) {
  omg_string_buf buf;
  buf.data = omg_calloc(capacity, sizeof(*buf.data));
  buf.size = 0;
  buf.capacity = capacity;
  return buf;
}

omg_string_buf omg_string_buf_new_from_string(const char* str) {
  size_t len = strlen(str) + DEFAULT_CAPACITY;
  omg_string_buf buf = omg_string_buf_new_with_capacity(len + 1);
  memcpy(buf.data, str, len);
  buf.size = len;
  return buf;
}

omg_string_buf omg_string_buf_clone(const omg_string_buf* src) {
  omg_string_buf buf;
  buf.data = omg_calloc(src->capacity, sizeof(*buf.data));
  memcpy(buf.data, src->data, src->size);
  buf.size = src->size;
  buf.capacity = src->capacity;
  return buf;
}

void omg_string_buf_free(omg_string_buf buf) { omg_free(buf.data); }

static void ensure_capacity(omg_string_buf* buf, size_t min_capacity) {
  if (min_capacity - buf->capacity > 0) {
    size_t capacity = ENLARGE_CAPACITY(buf->capacity);
    capacity = MAX(capacity, min_capacity);
    buf->data = omg_realloc(buf->data, capacity);
    buf->capacity = capacity;
  }
}

void omg_string_buf_append(omg_string_buf* buf, const char* str) {
  size_t len = strlen(str);
  omg_string_buf_appendn(buf, str, len);
}

void omg_string_buf_appendn(omg_string_buf* buf, const char* str, size_t len) {
  ensure_capacity(buf, buf->size + len + 1);
  memcpy(buf->data + buf->size, str, len);
  buf->data[buf->size + len] = '\0';
  buf->size += len;
}

void omg_string_buf_prepend(omg_string_buf* buf, const char* str) {
  size_t len = strlen(str);
  omg_string_buf_prependn(buf, str, len);
}

void omg_string_buf_prependn(omg_string_buf* buf, const char* str, size_t len) {
  ensure_capacity(buf, buf->size + len + 1);
  memmove(buf->data + len, buf->data, buf->size + 1);
  memcpy(buf->data, str, len);
  buf->size += len;
}
