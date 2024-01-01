//
// Created by Elaraby on 03/10/2023.
//

#include<bits/stdc++.h>
#include "Stack.h"
#include "Stack1.h"
#include "Stack2.h"

using namespace std;


//////////////////////////////////////////////////////////// stack using array
template<class Type>
void Stack1<Type>::initializeStack() {
    stackTop = 0;
}

template<class Type>
bool Stack1<Type>::is_empty() const {
    return (stackTop == 0);
}

template<class Type>
bool Stack1<Type>::is_full() const {
    return (stackTop == maxStackSize);
}

template<class Type>
void Stack1<Type>::push(const Type &newItem) {
    if (!is_full()) {
        list[stackTop] = newItem;
        stackTop++;
    } else {
        cout << "cannot add to a full stack " << endl;
    }
}

template<class Type>
Type Stack1<Type>::top() const {
    assert(stackTop != 0);
    return list[stackTop - 1];
}

template<class Type>
void Stack1<Type>::pop() {
    if (is_empty()) {
        cout << "the stack is empty " << endl;
    } else {
        stackTop--;
    }
}

template<class Type>
void Stack1<Type>::copyStack(const Stack1<Type> &otherStack) {
    delete[] list;
    stackTop = otherStack.stackTop;
    maxStackSize = otherStack.maxStackSize;
    list = new Type[maxStackSize];
    for (int i = 0; i < stackTop; i++) {
        list[i] = otherStack.list[i];
    }
}

template<class Type>
Stack1<Type>::Stack1(int stackSize) {
    if (stackSize <= 0) {
        cout << "Size of the array to hold the stack must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;
        maxStackSize = 100;
    } else {
        maxStackSize = stackSize;
        stackTop = 0;
        list = new Type[maxStackSize];
    }
}

template<class Type>
Stack1<Type>::~Stack1() {
    delete[] list;
}

template<class Type>
Stack1<Type>::Stack1(const Stack1<Type> &otherStack) {
    list = NULL;
    copyStack(otherStack);
}

template<class Type>
const Stack1<Type> &Stack1<Type>::operator=(const Stack1<Type> &otherStack) {
    if (this != &otherStack)
        copyStack(otherStack);
    return *this;
}

////////////////////////////////////////////////////////////////////////////////////// stack usin linkedlist

template<class Type>
Stack2<Type>::Stack2() {
    stackTop = NULL;
}

template<class Type>
bool Stack2<Type>::is_empty() const {
    return (stackTop == NULL);
}

template<class Type>
bool Stack2<Type>::is_full() const {
    return false;
    //Recall that in the linked implementation of stacks, the function is_full does not
    //apply because logically the stack is never full. However, you must provide its definition
    //because it is included as an abstract function in the parent class stackADT.
}

template<class Type>
void Stack2<Type>::initializeStack() {
    nodeType<Type> *temp;
    while (stackTop != NULL) {
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }
}

template<class Type>
void Stack2<Type>::push(const Type &newItem) {
    nodeType<Type> *newnode;
    newnode = new nodeType<Type>;
    newnode->info = newItem;
    newnode->link = stackTop;
    stackTop = newnode;
}

template<class Type>
Type Stack2<Type>::top() const {
    assert(stackTop != NULL);
    return stackTop->info;
}

template<class Type>
void Stack2<Type>::pop() {
    nodeType<Type> *temp;
    if (stackTop != NULL) {
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    } else {
        cout << "Cannot remove from an empty stack." << endl;
    }
}

template <class Type>
void Stack2<Type>::copyStack(const Stack2<Type>& otherStack){
    nodeType<Type> *newNode, *current, *last;
    if (stackTop != NULL) {
        //if stack is nonempty, make it empty
        initializeStack();
    }
    if (otherStack.stackTop == NULL) {
        stackTop = NULL;
    } else {
        current = otherStack.stackTop;   //set current to point to the stack to be copied
                                         //copy the stackTop element of the stack
        stackTop = new nodeType<Type>;   //create the node
        stackTop->info = current->info;  //copy the info
        stackTop->link = NULL;           //set the link field to NULL
        last = stackTop;                 //set last to point to the node
        current = current->link;         //set current to point to the next node

        //copy the remaining stack       // last mean last node added
        while (current != NULL){
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }//end while
    }//end else
} //end copyStack

template <class Type>
Stack2<Type>::Stack2(const Stack2<Type> &otherList) {
    stackTop = NULL ;
    copyStack(otherList) ;
}

template<class Type>
Stack2<Type>::~Stack2(){
   initializeStack() ;
}

template<class Type>
const Stack2<Type>& Stack2<Type>::operator=(const Stack2<Type>& otherStack){
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);
    return *this;
}


