# Declare modules

set(OMEGA_LIB_SRCS
    engine.c
    io_util.c
    io_util.h
    memory.c
    memory.h
    parser.c
    parser.h
    scanner.c
    scanner.h
    string_buf.c
    string_buf.h
    utility.h
)

# Build library target

set(OMEGA_LIB_NAME omega${PROJECT_VERSION_MAJOR})
set(OMEGA_LIB_NAME omega${PROJECT_VERSION_MAJOR} PARENT_SCOPE)

set(OMEGA_LIB_TYPE STATIC)
if(BUILD_SHARED_LIBS)
  set(OMEGA_LIB_TYPE SHARED)
endif()

# Config library
add_library(
  ${OMEGA_LIB_NAME} ${OMEGA_LIB_TYPE}
  ${OMEGA_LIB_SRCS}
)

target_include_directories(
  ${OMEGA_LIB_NAME}
  PRIVATE ${OMEGA_SOURCE_DIR}
  PUBLIC ${OMEGA_INCLUDE_DIR}
)

set_target_properties(${OMEGA_LIB_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${OMEGA_LIB_NAME} PROPERTIES DEFINE_SYMBOL OMG_IMPLEMENTATION)

# Add shared library macro
if(BUILD_SHARED_LIBS)
  target_compile_definitions(${OMEGA_LIB_NAME} PUBLIC OMG_USE_SHARED)
endif()
