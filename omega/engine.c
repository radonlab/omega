// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "omega/io_util.h"
#include "omega/omega.h"

omega_err_code omega_compile_script(const char* src, const char* out) {
  omg_string_buf buf = omg_string_buf_new();
  if (!omg_io_util_read_to_string_buf(src, &buf)) {
    return OMG_FILE_IO_ERR;
  }
  return OMG_OK;
}

omega_err_code omega_execute(const char* src_entry) {
  return OMG_OK;
}

omega_err_code omega_execute_string(const char* src_content, const char* src_entry) {
  return OMG_OK;
}
