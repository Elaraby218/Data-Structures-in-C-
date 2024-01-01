//
// Created by Elaraby on 29/09/2023.
//

using namespace std ;
template<class Type>
class unorderedLinkedList : public linkedListType<Type> {

public:
    bool search(const Type& serchItem) const ;
    // Function to determine whether serchItem is in the list
    // Postcondition: returns true if serchITem is in the list otherwise the
    // value false is returned .

    void insert_first(const Type& newItem)  ;
    // function to insert newItem at the beginning of the list ;
    //Postcondition: first points to the new list, newItem is
    // inserted at the beginning of the list, last points to
    // the last node in the list, and count is incremented by 1.

    void insert_last(const Type& newItem) ;
    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem is
    // inserted at the end of the list, last points to the
    // last node in the list, and count is incremented by 1.

    void deleteNode(const Type& deleteItem) ;
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing deleteItem is
    // deleted from the list. first points to the first node,
    // last points to the last node of the updated list, and count is decremented by 1.

};




