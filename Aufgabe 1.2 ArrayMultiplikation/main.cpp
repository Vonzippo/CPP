#include <iostream>


using namespace std;

class ArrayUtil{
public:

    static long* multiplyArrayValues(const long *values ,const int ARRAY_SIZE);
};

long* ArrayUtil::multiplyArrayValues(const long *values ,const int ARRAY_SIZE){
    long *product = new long[ARRAY_SIZE];


    long temp = 1;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        product[i] = temp;
        temp *= values[i];
    }

    temp = 1;
    for (int i = ARRAY_SIZE - 1; i >= 0; --i) {
        product[i] *= temp;
        temp *= values[i];
    }


    return product;
}

int main() {
    int size = 4;

    long *InputArray;
    InputArray = new long[size];

    long *OutputArray;
    OutputArray = new long[size];

    InputArray[0] = 12;
    InputArray[1] = 4;
    InputArray[2] = 7;
    InputArray[3] = 3;

    ArrayUtil obj;
    clock_t start, stop;

    start = clock();
    OutputArray = obj.multiplyArrayValues(InputArray,size);
    //OutputArray = foo(InputArray,size);
    stop = clock();

    int counter = 0;
    cout << " { ";
    for (int i= 0; i < size; i++){//für die darstellung
        cout << OutputArray[i];
        if (++counter < size){
            cout << ", ";
        }
        else {
            cout << " }";
        }
    }

    if (((double) (stop - start) / CLOCKS_PER_SEC) < 0.00001) {
        double runden = ((double) (stop - start) / CLOCKS_PER_SEC) * 1000000;
        cout << endl << "Zeit : " << runden << " mikro sekunden";
    } else if (((double) (stop - start) / CLOCKS_PER_SEC) < 0.0001) {
        double runden = ((double) (stop - start) / CLOCKS_PER_SEC) * 1000000;
        cout << endl << "Zeit : " << runden << " mikro sekunden";
    } else if (((double) (stop - start) / CLOCKS_PER_SEC) < 0.001) {
        double runden = ((double) (stop - start) / CLOCKS_PER_SEC) * 1000000;
        cout << endl << "Zeit : " << runden << " mikro sekunden";
    } else if (((double) (stop - start) / CLOCKS_PER_SEC) < 0.01) {
        double runden = ((double) (stop - start) / CLOCKS_PER_SEC) * 1000;
        cout << endl << "Zeit : " << runden << " milli sekunden";
    }
    else if (((double) (stop - start) / CLOCKS_PER_SEC) < 0.1) {
        double runden = ((double) (stop - start) / CLOCKS_PER_SEC) * 1000;
        cout << endl << "Zeit : " << runden << " milli sekunden";
    }
    else if (((double) (stop - start) / CLOCKS_PER_SEC) < 1) {
        double runden = ((double) (stop - start) / CLOCKS_PER_SEC) * 1000;
        cout << endl << "Zeit : " << runden << " milli sekunden";
    }
    else if (((double) (stop - start) / CLOCKS_PER_SEC) > 1) {
        double runden = ((double) (stop - start) / CLOCKS_PER_SEC);
        cout << endl << "Zeit : " << runden << " sekunden";
    }

    return 0;
}