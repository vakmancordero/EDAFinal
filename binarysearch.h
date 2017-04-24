#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iostream>
#include "linkedlist.h"

using namespace std;

template <class Person>
class BinarySearch {

public:
    int binarySearch(LinkedList<Person> &, Person);
    int getCounter();

private:
    int counter = 0;
};


template <class Person>
int BinarySearch<Person>::getCounter() {
    return this->counter;
}

template <class Person>
int BinarySearch<Person>::binarySearch(LinkedList<Person> &list, Person item) {

    Person middleValue;

    int middle, low = 0, high = list.size() - 1;

    int counter = 0;

    while (low <= high) {

        middle = (low + high) / 2;

        middleValue = list.get(middle);

        counter++;

        if (item.compareTo(middleValue) == 0) {

            this->counter = counter;

            return middle;

        }
        else {

            if (item.compareTo(middleValue) < 0) {

                //cout << "item" << " < " << middleValue.toString().toStdString() << endl;

                high = middle - 1;

                //cout << "high" << " = " << high << endl;

            }
            else {

                //cout << "item" << " > " << middleValue.toString().toStdString() << endl;

                low = middle + 1;

                //cout << "low" << " = " << low << endl;

            }

        }
    }

    return -1;

}

#endif // BINARYSEARCH_H
