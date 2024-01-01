//
// Created by Elaraby on 29/09/2023.
//

#include<iostream>

template <class Type>
class orderedLinkedList : public linkedListType<Type> {
public:
    bool search(const Type& serchItem) const ;
    // Function to determine whether searchItem is in the list or not
    //Postcondition: Returns true if searchItem is in the list,
    // otherwise the value false is returned.

    void insert(const Type& newItem) ;
    // function to insert newitem in the list
    //Postcondition: first points to the new list, newItem
    // is inserted at the proper place in the list, and count is incremented by 1.

    void insert_first(const Type& newItem) ;
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    // inserted at the beginning of the list, last points to the
    // last node in the list, and count is incremented by 1.

    void insert_last(const Type& newItem) ;
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    // inserted at the beginning of the list, last points to the
    // last node in the list, and count is incremented by 1.

    void deleteNode(const Type& deleteItem) ;
    // function to delete deleteItem from the list .
    //Postcondition: If found, the node containing deleteItem is
    // deleted from the list; first points to the first node
    // of the new list, and count is decremented by 1. If
    // deleteItem is not in the list, an appropriate message is printed.
};


