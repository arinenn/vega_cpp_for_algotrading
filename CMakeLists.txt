cmake_minimum_required(VERSION 3.14)
project(sample_cpp_project)

add_executable(main main.cpp src/my_add.cpp)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

set(BENCHMARK_ENABLE_TESTING NO)

FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG main
)

FetchContent_MakeAvailable(googletest googlebenchmark)

enable_testing()
add_executable(tests tests/test_add.cpp src/my_add.cpp)
target_link_libraries(tests gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)

add_executable(bench tests/benchmark_run.cpp src/my_add.cpp)
target_link_libraries(bench benchmark::benchmark)