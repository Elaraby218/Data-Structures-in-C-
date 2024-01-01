cmake_minimum_required(VERSION 3.26)
project(doubly_linked_list)

set(CMAKE_CXX_STANDARD 23)

add_executable(doubly_linked_list main.cpp
        DoublyLinkedList.cpp
        DoublyLinkedList.h
)
