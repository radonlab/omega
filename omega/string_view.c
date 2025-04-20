// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "omega/string_view.h"

omg_string_view omg_string_view_from(const char* start, size_t size) {
  omg_string_view result = {
      .data = start,
      .size = size,
  };
  return result;
}

omg_string_view omg_string_view_from_range(const char* start, const char* end) {
  omg_string_view result = {
      .data = start,
      .size = end - start,
  };
  return result;
}
