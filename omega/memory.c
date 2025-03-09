// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "omega/memory.h"

#include <assert.h>
#include <stdlib.h>

static void handle_out_of_memory(void) { abort(); }

void* omg_malloc(size_t size) {
  assert(size != 0);
  void* ptr = malloc(size);
  if (!ptr) {
    handle_out_of_memory();
  }
  return ptr;
}

void* omg_calloc(size_t num, size_t size) {
  assert(size != 0);
  void* ptr = calloc(num, size);
  if (!ptr) {
    handle_out_of_memory();
  }
  return ptr;
}

void* omg_realloc(void* ptr, size_t size) {
  assert(size != 0);
  void* newptr = realloc(ptr, size);
  if (!newptr) {
    handle_out_of_memory();
  }
  return newptr;
}

void omg_free(void* ptr) { free(ptr); }
