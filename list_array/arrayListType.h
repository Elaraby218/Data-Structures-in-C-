template <class Type>
class arrayListType{
protected:
    Type *list ;  // array to hold the list elements
    int length ;  // to store the length of the list
    int maxsize;  // to store the maximum size of the list


public:
    arrayListType(int size = 100) ; // line 109 at source file
    //constructor
    //Creates an array of the size specified by the
    //parameter size. The default array size is 100.
    //Postcondition: The list points to the array, length = 0,
    // and maxSize = size

    arrayListType(const arrayListType<Type>& otherList); // line 128 at source file
    //copy constructor

    ~arrayListType(); // line 122 at source file
    //destructor
    //Deallocates the memory occupied by the array.

    const arrayListType<Type>& operator=(const arrayListType<Type>&otherlist) ; // line 140 at source file

    bool is_empty() const ;  // line 7 at source file
    // function to determine whether the list is empty or not
    //Postcondition: Returns true if the list is empty;
    // otherwise, returns false.

    bool is_full() const ;  // line 11 at source file
    // function to determine whether the list is full or not.
    //Postcondition: Returns true if the list is full;
    // otherwise, returns false.

    int list_size() const ;    // line 16 at source file
    // function to determine the size of the list

    int maxListSize() const;   // line 22 at source file
    //Function to determine the size of the list.

    void print() const ;    // line 29 at the source file
    //Function to output the elements of the list

    bool is_item_equal(int location , const Type& item) const ;   // line 37 at the source file
    //Function to determine whether the item is the same
    //as the item in the list at the position specified by location
    //Postcondition: Returns true if list[location]
    //is the same as the item; otherwise,
    // returns false

    void insert_at(int location , const Type& item) ;  // line 46
    //Function to insert an item in the list at the
    //position specified by location. The item to be inserted
    //is passed as a parameter to the function.
    //Postcondition: Starting at location, the elements of the
    //list are shifted down, list[location] = item;,
    //and length++;. If the list is full or location is
    //out of range, an appropriate message is displayed.

    void insert_end(const Type& item); // line 63
    //Function to insert an item at the end of the list.
    //The parameter Item specifies the item to be inserted.
    //Postcondition: list[length] = item; and length++;
    //If the list is full, an appropriate message is displayed.

    void remove_at(int location) ; // line 74
    //Function to remove the item from the list at the position specified by location
    //Postcondition: The list element at list[location] is removed
    // and length is decremented by 1. If location is out of
    // range, an appropriate message is displayed.

    void retrieve_at(int location , Type& retitem) const ;  // line 86
    //Function to retrieve the element from the list at the
    //position specified by location.
    //Postcondition: retItem = list[location]
    // If location is out of range, an appropriate message is displayed.

    void replaceAt(int location, const Type& repItem); // line 95
    //Function to replace the elements in the list at the
    //position specified by location. The item to be replaced
    //is specified by the parameter repItem.
    //Postcondition: list[location] = repItem
    // If location is out of range, an appropriate message is displayed.

    void clear_list() ;  // line 104
    // function to remove all the elements from the list.
    // after this operation the size of the list is zero

    int seq_search (const Type& item) const ; // line 158
    //function to search the list for a given item.
    //Postcondition: If the item is found, returns the location
    //in the array where the item is found; otherwise, returns -1.

    void insert(const Type& item) ; // line 168
    //Function to insert the item specified by the parameter
    //item at the end of the list. However, first the
    //list is searched to see whether the item to be inserted is already in the list.
    //Postcondition: list[length] = insertItem and length++
    //If the item is already in the list or the list
    //is full, an appropriate message is displayed.

    void remove(const Type& removeItem); // 184
    //Function to remove the firs occurence of an item from the list. The parameter
    //removeItem specifies the item to be removed.
    //Postcondition: If removeItem is found in the list,
    // it is removed from the list and length is decremented by one.

};