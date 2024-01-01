#include <iostream>
#include "DoublyLinkedList.cpp"
using namespace std ;
int main() {
    DoublyLinkedList<int> d1 ;
    DoublyLinkedList<string>d2 ;


    for(int i=0 ; i<5 ; i++){
        int x ; cin >> x ;
        d1.insert(x) ;
    }
    cout << d1.length() << endl ;
    d1.print();
    cout << endl ;
    d1.reversePrint() ;
    cout << endl ;
    cout << d1.is_empty() << endl ;
    cout << d1.back() << endl ;
    cout << d1.front() << endl ;
    cout << "Enter item to search for ..." ;
    int item ;
    cin >> item ;
    cout << d1.search(item) << endl ;
    cout << "Enter item to delete from the list..." ;
    cin >> item ;
    d1.deleteNode(item);
    d1.print() ;
    cout << endl ;
    DoublyLinkedList<int>d3(d1) ;
    cout << "lab" << endl ;
    d3.print() ;
    d3.initializeList() ;
    cout << "the list after initialized .. " << endl ;
    d3.print() ;
    cout << endl ;
}
