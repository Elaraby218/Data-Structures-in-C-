//
// Created by Elaraby on 02/10/2023.
//

#ifndef STACK_STACK2_H
#define STACK_STACK2_H


template<class Type>
struct nodeType {
    Type info;
    nodeType<Type> *link;
};

template<class Type>
class Stack2 : public Stack<Type> {
public:
    const Stack2<Type> &operator=(const Stack2<Type> &);
    // overload the assignment operator

    bool is_empty() const;

    bool is_full() const;

    void initializeStack();

    void push(const Type &newItem);

    Type top() const;

    void pop();

    Stack2();

    Stack2(const Stack2<Type> &otherList);

    ~Stack2();

private:
    nodeType<Type> *stackTop;

    void copyStack(const Stack2<Type> &ohterStack);
};

#endif //STACK_STACK2_H
