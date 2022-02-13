cmake_minimum_required(VERSION 3.12)

# set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_BUILD_TYPE "Debug")

project(angle VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./include)

add_executable(${CMAKE_PROJECT_NAME} ./main.cpp)

set(CMAKE_INSTALL_PREFIX /usr/local/)

install(FILES ${CMAKE_SOURCE_DIR}/include/angle.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/artwork/angle)