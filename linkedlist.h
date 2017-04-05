#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <list>

using namespace std;

template <class T>
class LinkedList
{

public:

    //LinkedList();

    void add(T value);
    T get(int index);
    void set(int index, T value);
    void remove(T value);
    int size();

private:
    list<T> list;

};

#endif // LINKEDLIST_H
