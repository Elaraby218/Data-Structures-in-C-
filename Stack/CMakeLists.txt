cmake_minimum_required(VERSION 3.26)
project(Stack)

set(CMAKE_CXX_STANDARD 23)

add_executable(Stack main.cpp
        Stack1.h
        Stack.h
        Stack2.h
        implementationFile.cpp)
