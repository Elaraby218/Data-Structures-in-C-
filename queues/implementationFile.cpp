//
// Created by Elaraby on 05/10/2023.
//

#include<bits/stdc++.h>
#include "queues.h"

using namespace std;

/////////////////////////////////////////////////////////////////// queue using circular array

template<class Type>
bool queue1<Type>::is_empty() const {
    return (count == 0);
}


template<class Type>
bool queue1<Type>::is_full() const {
    return (count == maxsize);
}

template<class Type>
void queue1<Type>::initialize() {
    queueFront = 0;
    queueRear = maxsize - 1;
    count = 0;
}

template<class Type>
Type queue1<Type>::front() const {
    assert(!is_empty());
    return list[queueFront];
}

template<class Type>
Type queue1<Type>::back() const {
    assert(!is_empty());
    return list[queueRear];
}

template<class Type>
void queue1<Type>::addQueue(const Type &queueElement) {
    if (!is_full()) {
        queueRear = (queueRear + 1) % maxsize;
        count++;
        list[queueRear] = queueElement;
    } else {
        cout << "cannot add to a full queue. " << endl;
    }
}

template<class Type>
void queue1<Type>::deleteQueue() {
    if (!is_empty()) {
        count--;
        queueFront = (queueFront + 1) % maxsize;
    } else {
        cout << "cannot remove from an empty queue" << endl;
    }
}

template<class Type>
queue1<Type>::queue1(int size) {
    if (size <= 0) {
        cout << "size of the array to hold the queue must be positive." << endl;
        cout << "creating an array for size 100." << endl;
        maxsize = 100;
    } else {
        maxsize = size;
    }
    queueFront = 0;
    queueRear = maxsize - 1;
    count = 0;
    list = new Type[maxsize];
}

template<class Type>
queue1<Type>::~queue1() {
    delete[]list;
}

template<class Type>
void queue1<Type>::copylist(const queue1<Type> &otherlist) {
    maxsize = otherlist.maxsize;
    queueRear = otherlist.queueRear;
    queueFront = otherlist.queueFront;
    count = otherlist.count;
    list = new Type[maxsize];
    for (int i = 0; i < count; i++) {
        list[i] = otherlist.list[i];
    }
}

template<class Type>
queue1<Type>::queue1(const queue1<Type> &otherQueue) {
    copylist(otherQueue);
}

template<class Type>
int queue1<Type>::get_size() {
    return count;
}

template<class Type>
const queue1<Type> &queue1<Type>::operator=(const queue1<Type> &otherlist) {
    if (this != &otherlist) {
        copylist(otherlist);
    }
    return *this;
}

////////////////////////////////////////////////////////////////// queue based linked list

template<class Type>
bool queue2<Type>::is_empty() const {
    return (queueFront == NULL);
}

template<class Type>
bool queue2<Type>::is_full() const {
    return false;
}

template<class Type>
void queue2<Type>::initialize() {
    nodeType<Type> *temp;
    while (queueFront != NULL) {
        temp = queueFront;
        queueFront = queueFront->link;
        delete temp;
    }
    queueRear = NULL;
}

template<class Type>
void queue2<Type>::addQueue(const Type &queueElement) {
    nodeType<Type> *newnode;
    newnode = new nodeType<Type>;
    newnode->info = queueElement;
    newnode->link = NULL;

    if (queueFront == NULL) {
        queueFront = newnode;
        queueRear = newnode;
    } else {
        queueRear->link = newnode;
        queueRear = newnode;
    }
}

template<class Type>
Type queue2<Type>::front() const {
    assert(queueFront != NULL);
    return queueFront->info;
}

template<class Type>
Type queue2<Type>::back() const {
    assert(queueRear != NULL);
    return queueRear->info;
}

template<class Type>
void queue2<Type>::deleteQueue() {
    nodeType<Type> *temp;
    if (!is_empty()) {
        temp = queueFront;
        queueFront = queueFront->link;
        delete temp;
        if (queueFront == NULL) {
            queueRear = NULL;
        }
    } else {
        cout << "cannot remove from an empty queue.." << endl;
    }
}

template<class Type>
void queue2<Type>::copylist(const queue2<Type> &otherlist) {
    nodeType<Type> *newnode; // to create new linkedlist
    nodeType<Type> *temp;    // to points to other list
    nodeType<Type> *last;    // to points to last node added to new linked list

    temp = otherlist.queueFront;
    newnode = new nodeType<Type>;

    newnode->info = temp->info;
    newnode->link = NULL;

    queueFront = newnode;
    last = newnode;
    temp = temp->link;
    while (temp != NULL) {
        newnode = new nodeType<Type>;
        newnode->info = temp->info;
        newnode->link = NULL;
        last->link = newnode;
        last = newnode;
        temp = temp->link;
    }
    queueRear = last;
    queueRear->link = NULL ; 
}

template<class Type>
const queue2<Type> &queue2<Type>::operator=(const queue2<Type> &ohterlist) {
    if (this != &ohterlist) {
        copylist(ohterlist);
    }
    return *this;
}

template<class Type>
queue2<Type>::queue2() {
    queueFront = NULL;
    queueRear = NULL;
}

template<class Type>
queue2<Type>::queue2(const queue2<Type> &ohterlist) {
    copylist(ohterlist) ;
}

template<class Type>
queue2<Type>::~queue2(){
    initialize() ;
}


