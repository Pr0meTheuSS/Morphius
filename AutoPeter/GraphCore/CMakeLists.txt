cmake_minimum_required(VERSION 3.14)
project(GraphCore)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-g3 -fprofile-arcs -ftest-coverage --coverage -Wall -Wextra -pedantic -Werror")

file(GLOB SRCS Tests/*.cpp)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  ${SRCS}
  )

target_link_libraries(
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests()

