cmake_minimum_required(VERSION 4.0)

# Enable experimental `import std` support. This gate, along with CMAKE_CXX_MODULE_STD, must be set BEFORE the first project() call that enables the CXX
# language. The UUID is version-specific; this value is valid for CMake 3.31.11 .. 4.2.x (see Help/dev/experimental.rst in the CMake source).
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_MODULE_STD 1)

project(flicker_3 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

include(FetchContent)

# Files are organized as a library so my code is only compiled once and flags can be applied specifically to it.
add_library(flicker_lib)
target_sources(flicker_lib
	PRIVATE
	src/linenoise-wrapper.h
	src/linenoise-wrapper.cpp

	PUBLIC FILE_SET HEADERS
	BASE_DIRS src
	FILES src/common.h

	PUBLIC FILE_SET CXX_MODULES FILES
	src/analyzer.cppm
	src/analyzer-host.cppm
	src/ast.cppm
	src/core.fl.cppm
	src/diagnostic.cppm
	src/dot-printer.cppm
	src/lexer.cppm
	src/module.cppm
	src/param.cppm
	src/parser.cppm
	src/type.cppm
	src/vm.cppm
)

# Import Linenoise
FetchContent_Declare(
	linenoise
	GIT_REPOSITORY https://github.com/yhirose/cpp-linenoise.git
	GIT_TAG 67be78f385ff552a21d6f2d0b71fac64d9298384
)
FetchContent_MakeAvailable(linenoise)

# Create the flicker_lib target
target_link_libraries(flicker_lib PRIVATE linenoise)
set_target_properties(flicker_lib PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED ON CMAKE_CXX_MODULE_STD 1 CMAKE_CXX_EXTENSIONS OFF)
target_compile_options(flicker_lib PRIVATE -Wall -Werror)

# Flicker 3
add_executable(flicker_3 src/main.cpp)
target_link_libraries(flicker_3 flicker_lib)

# GoogleTest
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
