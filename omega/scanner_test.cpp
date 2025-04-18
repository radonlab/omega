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
  EXPECT_EQ(token.lineno, 1);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, TK_NEWLINE);
  EXPECT_EQ(token.lineno, 1);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, TK_NEWLINE);
  EXPECT_EQ(token.lineno, 2);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, KW_END);
  EXPECT_EQ(token.lineno, 3);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, TK_NEWLINE);
  EXPECT_EQ(token.lineno, 3);
  token = omg_scanner_scan(&scanner);
  EXPECT_EQ(token.type, TK_EOF);
}
