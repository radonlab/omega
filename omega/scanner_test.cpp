#include "tests/test_aux.h"

__BEGIN_DECLS
#include "omega/scanner.h"
#include "omega/token.h"
__END_DECLS

TEST(BasicTest, scanner) {
  const char* str = "begin\n\nend\n";
  omg_token token;
  omg_scanner scanner;
  omg_scanner_init(&scanner);
  token = omg_scanner_scan(&scanner, str);
  EXPECT_EQ(token.type, KW_BEGIN);
  EXPECT_EQ(token.lineno, 1);
  token = omg_scanner_scan(&scanner, str);
  EXPECT_EQ(token.type, NEWLINE);
  EXPECT_EQ(token.lineno, 1);
  token = omg_scanner_scan(&scanner, str);
  EXPECT_EQ(token.type, NEWLINE);
  EXPECT_EQ(token.lineno, 2);
  token = omg_scanner_scan(&scanner, str);
  EXPECT_EQ(token.type, KW_END);
  EXPECT_EQ(token.lineno, 2);
  token = omg_scanner_scan(&scanner, str);
  EXPECT_EQ(token.type, NEWLINE);
  EXPECT_EQ(token.lineno, 3);
  token = omg_scanner_scan(&scanner, str);
}
