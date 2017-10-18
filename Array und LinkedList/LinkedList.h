//
// Created by Patrick Oetterli on 18.10.17.
//

#ifndef ARRAY_UND_LINKEDLIST_LINKEDLIST_H
#define ARRAY_UND_LINKEDLIST_LINKEDLIST_H

#include <iostream>
#include "Collection.h"
#include "Array.h"
#include "Node.h"

template <class T>
class LinkedList : public Collection{
private:
    Node<T> * head;
    Node<T> * tail;
    int count;

    bool isIndexValid(int index) const;
public:

    LinkedList();
    ~LinkedList();
    LinkedList<T>(const LinkedList<T> & obj);
    LinkedList<T> operator= (const LinkedList<T> & obj);

    template <class U>
    friend std::ostream & operator<<(std::ostream & stream, const LinkedList<U> & obj);

    int size() const;
    void add(T value);

    T get(int index, bool & ok) const;
    void set(int index, T value, bool & ok);
    void remove(int index, bool & ok);
};

#endif //ARRAY_UND_LINKEDLIST_LINKEDLIST_H
