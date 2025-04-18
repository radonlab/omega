#include "test_aux.h"

__BEGIN_DECLS
#include "omega/io_util.h"
__END_DECLS

#ifndef OMG_TEST_DATA_PATH
#define OMG_TEST_DATA_PATH "__undefined__"
#endif  // OMG_TEST_DATA_PATH

TEST(CommonTest, io_util_read_file) {
  const char* input = OMG_TEST_DATA_PATH "/input.txt";
  omg_string_buf buf = omg_string_buf_new();
  omg_io_util_read_to_string_buf(input, &buf);
  EXPECT_STREQ(buf.data, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n");
  EXPECT_EQ(buf.size, 57);
  omg_string_buf_free(buf);
}
