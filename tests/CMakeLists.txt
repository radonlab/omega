# Build tests

enable_language(CXX)
enable_testing()

find_package(GTest REQUIRED)

set(OMEGA_LIB_DIR "${OMEGA_SOURCE_DIR}/omega")

set(OMEGA_TEST_SRCS
    ${OMEGA_LIB_DIR}/io_util_test.cpp
)

add_executable(test_zero ${OMEGA_TEST_SRCS})

target_link_libraries(
  test_zero PRIVATE
  GTest::gtest_main
)

add_test(ZeroTest test_zero)
