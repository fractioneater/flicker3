cmake_minimum_required(VERSION 4.0)
project(flicker_3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# Files are organized as a library so my code is only compiled once and flags can be applied specifically to it.
add_library(flicker_lib
	src/lexer.cpp
	src/parser.cpp
	src/analyzer.cpp
	src/vm.cpp
	src/util.cpp
)

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

# Lexer test
add_executable(test_lexer test/lexer-test.cpp)
target_link_libraries(test_lexer GTest::gtest_main flicker_lib)

# Parser test
add_executable(test_parser test/parser-test.cpp)
target_link_libraries(test_parser GTest::gtest_main flicker_lib)

include(GoogleTest)
gtest_discover_tests(test_lexer)
gtest_discover_tests(test_parser)
