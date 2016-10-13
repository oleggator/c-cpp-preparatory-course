cmake_minimum_required(VERSION 3.0)
project(homework3)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Weverything -g -O0")

elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -g -O0 -lm")

endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(BinarySearchTree_SOURCE_FILES BinarySearchTree.c BinarySearchTree.h)
add_library(BinarySearchTree ${BinarySearchTree_SOURCE_FILES})
add_library(BinarySearchTreeShared SHARED ${BinarySearchTree_SOURCE_FILES})

set(SOURCE_FILES main.c)
add_executable(homework3 ${SOURCE_FILES})

target_link_libraries(homework3 BinarySearchTree)
