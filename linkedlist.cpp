#include "linkedlist.h"

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

    return this->list.size();
}
