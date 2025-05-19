#include <cstring>

#include "test_aux.h"

__BEGIN_DECLS
#include "omega/scanner.h"
#include "omega/token.h"
__END_DECLS

TEST(ScannerTest, scanner_scan_basic_tokens) {
  const char* str =
      "begin\n"
      "  \n"
      "end";
  omg_token token;
  omg_scanner scanner;
  omg_scanner_init(&scanner, str);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, KW_BEGIN);
  EXPECT_EQ(token.pos, 0);
  EXPECT_EQ(token.end, 5);
  EXPECT_EQ(token.lineno, 1);
  EXPECT_EQ(token.colno, 1);
  EXPECT_TRUE(memcmp(str + token.pos, "begin", strlen("begin")) == 0);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, TK_NEWLINE);
  EXPECT_EQ(token.pos, 5);
  EXPECT_EQ(token.end, 6);
  EXPECT_EQ(token.lineno, 1);
  EXPECT_EQ(token.colno, 6);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, TK_NEWLINE);
  EXPECT_EQ(token.pos, 8);
  EXPECT_EQ(token.end, 9);
  EXPECT_EQ(token.lineno, 2);
  EXPECT_EQ(token.colno, 3);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, KW_END);
  EXPECT_EQ(token.pos, 9);
  EXPECT_EQ(token.end, 12);
  EXPECT_EQ(token.lineno, 3);
  EXPECT_EQ(token.colno, 1);
  EXPECT_TRUE(memcmp(str + token.pos, "end", strlen("end")) == 0);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, TK_EOF);
}

TEST(ScannerTest, scanner_scan_func_definition) {
  const char* str =
      "func test()\n"
      "  # single-line comment\n"
      "end";
  omg_token token;
  omg_scanner scanner;
  omg_scanner_init(&scanner, str);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, KW_FUNC);
  EXPECT_EQ(token.lineno, 1);
  EXPECT_EQ(token.colno, 1);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, TK_IDENTIFIER);
  EXPECT_EQ(token.lineno, 1);
  EXPECT_EQ(token.colno, 6);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, SP_LPAREN);
  EXPECT_EQ(token.lineno, 1);
  EXPECT_EQ(token.colno, 10);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, SP_RPAREN);
  EXPECT_EQ(token.lineno, 1);
  EXPECT_EQ(token.colno, 11);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, TK_NEWLINE);
  EXPECT_EQ(token.lineno, 1);
  EXPECT_EQ(token.colno, 12);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, TK_NEWLINE);
  EXPECT_EQ(token.lineno, 2);
  EXPECT_EQ(token.colno, 24);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, KW_END);
  EXPECT_EQ(token.lineno, 3);
  EXPECT_EQ(token.colno, 1);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, TK_EOF);
}

TEST(ScannerTest, scanner_scan_strings) {
  const char* str =
      "'''\n"
      "multiple-line string\n"
      "'''\n"
      "'single-line string'";
  omg_token token;
  omg_scanner scanner;
  omg_scanner_init(&scanner, str);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, LT_LONG_STRING);
  EXPECT_EQ(token.lineno, 1);
  EXPECT_EQ(token.colno, 1);
}
