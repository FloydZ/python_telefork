
cmake_minimum_required(VERSION 3.20.1)
project(decoding)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

# needed for nvim
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

link_directories("deps/telefork/target/debug/")
add_executable(telefork_bin telefork.c)
target_link_libraries(telefork_bin telefork)
