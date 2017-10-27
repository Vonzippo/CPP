#include <iostream>

using namespace std;


template<class T>
class Node {
public:
    T value;
    Node<T> *next;
};

template<class R>
class Collection {
public:
    virtual int size() const = 0;

    virtual void add(R value) = 0;

    virtual void insert(int index, R value, bool &ok) = 0;
    virtual R get(int index, bool &ok) const = 0;

    virtual void set(int index, R value, bool &ok) = 0;

    virtual void remove(int index, bool &ok) = 0;
    virtual int deleteEvenNumbers() = 0;
    virtual void print(ostream &stream) = 0;
    friend ostream &operator<<(ostream &stream, Collection &obj) {
        obj.print(stream);
        return stream;
    }

};


template<class T>
class LinkedList : public Collection<T> {
private:
    Node<T> *head;
    Node<T> *tail;
    int count;

    bool isIndexValid(int index) const;

public:

    LinkedList();

    ~LinkedList();

    LinkedList(const LinkedList<T> &obj);

    LinkedList<T> operator=(const LinkedList<T> &obj);

    void print(ostream &stream);

    int size() const;

    void add(T value);

    void insert(int index, T value, bool &ok);
    T get(int index, bool &ok) const;

    void set(int index, T value, bool &ok);

    void remove(int index, bool &ok);

    int deleteEvenNumbers();
};

template<class T>
LinkedList<T>::LinkedList() : head(0), tail(0), count(0) {
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj) {
    head = 0;
    tail = 0;
    count = 0;
    bool ok;
    for (int i = 0; i < obj.size(); i++) {
        add(obj.get(i, ok));
    }
}

template<class T>
void LinkedList<T>::print(ostream &stream) {
    stream << "Head: " << head << endl;
    stream << "Tail: " << tail << endl;
    stream << "=============================" << endl;
    int index = 0;

    for (Node<T> *tmp = head; tmp != 0; tmp = tmp->next) {
        stream << "Index: " << index << endl;
        stream << "MyAddress: " << tmp << endl;
        stream << "Value: " << tmp->value << endl;
        stream << "Next: " << tmp->next << endl;
        stream << "--------" << endl;
        index++;
    }
}

template<class T>
LinkedList<T> LinkedList<T>::operator=(const LinkedList<T> &obj) {
    while (count > 0) {
        bool ok;
        remove(0, ok);
    }
    bool ok;
    for (int i = 0; i < obj.size(); i++) {
        add(obj.get(i, ok));
    }
    return *this;
}

template<class T>
LinkedList<T>::~LinkedList() {
    while (count > 0) {
        bool ok;
        remove(0, ok);
    }
}

template<class T>
bool LinkedList<T>::isIndexValid(int index) const {
    return index >= 0 && index < size();
}

template<class T>
int LinkedList<T>::size() const {
    return count;
}

template<class T>
void LinkedList<T>::add(T value) {
    Node<T> *n = new Node<T>();
    n->value = value;
    n->next = 0;

    if (head == 0) {
        head = n;
        tail = n;
    } else {
        tail->next = n;
        tail = n;
    }
    count++;
}

template<class T>
void LinkedList<T>::remove(int index, bool &ok) {
    if (!isIndexValid(index)) {
        ok = false;
    } else {
        Node<T> *toDelete;
        if (index == 0) {
            toDelete = head;
            head = head->next;
            if (head == 0) {
                tail = 0;
            }
        } else {
            Node<T> *tmp = head;
            for (int i = 0; i < index - 1; i++) {
                tmp = tmp->next;
            }
            toDelete = tmp->next;
            if (toDelete == tail) {
                tail = tmp;
            }
            tmp->next = toDelete->next;
        }
        ok = true;
        delete toDelete;
        count--;
    }
}

template<class T>
T LinkedList<T>::get(int index, bool &ok) const {
    if (!isIndexValid(index)) {
        ok = false;
    } else {
        Node<T> *tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        ok = true;
        return tmp->value;
    }
    return NULL;
};

template<class T>
void LinkedList<T>::set(int index, T value, bool &ok) {
    if (!isIndexValid(index)) {
        ok = false;
    } else {
        Node<T> *tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        tmp->value = value;
        ok = true;
    }
}


template <class T>
void LinkedList<T>::insert(int index, T value, bool &ok){
    if (index < 0 || index > count) {
        ok = false;
    } else {
        Node<T> *toInsert = new Node<T>();
        toInsert->value = value;
        toInsert->next = 0;
        Node<T> *temp = head;

        if (index == 0){
            toInsert->next = head;
            head = toInsert;
        } else if (index==size()){

            add(value);

        } else {
            for (int i = 0 ; i < index -1 ; i++){
                temp= temp->next;
            }
            toInsert->next = temp->next;
            temp->next = toInsert;
        }
        ok = true;
        count++;
    }
}

class A {
public:
    int a;

    A(int a) : a(a) {};

    ~A() {
        cout << "~A" << endl;
    }
};

class B : public A {
public:
    int a;

    B(int a) : A(a - 1), a(a) {
        cout << "A" << endl;
    };

    ~B() {
        cout << "~B" << endl;
    }
};


int crosssum(unsigned int n) {
    int result = 0;
    if (n == 0) return 0;
    result += n % 10 + crosssum(n / 10);
    return result;
}

template<class T>
int LinkedList<T>::deleteEvenNumbers() {
    int deleteCounter = 0;
    Node<T> *toDelete;

    while (head != 0 && head->value % 2 == 0) {
        toDelete = head;
        head = head->next;
        if (head == 0) {
            tail = 0;
        }
        delete toDelete;
        deleteCounter++;
        count--;

    }

    if (head != 0) {
        Node<T> *temp = head;
        while (temp->next != 0) {
            if (temp->next->value % 2 == 0) {
                toDelete = temp->next;
                temp->next = toDelete->next;
                if (temp->next == 0) {
                    tail = temp;
                }
                deleteCounter++;
                delete toDelete;
            } else {
                temp = temp->next;
            }

        }
    }

    return deleteCounter;
};


int main() {
    clock_t start, stop;
    bool ok = true;
    A *obj = new B(5);
    obj->a++;
    cout << obj->a << endl;
    delete obj;

    Collection<int> *linkedlist = new LinkedList<int>;

    start = clock();
    for (long long i = 0; i < 10000; i++) {
        linkedlist->add(2);
    }
    linkedlist->add(2);
    linkedlist->add(2);
    linkedlist->add(2);
    linkedlist->add(2);
    linkedlist->add(2);
    cout << "Erstellen der Linked List: " << (double) (clock() - start) / CLOCKS_PER_SEC << "ms" << endl;

    start = clock();
    cout << linkedlist->deleteEvenNumbers() << " Elemente wurden geloescht" << endl;
    cout << "Löschen der geraden Elemente: " << (double) (clock() - start) / CLOCKS_PER_SEC << "ms" << endl;

    cout << *linkedlist << endl;



}