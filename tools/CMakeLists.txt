# Build tools

include(FetchContent)

FetchContent_Declare(
  re2c
  URL https://github.com/skvadrik/re2c/archive/refs/tags/4.0.2.tar.gz
  URL_HASH MD5=128b59fb6565930de114d8854063cf6a
  DOWNLOAD_EXTRACT_TIMESTAMP ON
)

FetchContent_MakeAvailable(re2c)

add_executable(lemon lemon.c)
