cmake_minimum_required(VERSION 3.23)
project(hello_world)

set(CMAKE_CXX_STANDARD 11)

add_executable(hello_world main.cpp HelloWorld.cpp HelloWorld.h)
