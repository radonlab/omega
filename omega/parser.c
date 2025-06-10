// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "omega/parser.h"
#include "omega/scanner.h"
#include "omega/parser_impl.h"

void omg_parser_init(omg_parser* parser) {}
void omg_parser_free(omg_parser* parser) {}
void omg_parser_parse(omg_parser* parser, const char* str) {
  omg_scanner scanner;
  omg_scanner_init(&scanner, str);
  omg_token token;
  while (token = omg_scanner_scan(&scanner), token.type != TK_EOF) {
    printf("%s", token.type);
  }
}
