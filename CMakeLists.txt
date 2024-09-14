cmake_minimum_required(VERSION 3.14)
project(sample_cpp_project)

add_executable(main main.cpp my_add.cpp)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(tests test_add.cpp my_add.cpp)
target_link_libraries(tests gtest_main)

# include_directories(${CMAKE_SOURCE_DIR}/googletest)

include(GoogleTest)
gtest_discover_tests(tests)