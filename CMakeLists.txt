cmake_minimum_required (VERSION 3.0)

#### Project name ####
project(matrix_determinant C)

#### Target ####
set(TARGET matrix_determinant)

#### Compile options ####
set(CMAKE_C_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

#### Target output directories ####
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/${CMAKE_BUILD_TYPE}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/${CMAKE_BUILD_TYPE}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/${CMAKE_BUILD_TYPE}/lib)

#### Source ####
include_directories(
	src
	src/matrix
	src/config
)

add_executable(${TARGET}
	src/matrix/matrix.c
	src/config/config.c
	src/main_matrix_determinant.c
)
