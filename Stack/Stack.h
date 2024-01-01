//
// Created by Elaraby on 02/10/2023.
//
#ifndef STACK_STACK_H
#define STACK_STACK_H

template<class Type>
class Stack {
public:
    virtual void initializeStack() = 0;
    //Method to initialize the stack to an empty state.
    //Postcondition: Stack is empty.

    virtual bool is_empty() const = 0;
    //Function to determine whether the stack is empty.

    virtual bool is_full() const = 0;
    //Function to determine whether the stack is full.

    virtual void push(const Type &newItem) = 0;
    // function to add new item to the stack

    virtual Type top() const = 0;
    // function to return the top element of the stack

    virtual void pop() = 0;
    // function to remove the top element of the stack

};

#endif //STACK_STACK_H
