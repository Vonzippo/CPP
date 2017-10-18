#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template <class T>
T getSmallest(T *array, int size) {
    T check = array[0];
    for (int i=0; i<size; i++) {
        if (array[i] < check) {
            check = array[i];
        }
    }
    return check;
}

class MyClass {
private:
    int x;
public:
    int getX() const;
    void setX(int x);
    bool operator<(const MyClass & obj);
};

bool MyClass::operator<(const MyClass & obj) {
    return x < obj.getX();
}

int MyClass::getX() const {
    return x;
}

void MyClass::setX(int x) {
    this->x = x;
}

int main(int argc, char **argv) {

    int iarray[] = {2, 4, 1, 3, 5};
    int iMinElement = getSmallest<int>(iarray, 5);

    char carray[] = {'a', 'b', 'c', 'D', 'H'};
    char cMinElement = getSmallest<char>(carray, 5);
    //cout << cMinElement << endl;

    float farray[] = {1.2, 3.141, 2.0, 4.7};
    float fMinElement = getSmallest<float>(farray, 4);
    //cout << fMinElement << endl;

    string sarray[] = {"AAB", "AAA", "BCF"};
    string sMinElement = getSmallest<string>(sarray, 3);
    //cout << sMinElement << endl;

    MyClass mcarray[5];
    for (int i=0; i<5; i++) {
        mcarray[i].setX(rand()%1000);
    }
    MyClass mcMinElement = getSmallest<MyClass>(mcarray, 5);

    return 0;
}

