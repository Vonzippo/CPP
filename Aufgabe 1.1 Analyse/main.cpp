#include <iostream>
#include <ctime>

using namespace std;

void foo(int *array,int size){
    int sum = 0;
    int product = 1;
    for(int i= 0; i<size; i++) {
        sum += array[i];
    }
    for(int i = 0; i<size; i++){
        product *= array[i];
    }
    cout << sum << "," << product << endl;
}

int main() {
    clock_t start,stop;

    int size = 5;
    int *array;
    array = new int[size];
    for (int i=0; i<size;i++){
        array[i] = i;
       // cout << array[i] << endl;
    }

    //cin.get();

    start = clock();
    foo(array, size);
    stop = clock();


    double time = (double)(stop-start) / CLOCKS_PER_SEC;
    cout << endl << time << "sec"; // um die 0,000005 sec

    return 0;
}