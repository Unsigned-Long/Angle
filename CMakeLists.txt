cmake_minimum_required(VERSION 3.10)

project(angle_template VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

set(./build/bin LIB_OUTPUT_DIR)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR})

include_directories(./include)

aux_source_directory(./src SRC_DIR)

add_library(angle SHARED ${SRC_DIR})

add_executable(angle_template ./main.cpp)

target_link_libraries(angle_template angle)

