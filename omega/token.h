// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef OMEGA_TOKEN_H_
#define OMEGA_TOKEN_H_

#define TK_EOF 0
#define TK_NEWLINE 10
#define TK_IDENTIFIER 11

#define LT_STRING 20
#define LT_LONG_STRING 21

#define KW_PACKAGE 100
#define KW_IMPORT 101
#define KW_BEGIN 102
#define KW_END 103
#define KW_VAR 104
#define KW_CONST 105
#define KW_TYPE 106
#define KW_STRUCT 107
#define KW_FUNC 108
#define KW_RETURN 109
#define KW_FOR 110
#define KW_BREAK 111
#define KW_CONTINUE 112
#define KW_IF 113
#define KW_ELSE 114
#define KW_SWITCH 115
#define KW_CASE 116
#define KW_DEFAULT 117

#define SP_LPAREN 200
#define SP_RPAREN 201
#define SP_LBRACKET 202
#define SP_RBRACKET 203
#define SP_LBRACE 204
#define SP_RBRACE 205

#define OP_ASSIGN 301
#define OP_EQ 302
#define OP_NE 303

#endif  // OMEGA_TOKEN_H_
