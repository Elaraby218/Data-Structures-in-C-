//
// Created by Elaraby on 28/09/2023.
//


template<class Type>
class linkedListType {
private:
    void copyList(const linkedListType<Type>&otherList) ;
    //Function to make a copy of otherList.
    //Postcondition: A copy of otherList is created and assigned to this list.

    //Declared as a private member. This is because this function is used
    //only to implement the copy constructor and overload the assignment operator.

protected:
    int count ;              // to store the number of list elements(nodes)
    nodeType<Type>*first ;   // pointer to the first node of the list ;
    nodeType<Type>*last  ;   // pointer to the last node of the list ;

public:
    linkedListType() ;
    //default constructor

    linkedListType(const linkedListType<Type>& ohterList) ;
    // copy constructor ;

    ~linkedListType();
    //destructor -> delete all nodes form the list

    const linkedListType<Type>& operator=(const linkedListType<Type>&) ;
    //overload the assignment operator ;

    void initializeList() ;
    // initialize the list ot an empty state. ;
    // Postcondition: first = NULL, last = NULL, count = 0;

    bool is_empty()const ;
    //Function to determine whether the list is empty.
    //Postcondition: Returns true if the list is empty, otherwise it returns false.

    void print() const;
    //Function to output the data contained in each node.

    int length() const;
    //Function to return the number of nodes in the list.
    //Postcondition: The value of count is returned.

    void destroyList();
    //Function to delete all the nodes from the list.
    //Postcondition: first = NULL, last = NULL, count = 0;

    Type front() const;
    //Function to return the first element of the list.
    //Precondition: The list must exist and must not be empty.
    //Postcondition: If the list is empty, the program terminates;
    // otherwise, the first element of the list is returned.

    Type back() const;
    //Function to return the last element of the list.
    //Precondition: The list must exist and must not be empty.
    //Postcondition: If the list is empty, the program
    // terminates; otherwise, the last element of the list is returned.

    virtual bool search(const Type& serchItem) const = 0 ;
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the list, otherwise the value false is returned.

    virtual void insert_first(const Type& newItem) = 0  ;
    // function to insert newItem at the beginning of the list ;
    //Postcondition: first points to the new list, newItem is
    // inserted at the beginning of the list, last points to
    // the last node in the list, and count is incremented by 1.

    virtual void insert_last(const Type& newItem) = 0 ;
    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem is
    // inserted at the end of the list, last points to the
    // last node in the list, and count is incremented by 1.

    virtual void deleteNode(const Type& deleteItem) = 0 ;
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing deleteItem is
    // deleted from the list. first points to the first node,
    // last points to the last node of the updated list, and count is decremented by 1.

    linkedListIterator<Type> begin() ;
    //Function to return an iterator at the beginning of the linked list.
    //Postcondition: Returns an iterator such that current is set to first.

    linkedListIterator<Type> end() ;
    //Function to return an iterator one element past the last element of the linked list.
    //Postcondition: Returns an iterator such that current is set to NULL.

};




