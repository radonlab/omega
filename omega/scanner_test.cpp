#include "tests/test_aux.h"

__BEGIN_DECLS
#include "omega/scanner.h"
#include "omega/token.h"
__END_DECLS

#include <gtest/gtest.h>

TEST(BasicTest, scanner) {
  const char* str = "\n\n\n";
  omg_token token;
  omg_scanner scanner;
  omg_scanner_init(&scanner);
  token = omg_scanner_scan(&scanner, str);
  EXPECT_EQ(token.type, NEWLINE);
  token = omg_scanner_scan(&scanner, str);
  EXPECT_EQ(token.type, NEWLINE);
  token = omg_scanner_scan(&scanner, str);
  EXPECT_EQ(token.type, NEWLINE);
  token = omg_scanner_scan(&scanner, str);
}
