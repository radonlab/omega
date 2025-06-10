// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef OMEGA_PARSER_H_
#define OMEGA_PARSER_H_

typedef struct omg_parser {
} omg_parser;

void omg_parser_init(omg_parser* parser);
void omg_parser_free(omg_parser* parser);
void omg_parser_parse(omg_parser* parser, const char* str);

#endif  // OMEGA_PARSER_H_
