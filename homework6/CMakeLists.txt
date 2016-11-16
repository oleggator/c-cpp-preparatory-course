cmake_minimum_required(VERSION 3.0)
project(homework6)

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

set(VOLUMEFIGURE_SOURCE_FILES VolumeFigure.cpp VolumeFigure.h)
add_library(VolumeFigure ${VOLUMEFIGURE_SOURCE_FILES})

set(CYLINDER_SOURCE_FILES Cylinder.cpp Cylinder.h)
add_library(Cylinder ${CYLINDER_SOURCE_FILES})

set(CUBOID_SOURCE_FILES Cuboid.cpp Cuboid.h)
add_library(Cuboid ${CUBOID_SOURCE_FILES})

set(SOURCE_FILES main.cpp)
add_executable(homework6 ${SOURCE_FILES})

target_link_libraries(homework6 VolumeFigure Cylinder Cuboid)
