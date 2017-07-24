#ifndef STACK_LINKED.CPP
#define STACK_LINKED.CPP
#include "stackLinked.h"
#include <stdio.h>
#include "except.h"

template<class T>
StackLinked<T>::~StackLinked(){
    Node<T> *temp ;
    while(top){
        temp = top->link;
        delete top;
        top =temp;
    }
}

template<class T>
bool StackLinked<T>::IsFull()const {
    try{
        Node<T> *temp  = new Node<T>;
        delete temp;
        return false;
    }catch(NoMem){
        return true;
    }
}
template<class T>
T StackLinked<T>::Top() const{
    if(IsEmpty())throw OutOfBounds();
    T temp =top->data;
    return temp;
}
template<class T>
StackLinked<T>& StackLinked<T>::Add(const T& x){
    Node<T> *temp  = new Node<T>;
    temp->data = x;
    temp->link = top;
    top =temp; //ָ�븳ֵ
    return *this;
}

template<class T>
StackLinked<T>& StackLinked<T>::Delete(T& x){
    if(IsEmpty()){
        throw OutOfBounds();
    }
    x= top->data;
    Node<T> *temp  = top;
    top = top->link;
    delete temp;
    return *this;
}
#endif // STACK_LINKED_CPP
