#include <iostream>
#include <climits>

using namespace std;

int func(int n){
    cout << n << endl;
    if(n <= 0){ // Abbruchbedingung

        return n;
    }

    func(n-1);
}

long long fakultat(int n){

    if(n <= 1 ){
        return n;
    }

    return n * fakultat(n-1);

}
int fiban(int n){
    //        0
    //0-> 0+0 0
    //1-> 0+1 1
    //2-> 0+1 1
    //3-> 1+3 2
    //4-> 1+2 3
    //5-> 2+3 5
    //6-> 3+5 8

    if(n <= 1){
        return n;
    }

    return fiban(n-1) + fiban(n-2);

}

int fiban1(int n){
    //        0
    //0-> 0+0 0
    //1-> 0+1 1
    //2-> 0+1 1
    //3-> 1+3 2
    //4-> 1+2 3
    //5-> 2+3 5
    //6-> 3+5 8

for(int i =0; i < n; i++) {
    if (n <= 1) {
        return n;
    }
    return fiban(n - 1) + fiban(n - 2);
}
}

int fiban2(int n){
    //        0
    //0-> 0+0 0
    //1-> 0+1 1
    //2-> 0+1 1
    //3-> 1+3 2
    //4-> 1+2 3
    //5-> 2+3 5
    //6-> 3+5 8

    int first, second, temp;
    first = 0;
    second = 1;
    for(int i = 0; i < n; i++) {
        temp = first + second;
        second = first;
        first = temp;
    }

    return first;
}
int fiban
int main() {

    //func(9);
/*
    long long res = 0;

    for(int i =0; i < 100; i++){
        res = fakultat(i);
        if (res < 0){
            cout << --i << endl;
            break;
        }
    }
*/



    clock_t start, stop;
    start = clock();
    cout << fiban2(6);
    stop = clock();

    cout <<endl<< "Zeit : " << (double)(stop - start)/CLOCKS_PER_SEC;
    cout << "Du DUMME HOMO"<<endl;





    return 0;
}