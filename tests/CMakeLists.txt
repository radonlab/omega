# Build tests

enable_language(CXX)

find_package(GTest REQUIRED)

set(OMEGA_LIB_DIR "${OMEGA_SOURCE_DIR}/omega")

set(OMEGA_TEST_SRCS
    test_aux.h
    ${OMEGA_LIB_DIR}/io_util_test.cpp
)

add_executable(test_zero ${OMEGA_TEST_SRCS})

target_link_libraries(
  test_zero PRIVATE
  ${OMEGA_LIB_NAME} GTest::gtest_main
)

target_include_directories(
  test_zero
  PRIVATE ${OMEGA_SOURCE_DIR}
)

target_compile_definitions(test_zero PRIVATE OMG_TEST_DATA_PATH="${CMAKE_CURRENT_SOURCE_DIR}")

include(GoogleTest)

gtest_discover_tests(test_zero)
