// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef OMEGA_SCANNER_H_
#define OMEGA_SCANNER_H_

typedef struct omg_scanner {
  int cur_pos;
  int cur_line;
  int cur_col;
} omg_scanner;

typedef struct omg_token {
  int type;
  int pos;
  int lineno;
  int colno;
} omg_token;

void omg_scanner_init(omg_scanner* scanner);
omg_token omg_scanner_scan(omg_scanner* scanner, const char* str);

#endif  // OMEGA_SCANNER_H_
