#include <iostream>

using namespace std;

class MyClass {
public:
    int getX() const;
    void setX(int x);
    bool operator<(const MyClass &obj);
private:
    int x;
};

int MyClass::getX() const {
    return x;
}

void MyClass::setX(int x) {
    this->x = x;
}

bool MyClass::operator<(const MyClass & obj) {
    return x < obj.x;
}
template <class T>
T getsmallest(T *array , int size){
    T check = array[0];

    for(int i = 1; i < size; i++){
        if (array[i] < check){
            check = array[i];

        }
    }
    return check;
}

int main(int argc, char **argv) {
    srand(time(NULL));
    int size = 6;
    int *array;
    array = new int[size];
    array[0] = 5;
    array[1] = 2;
    array[2] = 3;
    array[3] = 6;
    array[4] = 1;
    array[5] = 4;
    int such = 0;
    such = getsmallest<int>(array,size);
    cout << such;


    char carray[] = {'a','b','c','D','H'};
    char cminElement = getsmallest<char>(carray,5);
   // cout <<endl << cminElement;


    string  sarray[] = {"Hey", "Treppe", "ich" , "ist", "stringfreak"}; // von links nach rechts erstes zeichen vergleichen
    string sminElement = getsmallest<string>(sarray,5);
  //  cout <<endl << sminElement;

    float farray[] = {3.2342,31435,3.1234,543.345};
    float fminElement = getsmallest<float>(farray,5);
    //cout <<endl << fminElement;

    MyClass mcarray[5]; // erzeugt 5 objekte
    for(int i = 0; i < 5; i++ ){
        mcarray[i].setX(rand()%1000);// gibt unterschiedliche werte in die objekte
    }
    MyClass MCminElement = getsmallest<MyClass>(mcarray,5);
    //cout <<endl << MCminElement.getX();
    return 0;
}