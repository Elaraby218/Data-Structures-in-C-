//
// Created by Administrator on 30/09/2023.
//

#include "DoublyLinkedList.h"
#include <bits/stdc++.h>

using namespace std;

template<class Type>
DoublyLinkedList<Type>::DoublyLinkedList() {
    first = NULL;
    last = NULL;
    count = 0;
}

template<class Type>
DoublyLinkedList<Type>::~DoublyLinkedList() {
    destory();
}

template<class Type> /// wrong hehe
void DoublyLinkedList<Type>::copyList(const DoublyLinkedList<Type> &otherlist) {
    nodeType<Type> *newNode;
    nodeType<Type> *current;

    if(otherlist.first == NULL){
        first =NULL;
        last  =NULL;
        count = 0 ;
    } else {
        current = otherlist.first ;
        count = otherlist.count ;
        first = new nodeType<Type> ;
        first->info = current->info ;
        first->next = NULL ;
        first->back = NULL ;
        last = first ;
        nodeType<Type> *trailerCurrent ;
        trailerCurrent = first ;
        current = current->next ;
        while(current!=NULL){
            nodeType<Type> *toadd ;
            toadd = new nodeType<Type> ;
            toadd->info = current->info ;
            toadd->next = NULL ;
            toadd->back = trailerCurrent ;
            last = toadd ;
            trailerCurrent->next = toadd ;
            trailerCurrent = trailerCurrent->next ;
            current = current->next ;
        }
    }
}

template<class Type>
DoublyLinkedList<Type>::DoublyLinkedList(const DoublyLinkedList<Type>&otherList){
    first=NULL ;
    copyList(otherList) ;
}

template<class Type>
bool DoublyLinkedList<Type>::is_empty() const {
    return (first == last);
}

template<class Type>
void DoublyLinkedList<Type>::destory() {
    nodeType<Type> *temp;
    while (first != NULL) {
        temp = first;
        first = first->next;
        delete temp;
    }
    last = NULL;
    count = 0;
}

template<class Type>
void DoublyLinkedList<Type>::initializeList() {
    destory();
}

template<class Type>
int DoublyLinkedList<Type>::length() const {
    return count;
}


template<class Type>
void DoublyLinkedList<Type>::print() const {
    nodeType<Type> *current; //pointer to traverse the list
    current = first;         //set current to point to the first node
    while (current != NULL) {
        cout << current->info << " "; //output info
        current = current->next;
    }
}

template<class Type>
void DoublyLinkedList<Type>::reversePrint() const {
    nodeType<Type> *current; //pointer to traverse the list
    current = last;          //set current to point to the last node
    while (current != NULL) {
        cout << current->info << " ";
        current = current->back;
    }
}

template<class Type>
bool DoublyLinkedList<Type>::search(const Type &searchItem) const {
    bool found = false;
    nodeType<Type> *current;
    current = first;
    while (current != NULL && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->next;
    if (found)
        found = (current->info == searchItem);
    return found;
}

template<class Type>
Type DoublyLinkedList<Type>::front() const {
    assert(first != NULL);
    return first->info;
}

template<class Type>
Type DoublyLinkedList<Type>::back() const {
    assert(last != NULL);
    return last->info;
}

template<class Type>
void DoublyLinkedList<Type>::insert(const Type &insertItem) {
    nodeType<Type> *current;      //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    nodeType<Type> *newNode;      //pointer to create a node
    bool found;
    newNode = new nodeType<Type>; //create the node
    newNode->info = insertItem;   //store the new item in the node
    newNode->next = NULL;
    newNode->back = NULL;
    if (first == NULL) {            //if list is empty, newNode is the only node
        first = newNode;
        last = newNode;
        count++;
    } else {
        found = false;
        current = first;
        while (current != NULL && !found)
            if (current->info >= insertItem)
                found = true;
            else {
                trailCurrent = current;
                current = current->next;
            }
        if (current == first) {
            first->back = newNode;
            newNode->next = first;
            first = newNode;
            count++;
        } else {

            if (current != NULL) {
                trailCurrent->next = newNode;
                newNode->back = trailCurrent;
                newNode->next = current;
                current->back = newNode;
            } else {
                trailCurrent->next = newNode;
                newNode->back = trailCurrent;
                last = newNode;
            }
            count++;
        }//end else
    }//end else
}//end insert


template<class Type>
void DoublyLinkedList<Type>::deleteNode(const Type &deleteItem) {
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;
    if (first == NULL)
        cout << "Cannot delete from an empty list." << endl;
    else if (first->info == deleteItem) {
        current = first;
        first = first->next;
        if (first != NULL)
            first->back = NULL;
        else
            last = NULL;
        count--;
        delete current;
    } else {
        found = false;
        current = first;
        while (current != NULL && !found) //search the list
            if (current->info >= deleteItem)
                found = true;
            else
                current = current->next;
        if (current == NULL)
            cout << "The item to be deleted is not in "
                 << "the list." << endl;
        else if (current->info == deleteItem) {
            trailCurrent = current->back;
            trailCurrent->next = current->next;
            if (current->next != NULL)
                current->next->back = trailCurrent;
            if (current == last)
                last = trailCurrent;
            count--;
            delete current;
        } else
            cout << "The item to be deleted is not in list." << endl;
    }//end else
}//end deleteNode
