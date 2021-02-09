# Minimum CMake version
cmake_minimum_required(VERSION 3.0)


# Project "Malloc" - Language: C
project(malloc C)

# Set C language standard to C99
set(CMAKE_C_STANDARD 99)
add_compile_options(-W -Wall -Wextra -pedantic)

# Include files
include_directories(include)

# Library: Add this to every executable
add_library(list src/list.c)
link_libraries(list)

add_executable(1_allocation_automatique    src/1_alloc_automatique.c)
add_executable(2_allocation_statique       src/2_alloc_statique.c)
add_executable(3_allocation_dynamique      src/3_alloc_dynamique.c)
add_executable(4_allocation_dynamique_test src/4_alloc_dynamique_test.c)
add_library(5_my_malloc_list SHARED        src/5_my_malloc_list.c)

