//
// Created by Elaraby on 29/09/2023.
//
#include<bits/stdc++.h>
#include "linkedListIterator.h"
#include "linkedListType.h"
#include "orderedLinkedList.h"
#include "unorderedLinkedList.h"

using namespace std ;

//////////////////////////////////////////////////// linked list iterator


template<class Type>
linkedListIterator<Type>::linkedListIterator() {
    current = NULL ;
}

template<class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr){
    current = ptr ;
}

template<class Type>
Type linkedListIterator<Type>::operator*() {
    return current->info ;
}

template<class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++(int) {
    current = current->link ;
    return *this ;
}

template<class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++() {
    current = current->link ;
    return *this ;
}

template<class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type> &right) const {
    return (current == right.current) ;
}

template <class Type>
bool linkedListIterator<Type>::operator!= (const linkedListIterator<Type>& right) const {
    return (current != right.current);
}

//////////////////////////////////////////////////// linked list Type




using namespace std ;
template<class Type>
bool linkedListType<Type>::is_empty() const {
    return (first == NULL) ;
}

template<class Type>
linkedListType<Type>::linkedListType() {
    first = NULL ;
    last  = NULL ;
    count = 0 ;
}

template<class Type>
void linkedListType<Type>::destroyList() {
    nodeType<Type> *temp ;      // pinter to deallocate the memory occupied by the node
    while(first!=NULL){
        temp = first ;          // set temp to the current node
        first = first->link;    // advance first to the next node
        delete temp ;           // deallocate the memory occupied by temp
    }
    last = NULL ;
    count = 0 ;
}

template<class Type>
void linkedListType<Type>::initializeList() {
    destroyList() ;
}

template<class Type>
void linkedListType<Type>::print() const {
    nodeType<Type>* current ;
    current = first ;
    while(current!=NULL){
        cout << current->info << " " ;
        current = current->link ;
    }
    cout << endl ;
}

template<class Type>
int linkedListType<Type>::length() const {
    return count ;
}

template <class Type>
Type linkedListType<Type>::front() const {
    assert(first != NULL);
    return first->info;
}

template <class Type>
Type linkedListType<Type>::back() const {
    assert(last != NULL);
    return last->info;
}

template<class Type>
linkedListIterator<Type> linkedListType<Type>::begin() {
    linkedListIterator<Type>temp(first) ;
    return temp ;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end() {
    linkedListIterator<Type> temp(NULL);
    return temp;
}

template<class Type>
void linkedListType<Type>::copyList(const linkedListType<Type> &otherList) {
    nodeType<Type>*current ;   // pointer to traverse the list
    nodeType<Type>*newNode ;   // pointer to create a node

    if(first!=NULL){
        destroyList() ;   // if the list is none empty make it empty
    }
    if(otherList.first==NULL) {  // other list is empty
        first = NULL ;
        last  = NULL ;
        count = 0 ;
    } else {
        current = otherList.first ;
        count   = otherList.count ;

        first = new nodeType<Type> ;    // create the node
        first->info = current->info ;   // copy info
        first->link = current->link ;   // copy link
        last = first ;
        current = current->link ;

        while(current!=NULL){
            newNode = new nodeType<Type> ;
            newNode->info = current->info ;
            newNode->link = NULL ; // it will be the last node
            last->link = newNode ;
            last = newNode ;
            current = current->link ;
        } // end while
    } // end else
} // end copylist

template <class Type>
linkedListType<Type>::~linkedListType() {  // destructor
    destroyList();
}

// copy constructor
template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList) {
    first = NULL;
    copyList(otherList);
}

//overload the assignment operator
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
        (const linkedListType<Type>& otherList) {
    if (this != &otherList) //avoid self-copy
    {
        copyList(otherList);
    }//end else
    return *this;
}


//////////////////////////////////////////////////////////////////////// unordered linked list




template<class Type>
bool unorderedLinkedList<Type>::search(const Type &serchItem) const {
    nodeType<Type> *current ;
    current = this->first;  // why ( current = first ) does not work ?!

    while(current!=NULL){
        if(current->info == serchItem){
            return true ;
        }
        current = current->link ;
    }
    return false ;
}

template<class Type>
void unorderedLinkedList<Type>::insert_first(const Type &newItem) {
    nodeType<Type>*newNode ;
    newNode = new nodeType<Type> ;
    newNode->info = newItem ;
    newNode->link = this->first ;
    this->first = newNode ;
    this->count++ ;

    if(this->last == NULL){  // if the list was empty, newnode is also the last node in the list
        this->last = newNode ;
    }
}

template<class Type>
void unorderedLinkedList<Type>::insert_last(const Type &newItem) {
    nodeType<Type> *newNode ;
    newNode = new nodeType<Type> ;
    newNode->info = newItem ;
    newNode->link = NULL ;

    if(this->first == NULL){ // if the list is empty, newnode is both the first and last node
        this->first = newNode ;
        this->last  = newNode ;
    } else {
        this->last->link = newNode ;
        this->last = newNode ;
    }
    this->count++ ;
}

template<class Type>
void unorderedLinkedList<Type>::deleteNode(const Type &deleteItem) {
    nodeType<Type> *current ;    // to traverse the list
    nodeType<Type> *trailCurrent ; // before current ;

    if(this->first == NULL){
        cout << "can not delete from an empty list " << endl;
    } else {
        if(this->first->info == deleteItem){
            current = this->first ;
            this->first = this->first->link ;

            if(this->first == NULL){  // it means the list has only one node
                this->last = NULL ;
            }
            delete current ;
            this->count-- ;
        } else {
            trailCurrent = this->first ;
            current = this->first->link ;
            bool found = false ;
            while(current != NULL && !found){
                if(current->info != deleteItem){
                    trailCurrent = current ;
                    current = current->link ;
                } else {
                    found = true ;
                }
            }
            if(found){
                trailCurrent->link = current->link ;
                this->count-- ;
                if(this->last == current){ // node to be deleted is the last node
                    this->last = trailCurrent ;
                }
                delete current ;
            } else {
                cout << "the item to be deleted is not in the list .." << endl ;
            }
        } // end else
    } // end else
} // end delete_Node


////////////////////////////////////////////////////////////////////////////  ordered linked list



template<class Type>
bool orderedLinkedList<Type>::search(const Type &serchItem) const {
    bool found = false;
    nodeType<Type> *current;
    current = this->first;
    while (current != NULL && !found) {
        if (current->info >=
            serchItem) {  // because it is ordered linked list (sorted) we do not need check element greater than searchItem
            found = true;
        } else {
            current = current->link;
        }
    }
    if (found) {
        found = (current->info == serchItem);
    }
    return found;
}


template<class Type>
void orderedLinkedList<Type>::insert(const Type &newItem) {
    nodeType<Type> *current, *trailCurrnet, *newNode;
    bool found;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = NULL;

    if (this->first == NULL) {
        // the list is initially empty ;
        this->first = newNode;
        this->last = newNode;
        this->count++;
    } else {
        current = this->first;
        found = false;
        while (current != NULL && !found) {
            if (current->info >= newItem) {
                found = true;
            } else {
                trailCurrnet = current;
                current = current->link;
            }
        }
        if (current == this->first) {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        } else {
            trailCurrnet->link = newNode;
            newNode->link = current;
            if (current == NULL) {
                this->last = newNode;
            }
            this->count++;
        }
    }
} // end insert


template<class Type>
void orderedLinkedList<Type>::insert_first(const Type &newItem) {
    insert(newItem);
}//end insertFirst

template<class Type>
void orderedLinkedList<Type>::insert_last(const Type &newItem) {
    insert(newItem);
}//end insertLast


template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type &deleteItem) {
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found;

    if (this->first == NULL) {
        cout << "cannot delete from an empty linked list." << endl;
    } else {
        current = this->first;
        found = false;

        while (current != NULL && !found) {
            if (current->info >= deleteItem)
                found = true;
            else {
                trailCurrent = current;
                current = current->link;
            }
        }

        if(current == NULL){
            cout << "The item to be deleted is not in the list" << endl ;
        } else {
            if(current->info == deleteItem){
                if(this->first == current){
                    this->first = this->first->link ;
                    if(this->first == NULL){
                        this->last = NULL ;
                    }
                    delete current ;
                } else {
                    trailCurrent->link = current->link ;
                    if(current == this->last){
                        this->last = trailCurrent ;
                    }
                    delete current ;
                }
                this->count-- ;
            } else {
                cout << "the item to be deleted is not in teh list" << endl ;
            }
        }
    }
}


