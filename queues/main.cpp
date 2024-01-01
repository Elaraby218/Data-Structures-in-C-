#include <iostream>
#include "queues.h"
#include "implementationFile.cpp"

using namespace std ;
int main() {
    cout << "-------------------------------------------- Test queue based on array ------" << endl ;
    queue1<int> q(100);
    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        q.addQueue(x);
    }
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.is_empty() << endl;
    cout << q.is_full() << endl;
    q.deleteQueue();
    cout << q.front() << endl;
    cout << q.back() << endl;

    queue1<int> q2(q);
    cout << q2.front() << endl;
    cout << q2.back() << endl;

    queue1<int> q3;
    q3 = q2;
    cout << q3.front() << endl;
    cout << q3.back() << endl;

    cout << endl << "------------------------------------ test queue based on linked list -------------" << endl ;
    queue2<int>lsq ;
    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        lsq.addQueue(x);
    }
    cout << lsq.front() << endl;
    cout << lsq.back() << endl;
    cout << lsq.is_empty() << endl;
    cout << lsq.is_full() << endl;
    lsq.deleteQueue();
    cout << lsq.front() << endl;
    cout << lsq.back() << endl;

    queue2<int> lsq2(lsq);
    cout << lsq2.front() << endl;
    cout << lsq2.back() << endl;

    queue2<int> lsq3;
    lsq3 = lsq2;
    cout << lsq3.front() << endl;
    cout << lsq3.back() << endl;

}