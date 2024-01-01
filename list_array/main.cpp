#include "arraylisttype.cpp"
#include <iostream>

using namespace std ;
int main() {
    arrayListType<int> intlist(100) ;
    arrayListType<string> stringlist ;

    int number ;
    cout << "enter 5 intgers to test intlist" << endl ;
    for(int i=0 ; i<5 ; i++){
        cin >> number ;
        intlist.insert_at(i,number) ;;
    }
    cout << endl ;
    cout << "the list your entered is .. " << endl ;
    intlist.print() ;
    cout << endl ;

    cout << "enter item to be deleted .." << endl ;
    cin >> number ;
    intlist.remove(number) ;
    cout << "your list after removing item " << number << endl ;
    intlist.print() ;
    cout << endl ;

    string str ;
    cout << "enter 5 strings " << endl ;
    for(int i=0 ; i<5 ; i++){
        cin >> str ;
        stringlist.insert_at(i,str) ;
    }

    cout << endl ;
    cout << "you enter .. " << endl;
    stringlist.print() ;
    cout << endl ;

    cout << "enter string to be deleted" << endl ;
    cin >> str ;
    stringlist.remove(str) ;
    cout << "your list after removing the string you entered " << endl ;
    stringlist.print() ;
    cout << endl ;

    return 0 ;
}
