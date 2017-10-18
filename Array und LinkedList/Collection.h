//
// Created by Patrick Oetterli on 18.10.17.
//

#ifndef ARRAY_UND_LINKEDLIST_COLLECTION_H
#define ARRAY_UND_LINKEDLIST_COLLECTION_H

template <class R>
class Collection {
public:
    virtual int size() const = 0;
    virtual void add(R value) = 0;
    virtual R get(int index, bool & ok) const = 0;
    virtual void set(int index, R value, bool & ok) = 0;
    virtual void remove(int index, bool & ok) = 0;
};


#endif //ARRAY_UND_LINKEDLIST_COLLECTION_H
