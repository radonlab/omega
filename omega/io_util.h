// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef OMEGA_IO_UTIL_H_
#define OMEGA_IO_UTIL_H_

#include <stdbool.h>

#include "omega/string_buf.h"

bool omg_io_util_read_to_string_buf(const char* pth, omg_string_buf* buf);

#endif  // OMEGA_IO_UTIL_H_
