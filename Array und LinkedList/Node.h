//
// Created by Patrick Oetterli on 18.10.17.
//

#ifndef ARRAY_UND_LINKEDLIST_NODE_H
#define ARRAY_UND_LINKEDLIST_NODE_H


template <class T>
class Node {
public:
    T value;
    Node<T> * next;
};

#endif //ARRAY_UND_LINKEDLIST_NODE_H
