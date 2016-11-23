cmake_minimum_required(VERSION 3.0)
project(homework8)

set(CMAKE_CXX_FLAGS
    "${CMAKE_C_FLAGS} -std=c++14 -g -O0 -Wno-c++98-compat -Wno-c++98-compat-pedantic"
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything")

elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lm")

endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(WORDS_SOURCE_FILES Words.cpp Words.hpp)
add_library(Words ${WORDS_SOURCE_FILES})

set(SOURCE_FILES main.cpp)

find_package(Boost 1.62.0)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(homework8 ${SOURCE_FILES})
  target_link_libraries(homework8 ${Boost_LIBRARIES} Words)
endif()

