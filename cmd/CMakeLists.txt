# Build executable target

set(OMEGA_EXE_NAME omega)
set(OMEGA_EXE_SRCS
    omega.c
)

add_executable(${OMEGA_EXE_NAME} ${OMEGA_EXE_SRCS})

find_package(pgetopt CONFIG REQUIRED)
find_package(clevenshtein CONFIG REQUIRED)

target_link_libraries(${OMEGA_EXE_NAME} PRIVATE ${OMEGA_LIB_NAME} pgetopt clevenshtein)
