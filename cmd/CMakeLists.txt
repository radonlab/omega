# Build executable target

set(OMEGA_EXE_NAME omega)
set(OMEGA_EXE_SRCS omega.c)

add_executable(${OMEGA_EXE_NAME} ${OMEGA_EXE_SRCS})

target_link_libraries(
  ${OMEGA_EXE_NAME} PRIVATE
  ${OMEGA_LIB_NAME}
)
