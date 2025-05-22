cmake_minimum_required(VERSION 3.10)
project(cpp-neural-network)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_executable(cpp-neural-network src/ANN.cpp src/main.cpp)
