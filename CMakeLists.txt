cmake_minimum_required(VERSION 4.0)
project(flicker_3)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

add_executable(flicker_3 src/main.cpp
        src/vm.cpp
        src/compiler.cpp
        src/lexer.cpp)

target_include_directories(flicker_3 PUBLIC h)

