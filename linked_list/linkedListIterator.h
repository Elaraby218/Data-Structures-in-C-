//
// Created by Elaraby on 27/09/2023.
//

#ifndef LINKED_LIST_LINKEDLISTITERATOR_H
#define LINKED_LIST_LINKEDLISTITERATOR_H

template<class Type>
struct nodeType{
    Type info ;
    nodeType<Type> *link ; // points to the next node
};

template<class Type>
class linkedListIterator {
private:
    nodeType<Type>*current ;
public:
    linkedListIterator() ;
    // defult constructor

    linkedListIterator(nodeType<Type>*ptr) ;
    // parameteraized constructor

    Type operator*() ;
    //Function to overload the dereferencing operator *.
    //Postcondition: Returns the info contained in the node.

    linkedListIterator<Type>operator++(int) ;
    //Overload the preincrement operator.
    //Postcondition: The iterator is advanced to the next node.

    linkedListIterator<Type>operator++() ;
    //Overload the preincrement operator.
    //Postcondition: The iterator is advanced to the next node.

    bool operator==(const linkedListIterator<Type>& right) const ;
    //Overload the equality operator.
    //Postcondition: Returns true if this iterator is equal to
    // the iterator specified by right, otherwise it returns false.

    bool operator!=(const linkedListIterator<Type>& right) const ;
    // Overload the not equal to operator
    //Postcondition: Returns true if this iterator is not equal to
    // the iterator specified by right, otherwise it returns false.
};


#endif //LINKED_LIST_LINKEDLISTITERATOR_H
