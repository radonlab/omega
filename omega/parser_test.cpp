#include "test_aux.h"

__BEGIN_DECLS
#include "omega/parser.h"
__END_DECLS

TEST(ParserTest, parser_parse_basic) {
  const char* str =
      "func test()\n"
      "  # single-line comment\n"
      "end";
  omg_parser parser;
  omg_parser_parse(&parser, str);
}
