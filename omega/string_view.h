// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef OMEGA_STRING_VIEW_H_
#define OMEGA_STRING_VIEW_H_

#include <stddef.h>

typedef struct omg_string_view {
  const char* const data;
  const size_t size;
} omg_string_view;

omg_string_view omg_string_view_from(const char* start, size_t size);
omg_string_view omg_string_view_from_range(const char* start, const char* end);

#endif  // OMEGA_STRING_VIEW_H_
