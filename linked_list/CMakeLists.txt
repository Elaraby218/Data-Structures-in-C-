cmake_minimum_required(VERSION 3.26)
project(linked_list)

set(CMAKE_CXX_STANDARD 23)

add_executable(linked_list main.cpp
        linkedListIterator.h
        linkedListType.h
        orderedLinkedList.h
        unorderedLinkedList.h
        implementationFile.cpp)
