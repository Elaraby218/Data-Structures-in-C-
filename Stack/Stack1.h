//
// Created by Elaraby on 02/10/2023.
//

#ifndef STACK_STACK1_H
#define STACK_STACK1_H

#include "Stack.h"

template<class Type>
class Stack1 : public Stack<Type> {
public:
    const Stack1<Type> &operator=(const Stack1<Type> &);
    // overload the assignment operator.

    void initializeStack();
    //Function to initialize the stack to an empty state .

    bool is_empty() const;
    //Function to determine whether the stack is empty.

    bool is_full() const ;
    //Function to determine whether the stack is full.

    void push(const Type &newItem);
    //Function to add new item to the stack

    Type top() const ;
    //Function to return the top element of the stack.
    //Precondition: The stack exists and is not empty.
    //Postcondition: If the stack is empty, the program
    // terminates; otherwise, the top element of the stack is returned.

    void pop();
    //Function to remove the top element of the stack.
    //Precondition: The stack exists and is not empty.
    //Postcondition: The stack is changed and the top element is removed from the stack.

    Stack1(int stackSize = 100);
    //Constructor
    //Create an array of the size stackSize to hold
    //the stack elements. The default stack size is 100.
    //Postcondition: The variable list contains the base address
    // of the array, stackTop = 0, and maxStackSize = stackSize

    Stack1(const Stack1<Type> &otherStack);
    //Copy constructor

    ~Stack1();
    //Destructor
    //Remove all the elements from the stack.
    //Postcondition: The array (list) holding the stack
    // elements is deleted.

private:
    int maxStackSize;
    int stackTop;
    Type *list;

    void copyStack(const Stack1<Type> &otherStack);
    //Fuction to make a copy of other stack;
};

#endif //STACK_STACK1_H
