<<<<<<< HEAD
commit 985f23c6d406ebe17ec0e98b42b4e6dafd2f03fe
Author: Pr0meTheuSS <yr.olimpiev@gmail.com>
Date:   Mon Nov 7 18:10:48 2022 +0700

    Added google test framework deps

diff --git a/AutoPeter/GraphCore/CMakeLists.txt b/AutoPeter/GraphCore/CMakeLists.txt
new file mode 100644
index 0000000..a89de4b
--- /dev/null
+++ b/AutoPeter/GraphCore/CMakeLists.txt
@@ -0,0 +1,33 @@
+cmake_minimum_required(VERSION 3.14)
+project(GraphCore)
+
+# GoogleTest requires at least C++14
+set(CMAKE_CXX_STANDARD 14)
+
+set(CMAKE_CXX_FLAGS "-g3 -fprofile-arcs -ftest-coverage --coverage -Wall -Wextra -pedantic -Werror")
+
+file(GLOB SRCS Tests/*.cpp)
+
+include(FetchContent)
+FetchContent_Declare(
+    googletest
+    GIT_REPOSITORY https://github.com/google/googletest.git
+    GIT_TAG release-1.12.1
+)
+# For Windows: Prevent overriding the parent project's compiler/linker settings
+set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
+FetchContent_MakeAvailable(googletest)
+
+enable_testing()
+
+add_executable(
+  ${SRCS}
+  )
+
+target_link_libraries(
+  GTest::gtest_main
+)
+
+include(GoogleTest)
+gtest_discover_tests()
+
=======
cmake_minimum_required(VERSION 3.14)
project(GraphCore)

#GoogleTest requires at least C++14
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
    tests
    ${SRCS}
    ../GraphCore.cpp
    )

target_link_libraries(
    tests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)

>>>>>>> feature/GraphCore
