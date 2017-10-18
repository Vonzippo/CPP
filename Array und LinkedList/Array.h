//
// Created by Patrick Oetterli on 18.10.17.
//

#ifndef ARRAY_UND_LINKEDLIST_ARRAY_H
#define ARRAY_UND_LINKEDLIST_ARRAY_H

#include <iostream>
#include "Collection.h"
#include "Array.h"
#include "LinkedList.h"
#include "Node.h"

template <class T>
class Array : public Collection{
private:
    T *values;
    int maxSize;
    int currentSize;

    bool isIndexValid(int index);
    void resize();
public:
    //friend std::ostream& operator<<(std::ostream& stream, const Array& obj);

    Array(int size=0);

    ~Array();
    Array(const Array & obj);
    Array operator= (const Array & obj);

    int size();
    void add(T value);
    T get(int index, bool & ok);
    void set(int index, T value, bool & ok);
    void remove(int index, bool & ok);
};


#endif //ARRAY_UND_LINKEDLIST_ARRAY_H
