cmake_minimum_required(VERSION 3.20)

project(klang)

set(CMAKE_CXX_STANDARD 20)

find_package(LLVM REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/lib/include")

add_subdirectory(lib)
add_subdirectory(tests)
