#include <bits/stdc++.h>
#include "implementationFile.cpp"
using namespace std ;
int main() {
    /////////////////////////////////////////////////// test unorderd linked list (int)

    cout << "---------test unordered linked list ----------------" << endl ;
    int size ;
    cout << "enter linked list size to create .." << endl ;
    cin >> size ;
    unorderedLinkedList<int> U_ls ;
    cout << "insert your items .." << endl ;
    for(int i=0 ; i<size ; i++){
        int num ;
        cin >> num ;
        U_ls.insert_last(num) ;
    }
    cout << "enter an item to insert first " << endl ;
    int n ;
    cin >> n ;
    U_ls.insert_first(n) ;
    cout << "the linked list you enterd is .. " << endl ;
    U_ls.print() ;
    cout << endl ;
    cout << "thie linked list size is" << " " << U_ls.length() << endl ;
    cout << "the state of the list (empty or not) is .. " << " " << U_ls.is_empty() << endl ;
    cout << "list.front is " << U_ls.front() << endl ;
    cout << "list.back is " << U_ls.back() << endl ;
    cout << endl ;
    cout << "enter item to search for it in the list .. " << endl ;
    int item ;
    cin >> item ;
    bool found = U_ls.search(item) ;
    if(found){
        cout << "the item is in the list // " << endl  ;
    } else {
        cout << "the item is not in the list" << endl ;
    }

    cout << endl << " enter item to delete from the list " << endl ;
    cin >> item ;
    U_ls.deleteNode(item) ;
    cout << "the list after delete the item is .. " << endl ;
    U_ls.print() ;
    cout << endl ;
    cout << "-------------------------------- end test -----------------------------------" << endl;

    //////////////////////////////////////////////////////// test iterator
    cout << "--------------------------test iterator------------------------" << endl ;
    linkedListIterator<int>it(U_ls.begin()) ;
    cout << "linked list we have .." << endl ;
    U_ls.print() ;
    cout << "derefrence the iterator " << *it << endl ;
    it++ ;
    cout << "dereference it++ " << *it << endl ;

    if(*it == *(++it)){
        cout << "it and ++it are equal" << endl ;
    } else {
        cout << "it and ++it are not equal" << endl ;
    }
    cout << "-------------------------------- end test -----------------------------------" << endl;

    //////////////////////////////////////////////////////// test ordered set
    cout << "--------------------------test ordered linked list--------------------------" << endl ;
    orderedLinkedList<int> ordered_list ;
    cout << "enter linked list size to create .." << endl ;
    cin >> size ;
    cout << "insert your items .." << endl ;
    for(int i=0 ; i<size ; i++){
        int num ;
        cin >> num ;
        ordered_list.insert_first(num) ;
    }
    cout << "enter an item to insert first " << endl ;
    cin >> n ;
    ordered_list.insert_first(n) ;
    cout << "the linked list you enterd is .. " << endl ;
    ordered_list.print() ;
    cout << endl ;
    cout << "thie linked list size is" << " " << ordered_list.length() << endl ;
    cout << "the state of the list (empty or not) is .. " << " " << ordered_list.is_empty() << endl ;
    cout << "list.front is " << ordered_list.front() << endl ;
    cout << "list.back is " << ordered_list.back() << endl ;
    cout << endl ;
    cout << "enter item to search for it in the list .. " << endl ;
    cin >> item ;
    found = ordered_list.search(item) ;
    if(found){
        cout << "the item is in the list // " << endl  ;
    } else {
        cout << "the item is not in the list" << endl ;
    }

    cout << endl << " enter item to delete from the list " << endl ;
    cin >> item ;
    ordered_list.deleteNode(item) ;
    cout << "the list after delete the item is .. " << endl ;
    ordered_list.print() ;
    cout << endl ;
    cout << "-------------------------------- end test -----------------------------------" << endl;
}
