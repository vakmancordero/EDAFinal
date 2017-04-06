#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <iomanip>
#include "linkedlist.h"

using namespace std;

template <class Person>
class QuickSort {

public:
    void quickSort(LinkedList<Person> &, int, int);
    int partition(LinkedList<Person> &, int, int);

    LinkedList<Person> getResult();

    int getComparisons();
    int getSwaps();

private:
    LinkedList<Person> resultVector;

    int comparisons = 0;
    int swaps = 0;
};

int QuickSort<Person>::getComparisons() {
    return this->comparisons;
}

int QuickSort<Person>::getSwaps() {
    return this->swaps;
}

LinkedList<Person> QuickSort<Person>::getResult() {
    return resultVector;
}

template <class Person>
void QuickSort<Person>::quickSort(LinkedList<Person> &list, int left, int right) {

    int index = partition(list, left, right);

    if (left < index - 1)
        quickSort(list, left, index - 1);

    if (index < right)
        quickSort(list, index, right);

    resultVector = list;

}

template <class Person>
int QuickSort<Person>::partition(LinkedList<Person> &list, int left, int right) {

    int l = left;
    int r = right;

    Person tmp;
    Person pivot = list.get(left);

    while (l <= r) {

        while (list.get(l).compareTo(pivot) < 0) {
            l++;
        }

        while (list.get(r).compareTo(pivot) > 0) {
            r--;
        }

        if (l <= r) {

            tmp = list.get(l);

            list.set(l, list.get(r));
            list.set(r, tmp);

            l++;
            r--;

            swaps++;

        }

        comparisons++;

    }

    return l;
}

#endif // QUICKSORT_H
