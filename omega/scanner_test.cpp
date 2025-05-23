#include "test_aux.h"

__BEGIN_DECLS
#include "omega/scanner.h"
#include "omega/token.h"
__END_DECLS

TEST(ScannerTest, scanner_scan_token) {
  const char* str = "begin\n  \nend\n";
  omg_token token;
  omg_scanner scanner;
  omg_scanner_init(&scanner, str);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, KW_BEGIN);
  EXPECT_EQ(token.pos, 0);
  EXPECT_EQ(token.end, 5);
  EXPECT_EQ(token.lineno, 1);
  EXPECT_EQ(token.colno, 1);
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
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, TK_NEWLINE);
  EXPECT_EQ(token.pos, 12);
  EXPECT_EQ(token.end, 13);
  EXPECT_EQ(token.lineno, 3);
  EXPECT_EQ(token.colno, 4);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, TK_EOF);
}
