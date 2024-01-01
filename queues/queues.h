//
// Created by Administrator on 06/10/2023.
//

#ifndef QUEUES_QUEUES_H
#define QUEUES_QUEUES_H
template<class Type>
class queueADT {
public:
    virtual bool is_empty() const = 0;
    // function to detemine wheter the queue is empty or not

    virtual bool is_full() const = 0;
    // Functino to determine whether the queue is full

    virtual void initialize() = 0;
    //Function to initialize the queue to an empty state.
    //Postcondition: The queue is empty.

    virtual Type front() const = 0;
    //Function to return the first element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: If the queue is empty, the progra
    // terminates; otherwise, the first element of the queue is returned.

    virtual Type back() const = 0;
    //Function to return the last element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: If the queue is empty, the program
    // terminates; otherwise, the last element of the queue is returned.

    virtual void addQueue(const Type &queueElement) = 0;
    //Function to add queueElement to the queue.
    //Precondition: The queue exists and is not full.
    //Postcondition: The queue is changed and queueElement is
    // added to the queue.

    virtual void deleteQueue() = 0;
    //Function to remove the first element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: The queue is changed and the first element
    // is removed from the queue.

};

/////////////////////////////////////////////////////////// queue using array

template<class Type>
class queue1 : public queueADT<Type> {

private:
    int maxsize;
    int count;
    int queueFront;
    int queueRear;
    Type *list;

    void copylist(const queue1<Type> &otherlist);

public:

    const queue1<Type> &operator=(const queue1<Type> &otherlist);
    //Overload the assignment operator.

    bool is_empty() const;

    bool is_full() const;

    void initialize();

    Type front() const;

    Type back() const;

    void addQueue(const Type &queueElement);

    void deleteQueue();

    int get_size();

    queue1(int size = 100);

    queue1(const queue1<Type> &otherQueue);

    ~queue1();

};

///////////////////////////////////////////////////////////// queue usind linked list

template<class Type>
struct nodeType {
    Type info;
    nodeType<Type> *link;
};

template<class Type>
class queue2 : queueADT<Type> {
public:
    const queue2<Type> &operator=(const queue2<Type> & ohterlist);

    bool is_empty() const;
    bool is_full() const;

    void initialize();

    Type front() const;
    Type back() const;

    void addQueue(const Type &queueElement) ;
    void deleteQueue() ;

    queue2();
    queue2(const queue2<Type>&ohterlist) ;
    ~queue2() ;

private:
    nodeType<Type> *queueFront;
    nodeType<Type> *queueRear;
    void copylist(const queue2<Type>&otherlist) ;
};

#endif //QUEUES_QUEUES_H
