#include <iostream>
#include <vector>
using namespace std;

class Result {
public:
    int nPositive;
    int nZero;
    int nNegative;
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
    //cout << input.size();
    for(int i =0; i < 3 ;i++) {
        c[i] = 0;
        c[i] = (double) ((counter[i] / input.size()) * 100.0);
        //cout << endl << c[i] << "%";
    }
    Result obj;
    obj.nNegative = c[0];
    obj.nPositive = c[1];
    obj.nZero = c[2];

    return obj;
}

int main(int argc, char** argv) {

    int arra[] = {1,10,0,-6,-9,2,5};
    vector<int> input;

    for(int i =0; i< 7;i++){
        input.push_back(arra[i]);
        //cout << input[i] << endl;
    }

    ArrayUtil obj;
    Result newobj;
    newobj = obj.analyseArray(input);

    cout << endl << "nNegative = " << newobj.nNegative << "%";
    cout << endl << "nPositive = " << newobj.nPositive<< "%";
    cout << endl<< "nZero = " << newobj.nPositive << "%";
    //std::cout << "Hello, World!" << std::endl;

    return 0;
}