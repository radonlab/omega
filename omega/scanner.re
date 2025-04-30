// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "omega/scanner.h"

#include <stddef.h>

#include "omega/token.h"

void omg_scanner_init(omg_scanner* scanner, const char* str) {
  scanner->start = str;
  scanner->cursor = scanner->start;
  scanner->marker = NULL;  // No need to initialize
  scanner->cur_line = 1;
  scanner->cur_col = 1;
}

static inline void update_location(omg_scanner* scanner, const char* token) {
  int span = (int)(scanner->cursor - token);
  scanner->cur_col += span;
}

static inline omg_token make_token(omg_scanner* scanner, const char* token, int token_type) {
  omg_token result = {
      .type = token_type,
      .pos = token - scanner->start,
      .end = scanner->cursor - scanner->start,
      .lineno = scanner->cur_line,
      .colno = scanner->cur_col,
  };
  update_location(scanner, token);
  return result;
}

/*!re2c
  re2c:yyfill:enable = 0;
  re2c:define:YYCTYPE = char;
 */

omg_token omg_scanner_scan(omg_scanner* scanner) {
  const char* token;
  for (;;) {
    token = scanner->cursor;
  /*!re2c
    re2c:define:YYCURSOR = scanner->cursor;
    re2c:define:YYMARKER = scanner->marker;

    eof = "\x00";
    newline = "\n";
    whitespace = [ \t\v\r]+;
    comment = "#" [^\n\x00]*;
    char =  [^\x00-\x7F]|[a-zA-Z_];
    digit = [0-9];
    identifier = char (char | digit)*;

    * {
    }

    eof {
      return make_token(scanner, token, TK_EOF);
    }

    newline {
      omg_token result = make_token(scanner, token, TK_NEWLINE);
      scanner->cur_line++;
      scanner->cur_col = 1;
      return result;
    }

    whitespace {
      update_location(scanner, token);
      continue;
    }

    comment {
      update_location(scanner, token);
      continue;
    }

    // Keywords

    "package"  { return make_token(scanner, token, KW_PACKAGE); }
    "import"   { return make_token(scanner, token, KW_IMPORT); }
    "begin"    { return make_token(scanner, token, KW_BEGIN); }
    "end"      { return make_token(scanner, token, KW_END); }
    "var"      { return make_token(scanner, token, KW_VAR); }
    "const"    { return make_token(scanner, token, KW_CONST); }
    "type"     { return make_token(scanner, token, KW_TYPE); }
    "struct"   { return make_token(scanner, token, KW_STRUCT); }
    "func"     { return make_token(scanner, token, KW_FUNC); }
    "return"   { return make_token(scanner, token, KW_RETURN); }
    "for"      { return make_token(scanner, token, KW_FOR); }
    "break"    { return make_token(scanner, token, KW_BREAK); }
    "continue" { return make_token(scanner, token, KW_CONTINUE); }
    "if"       { return make_token(scanner, token, KW_IF); }
    "else"     { return make_token(scanner, token, KW_ELSE); }
    "switch"   { return make_token(scanner, token, KW_SWITCH); }
    "case"     { return make_token(scanner, token, KW_CASE); }
    "default"  { return make_token(scanner, token, KW_DEFAULT); }

    identifier { return make_token(scanner, token, TK_IDENTIFIER); }

    // Separator

    "(" { return make_token(scanner, token, SP_LPAREN); }
    ")" { return make_token(scanner, token, SP_RPAREN); }
    "[" { return make_token(scanner, token, SP_LBRACKET); }
    "]" { return make_token(scanner, token, SP_RBRACKET); }
    "{" { return make_token(scanner, token, SP_LBRACE); }
    "}" { return make_token(scanner, token, SP_RBRACE); }

    "=" {
      return make_token(scanner, token, OP_ASSIGN);
    }

    "==" {
      return make_token(scanner, token, OP_EQ);
    }
    "!=" {
      return make_token(scanner, token, OP_NE);
    }
   */
  }
}
