// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "omega/io_util.h"

#include <stdio.h>

#include "omega/memory.h"

bool omg_io_util_read_to_string_buf(const char* pth, omg_string_buf* buf) {
  FILE* file = fopen(pth, "r");
  if (file == NULL) {
    perror("Error opening file");
    return false;
  }
  char* tmp = omg_malloc(BUFSIZ * sizeof(char));
  size_t n;
  do {
    n = fread(tmp, sizeof(char), BUFSIZ, file);
    omg_string_buf_appendn(buf, tmp, n);
  } while (n > 0);
  omg_free(tmp);
  fclose(file);
  return true;
}
