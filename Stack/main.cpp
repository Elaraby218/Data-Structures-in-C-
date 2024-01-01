#include <iostream>
#include "implementationFile.cpp"

using namespace std;

void testCopyConstructor(Stack1<int> otherStack) {
    if (!otherStack.is_empty())
        cout << "otherStack is not empty." << endl
             << "The top element of otherStack: " << otherStack.top() << endl;
}

void testCopy(Stack2<int> OStack) {
    cout << "Stack in the function testCopy:" << endl;
    while (!OStack.is_empty()) {
        cout << OStack.top() << endl;
        OStack.pop();
    }
}

int main() {
    //////////////////////////////////////// test array stack
    cout<< "test array stack -------------------------------------------------------------------------" << endl ;
    Stack1<int> stack(50);
    Stack1<int> copyStack(50);
    Stack1<int> dummyStack(100);
    stack.initializeStack();
    stack.push(23);
    stack.push(45);
    stack.push(38);
    copyStack = stack; //copy stack into copyStack
    cout << "The elements of copyStack: ";
    while (!copyStack.is_empty()) {
        cout << copyStack.top() << " ";
        copyStack.pop();
    }
    cout << endl;
    copyStack = stack;
    testCopyConstructor(stack); //test the copy constructor
    if (!stack.is_empty())
        cout << "The original stack is not empty." << endl
             << "The top element of the original stack: "
             << copyStack.top() << endl;
    dummyStack = stack;
    cout << "The elements of dummyStack: ";
    while (!dummyStack.is_empty()) {
        cout << dummyStack.top() << " ";
        dummyStack.pop();
    }
    cout << endl;
    cout << endl ; 


    ////////////////////////////////////////////////////////////////// test linked list stack
    cout << "test linkedlist stack ------------------------------------------------------------------------" << endl ;
    Stack2<int> stack1;
    Stack2<int> otherStack;
    Stack2<int> newStack;

    stack1.push(34);
    stack1.push(43);
    stack1.push(27);

    newStack = stack1;
    cout << "After the assignment operator, newStack: " << endl;
    while (!newStack.is_empty()){
        cout << newStack.top() << endl;
        newStack.pop();
    }
    otherStack = stack1;
    cout << "Testing the copy constructor." << endl;
    testCopy(otherStack);
    cout << "After the copy constructor, otherStack: " << endl;
    while (!otherStack.is_empty()){
        cout << otherStack.top() << endl;
        otherStack.pop();
    }

    return 0 ;
}
