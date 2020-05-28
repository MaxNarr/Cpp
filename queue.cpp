#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstdint>


namespace DHBW {
template <typename T> class Element{
public:
Element(T p_value){
*value = p_value;
};

T value;
Element* nextElement = nullptr;
};


template <typename T> class Queue{
public:
Queue();
Queue(int n);
bool enqueue(T value);
T dequeue();
int count();
bool free();

private:
int capacity;
int numberOfElements;
Element<T>* firstElement;
Element<T>* lastElement;

};

template <class T>
bool Queue<T>::enqueue(T value){
if (numberOfElements != capacity){
Element<T>* newElement = new Element(value);
lastElement->nextElement = newElement;
lastElement = newElement;
return true;
}
return false;
}

template <class T>
T Queue<T>::dequeue(){
if (free()){
return nullptr;
}
Element<T>* elementToReturn = firstElement;
firstElement = elementToReturn->nextElement;
return elementToReturn;
}
}
#endif /* QUEUE_HPP */