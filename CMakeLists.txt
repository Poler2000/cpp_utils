cmake_minimum_required(VERSION 3.19)
project(cpp_utils)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -Wpedantic")

include_directories(include)

add_executable(cpp_utils main.cpp src/SimpleTimer.cpp include/SimpleTimer.h)