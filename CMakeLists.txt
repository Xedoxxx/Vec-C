cmake_minimum_required(VERSION 3.10)
project(vec_t VERSION 0.0.2 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(vec_t src/vec.c)

target_include_directories(vec_t PUBLIC include)

enable_testing()
add_subdirectory(tests)