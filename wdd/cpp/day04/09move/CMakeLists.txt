cmake_minimum_required(VERSION 3.2)
project(09move)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")

add_executable(09move main.cpp)
