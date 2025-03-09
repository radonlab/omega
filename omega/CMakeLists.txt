# Declare submodules

set(OMEGA_MOD_CORE_NAME omega_core)
set(OMEGA_MOD_CORE_SRCS
    memory.c
    memory.h
)
add_library(${OMEGA_MOD_CORE_NAME} OBJECT ${OMEGA_MOD_CORE_SRCS})
target_include_directories(${OMEGA_MOD_CORE_NAME} PRIVATE ${OMEGA_SOURCE_DIR})

# Build library target

set(OMEGA_LIB_NAME omega${PROJECT_VERSION_MAJOR})

set(OMEGA_LIB_TYPE STATIC)
if(BUILD_SHARED_LIBS)
  set(OMEGA_LIB_TYPE SHARED)
endif()

# Config library
add_library(
  ${OMEGA_LIB_NAME} ${OMEGA_LIB_TYPE}
  $<TARGET_OBJECTS:omega_core>
)

target_include_directories(${OMEGA_LIB_NAME} PUBLIC ${OMEGA_INCLUDE_DIR})

set_target_properties(${OMEGA_LIB_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${OMEGA_LIB_NAME} PROPERTIES DEFINE_SYMBOL OMG_IMPLEMENTATION)

# Add shared library macro
if(BUILD_SHARED_LIBS)
  target_compile_definitions(${OMEGA_LIB_NAME} PUBLIC OMG_USE_SHARED)
endif()
