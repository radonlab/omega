// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "omega/scanner.h"

#include <stddef.h>

#include "omega/parser_impl.h"

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

#define TK(type) make_token(scanner, token, TK_##type)

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
    squote_string = "'" ("\\"[^\x00] | [^'\x00\n\\])* "'";
    dquote_string = '"' ('\\'[^\x00] | [^"\x00\n\\])* '"';
    squote_long_string =
        "'''" ( "\\"[^\x00]
            | ("'" | "'" "\\"+ "'" | "'" "\\"+) [^'\x00\\]
            | ("''" | "''" "\\"+) [^'\x00\\]
            | [^'\x00\\] )*
        "'''";
    dquote_long_string =
        '"""' ( '\\'[^\x00]
            | ('"' | '"' '\\'+ '"' | '"' '\\'+) [^"\x00\\]
            | ('""' | '""' '\\'+) [^"\x00\\]
            | [^"\x00\\] )*
        '"""';

    * {
    }

    eof {
      return TK(EOF);
    }

    newline {
      omg_token result = TK(NEWLINE);
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

    // Literal

    squote_string      { return TK(STRING_LIT); }
    dquote_string      { return TK(STRING_LIT); }
    squote_long_string { return TK(RAW_STRING_LIT); }
    dquote_long_string { return TK(RAW_STRING_LIT); }

    // Keywords

    "package"  { return TK(PACKAGE); }
    "import"   { return TK(IMPORT); }
    "var"      { return TK(VAR); }
    "const"    { return TK(CONST); }
    "type"     { return TK(TYPE); }
    "struct"   { return TK(STRUCT); }
    "func"     { return TK(FUNC); }
    "return"   { return TK(RETURN); }
    "for"      { return TK(FOR); }
    "break"    { return TK(BREAK); }
    "continue" { return TK(CONTINUE); }
    "if"       { return TK(IF); }
    "else"     { return TK(ELSE); }
    "switch"   { return TK(SWITCH); }
    "case"     { return TK(CASE); }
    "default"  { return TK(DEFAULT); }

    identifier { return TK(IDENTIFIER); }

    // Separator

    "(" { return TK(L_PAREN); }
    ")" { return TK(R_PAREN); }
    "[" { return TK(L_BRACKET); }
    "]" { return TK(R_BRACKET); }
    "{" { return TK(L_BRACE); }
    "}" { return TK(R_BRACE); }

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
