//
// Created by Administrator on 30/09/2023.
//

#ifndef DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H
#define DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H


template<class Type>
struct nodeType {
    Type info ;
    nodeType<Type>*next ;
    nodeType<Type>*back ;
};

template<class Type>
class DoublyLinkedList {
private:
    void copyList(const DoublyLinkedList<Type>&otherlist) ;
    //Function to make a copy of otherList.
    //Postcondition: A copy of otherList is created and assigned to this list.

protected:
    int count ;
    nodeType<Type> *first ;
    nodeType<Type> *last  ;

public:
    DoublyLinkedList();
    //Default constructor
    //Initializes the list to an empty state

    DoublyLinkedList(const DoublyLinkedList<Type>&otherList) ;
    // copy constructor

    ~DoublyLinkedList();
    //destructor

    const DoublyLinkedList<Type>& operator=(const DoublyLinkedList<Type> &);
    //Overload the assignment operator

    void initializeList();
    //Function to initialize the list to an empty state.

    bool is_empty() const ;
    //Function to determine whether the list is empty.
    //Postcondition: Returns true if the list is empty,
    // otherwise returns false

    void destory() ;
    //Function to delete all the nodes from the list.
    //Postcondition: first = NULL; last = NULL; count = 0;

    void print() const;
    //Function to output the info contained in each node.

    void reversePrint() const;
    //Function to output the info contained in each node
    //in reverse order.

    int length() const;
    //Function to return the number of nodes in the list.
    //Postcondition: The value of count is returned.

    Type front() const;
    //Function to return the first element of the list.
    //Precondition: The list must exist and must not be empty.
    //Postcondition: If the list is empty, the program terminates;
    // otherwise, the first element of the list is returned.

    Type back() const;
    //Function to return the last element of the list.
    //Precondition: The list must exist and must not be empty.
    //Postcondition: If the list is empty, the program terminates;
    // otherwise, the last element of the list is returned.

    bool search(const Type& searchItem) const;
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is found in the
    // list, otherwise returns false.

    void insert(const Type& insertItem);
    //Function to insert insertItem in the list.
    //Precondition: If the list is nonempty, it must be in order.
    //Postcondition: insertItem is inserted at the proper place
    // in the list, first points to the first node, last points
    // to the last node of the new list, and count is
    // incremented by 1.

    void deleteNode(const Type& deleteItem);
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing deleteItem is
    // deleted from the list; first points to the first node of
    // the new list, last points to the last node of the new
    // list, and count is decremented by 1; otherwise an
    // appropriate message is printed.

};


#endif //DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H
