cmake_minimum_required(VERSION 3.10)

project(rkc_string_literal LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_library(rkc_string_literal INTERFACE)
add_library(rkc::string_literal ALIAS rkc_string_literal)
target_include_directories(rkc_string_literal INTERFACE include)

set(RKC_STRING_LITERAL_VERSION 0.1.0)
set(RKC_STRING_LITERAL_GIT_REPOSITORY "https://github.com/yourusername/rkc_string_literal.git")
set(RKC_STRING_LITERAL_LIB_GIT_TAG "v${RKC_STRING_LITERAL_VERSION}")

if(BUILD_TESTING)
    enable_testing()
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
    )
    FetchContent_MakeAvailable(googletest)

    enable_testing()
    add_executable(program_tests tests/compile_test.cpp)
    target_link_libraries(program_tests PRIVATE GTest::gtest GTest::gtest_main rkc_string_literal)
    add_test(NAME all_tests COMMAND program_tests)
endif()
