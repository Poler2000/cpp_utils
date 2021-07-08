cmake_minimum_required(VERSION 3.19)
project(cpp_utils)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS " -Wall -Wextra -Wpedantic")

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        my_test
        src/Random.cpp
        include/Random.h
        test/RandomTest.cpp
)
target_link_libraries(
        my_test
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(my_test)

include_directories(include)

add_executable(cpp_utils main.cpp src/SimpleTimer.cpp include/SimpleTimer.h src/BenchmarkTimer.cpp include/BenchmarkTimer.h include/TimeMeasurement.h src/Random.cpp include/Random.h src/Logger.cpp include/Logger.h)