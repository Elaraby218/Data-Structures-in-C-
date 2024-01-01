//
// Created by mohamed Elaraby on 25/09/2023.
//
#include "arraylisttype.h"
#include<iostream>
using namespace std ;

template<class Type>
bool arrayListType<Type>:: is_empty() const {
    return (length == 0) ;
}

template<class Type>
bool arrayListType<Type>::is_full() const {
    return (length == maxsize) ;
}

template<class Type>
int arrayListType<Type>::list_size() const {
    return length ;
}

template<class Type>
int arrayListType<Type>::maxListSize() const {
    return maxsize ;
}

template<class Type>
void arrayListType<Type>::print() const {
    for(int i=0 ; i<length ; i++){
        cout << list[i] << " " ;
    }
    cout << endl ;
}

template<class Type>
bool arrayListType<Type>::is_item_equal(int location, const Type &item) const {
    if(location >= length){
        cerr << "location does not found .." << endl ;
        return false ;
    }
    return(list[location]==item) ;
}

template<class Type>
void arrayListType<Type>::insert_at(int location, const Type &item) {
    if(location < 0 || location >=maxsize){
        cerr << "the position of the item to be inserted " << "is out of range " << endl ;
    } else {
        if(length >= maxsize){
            cerr << "cannot insert in a full list " << endl ;
        } else {
            for(int i= length ; i>location ; i--){
                list[i] = list[i-1] ;  // move the elemnts down to creat a room for a new elemnt
            }
            list[location] = item ;
            length++ ;
        }
    }
} // end insert_at

template<class Type>
void arrayListType<Type>::insert_end(const Type &item) {
    if (length >= maxsize) //the list is full
        cerr << "Cannot insert in a full list" << endl;
    else
    {
        list[length] = item; //insert the item at the end
        length++; //increment the length
    }
}

template<class Type>
void arrayListType<Type>::remove_at(int location) {
    if(location < 0 || location >= length){
        cerr << "the position of the item to be inserted " << "is out of range " << endl ;
    } else {
        for(int i=location ; i<length ; i++){
            list[i] = list[i+1] ;
        }
        length-- ;
    }
} // end remove_at

template<class Type>
void arrayListType<Type>::retrieve_at(int location, Type &retitem) const {
    if(location < 0 || location>=length){
        cerr << "the position of the item to be inserted " << "is out of range " << endl ;
    } else {
        retitem = list[location] ;
    }
}

template<class Type>
void arrayListType<Type>::replaceAt(int location, const Type &repItem) {
    if(location < 0 || location>=length){
        cerr << "the position of the item to be inserted " << "is out of range " << endl ;
    } else {
        list[location] = repItem ;
    }
}

template<class Type>
void arrayListType<Type>::clear_list() {
    length = 0 ;
}

template<class Type>
arrayListType<Type>::arrayListType(int size) {
    if(size <0){
        cerr << "the array size must be positive. " << endl << "Creating an array of size 100 ..." << endl ;
        maxsize = 100 ;
    } else {
        maxsize = size ;
    }
    length = 0 ;
    list = new Type[maxsize] ;
    //  assert(list!=NULL) ;  //terminate if unable to allocate memory space
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete [] list;
}

template<class Type>
arrayListType<Type>::arrayListType(const arrayListType<Type> &otherList) {
    maxsize = otherList.maxsize ;
    length  = otherList.length ;
    list    = new Type[maxsize] ;
    // assert(list!=NULL) ;   //terminate if unable to allocate memory space

    for(int i=0 ; i<length ; i++){
        list[i] = otherList.list[i] ;
    }
}

template<class Type>
const arrayListType<Type>& arrayListType<Type>::operator=(const arrayListType<Type> & otherlist) {
    if(this != &otherlist){ // avoid self_assignment
        delete [] list ;
        maxsize = otherlist.maxsize ;
        length = otherlist.length ;

        list = new Type[maxsize] ; // create the array
        // assert(list!=NULL); // if unable to allocate memory space, terminate the program

        for(int i=0 ; i<length ; i++){
            list[i] = otherlist.list[i] ;
        }

        return *this ; // inseat of creating temp calss object we make the object who called the function to be the temp one
    }
}

template <class Type>
int arrayListType<Type>::seq_search(const Type &item) const {
    for(int i=0 ; i<length ; i++){
        if(list[i]==item){
            return i ;   // if the item is found return its location (i)
        }
    }
    return -1 ; // if not found return -1 ;
}

template<class Type>
void arrayListType<Type>::insert(const Type &item) {
    if(length == maxsize){
        cerr << "cannot insert in a full list..." << endl ;
    } else if(length == 0){
        list[length++] = item ;
    } else {
        int idx = seq_search(item) ;
        if(idx == -1){
            list[length++] = item ;
        } else {
            cerr << "the item to be inserted is already in the list, no duplicates are allowed" << endl ;
        }
    }
}

template<class Type>
void arrayListType<Type>::remove(const Type &removeItem) {
    if(length == 0){
        cerr << "cannot delete from an empty list." << endl ;
    } else {
        int idx = seq_search(removeItem) ;
        if(idx != -1){
            remove_at(idx) ;
        } else {
            cout << "the item to be deleted is not in the list " << endl ;
        }
    }


}