cmake_minimum_required(VERSION 3.26)
project(queues)

set(CMAKE_CXX_STANDARD 23)

add_executable(queues main.cpp
        queues.h
        implementationFile.cpp)
