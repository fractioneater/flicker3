cmake_minimum_required(VERSION 4.0)

# Enable experimental `import std` support. This gate, along with CMAKE_CXX_MODULE_STD, must be set BEFORE the first project() call that enables the CXX
# language. The UUID is version-specific; this value is valid for CMake 3.31.11 .. 4.2.x (see Help/dev/experimental.rst in the CMake source).
# set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_CXX_MODULE_STD 1)

project(flicker_3 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# Files are organized as a library so my code is only compiled once and flags can be applied specifically to it.
add_library(flicker_lib)

target_sources(flicker_lib
	PRIVATE
	src/analyzer.cpp
	src/diagnostic.cpp
	src/lexer.cpp
	src/module.cpp
	src/parser.cpp
	src/vm.cpp
	PUBLIC FILE_SET CXX_MODULES FILES
	src/dot-printer.cppm
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
