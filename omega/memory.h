// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef OMEGA_MEMORY_H_
#define OMEGA_MEMORY_H_

#include <stddef.h>

void* omg_malloc(size_t size);
void* omg_calloc(size_t num, size_t size);
void* omg_realloc(void* ptr, size_t size);
void omg_free(void* ptr);

#endif  // OMEGA_MEMORY_H_
