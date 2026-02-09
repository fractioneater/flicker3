cmake_minimum_required(VERSION 4.0)
project(flicker_3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# It's inside a library so my code is only compiled once and flags can be applied specifically to it
add_library(flicker_lib
    src/vm.cpp
    src/compiler.cpp
    src/lexer.cpp
    src/tree-export.cpp
    gen/antlr/flicker.cpp
    gen/antlr/flickerBaseVisitor.cpp
    gen/antlr/flickerVisitor.cpp
)

# ANTLR4 Setup
target_include_directories(flicker_lib SYSTEM PUBLIC /usr/local/include/antlr4-runtime gen/antlr)
target_link_libraries(flicker_lib PRIVATE /usr/local/lib/libantlr4-runtime.a)

target_compile_options(flicker_lib PRIVATE -Wall -Werror)
target_include_directories(flicker_lib PUBLIC h)

# Flicker 3
add_executable(flicker_3 src/main.cpp)
target_link_libraries(flicker_3 flicker_lib)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(tests test/lexer-test.cpp)
target_link_libraries(tests GTest::gtest_main flicker_lib)

# Parser test
add_executable(test_parser test/parser-test.cpp)
target_link_libraries(test_parser GTest::gtest_main flicker_lib)

include(GoogleTest)
gtest_discover_tests(tests)
gtest_discover_tests(test_parser)
