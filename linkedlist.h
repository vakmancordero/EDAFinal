#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <list>
#include "person.h"

#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
class LinkedList
{

public:

    LinkedList();

    void add(T value);
    T get(int index);
    void set(int index, T value);
    void remove(T value);
    int size();

    list<T> list;

private:

};

template <class T>
LinkedList<T>::LinkedList() {

}

template <class T>
void LinkedList<T>::add(T value) {

    this->list.push_back(value);
}

template <class T>
T LinkedList<T>::get(int index) {

    std::list<T>::iterator it = this->list.begin();
    std::advance(it, index);

    T value = *it;

    return value;
}

template <class T>
void LinkedList<T>::set(int index, T value) {

    std::list<T>::iterator it = this->list.begin();
    std::advance(it, index);

    *it = value;
}

template <class T>
void LinkedList<T>::remove(T value) {

    this->list.remove(value);
}

template <class T>
int LinkedList<T>::size() {

    return (int) this->list.size();
}

#endif // LINKEDLIST_H
