cmake_minimum_required(VERSION 3.6)
project(homework1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Weverything -O0")

set(SOURCE_FILES main.c)
add_executable(homework1 ${SOURCE_FILES})
