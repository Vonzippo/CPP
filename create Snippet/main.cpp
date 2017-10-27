#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Result {
public:
    int nPositive;
    int nZero;
    int nNegative;
    
    friend std::ostream & operator <<(std::ostream & stream, const Result & obj){
        stream << "nNegative : " << (double)obj.nNegative/10 << "%" <<  endl ;
        stream << "nZero : " << (double)obj.nZero/10 << "%" << endl;
        stream << "nPositive : " <<  (double)obj.nPositive/10 << "%" << endl;
    }
};

class ArrayUtil{
public:
    static Result analyseArray(vector<int> input);

};
Result ArrayUtil::analyseArray(vector<int> input){
    float *counter;
    counter = new float[3];

    for(int i = 0; i < 3; i++){
        counter[i] = 0;
    }
    for(vector<int>::iterator i = input.begin(); i != input.end();i++){
        if(*i < 0){// braucht stern weil i ein iterator ist und kein integer
            //cout << *i << " kleiner als 0" << endl;
            counter[0]++;
        }
        else if(*i> 0){
            //cout << *i << " grösser als 0" << endl;
            counter[1]++;
        }
        else {
            //cout << *i << " gleich 0" << endl;
            counter[2]++;
        }
    }

    double c[3];

    for(int i =0; i < 3 ;i++) {
        c[i] = ((counter[i] / input.size()) * 1000);
    }

    Result obj;
    obj.nNegative = (int)round(c[0]);
    obj.nZero = (int)round(c[2]);
    obj.nPositive = (int)round(c[1]);

    return obj;
}

int main(int argc, char** argv) {


    vector<int> input{1,10,0,-6,-9,2,5};

    ArrayUtil obj;
    Result newobj;
    newobj = obj.analyseArray(input);

    cout << newobj;
/*
    cout << endl << "nNegative = " << newobj.nNegative << "%";
    cout << endl << "nPositive = " << newobj.nPositive<< "%";
    cout << endl<< "nZero = " << newobj.nPositive << "%";
    //std::cout << "Hello, World!" << std::endl;
*/
    return 0;
}