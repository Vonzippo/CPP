#include <iostream>

using namespace std;


int crosssum(unsigned int n) {
    int result = 0;
    int localN = n;
    while (localN > 0) {
        result += localN % 10;
        localN /= 10;
    }
    return result;
}

int crosssum1(unsigned int n) {
    int result = 0;
    int localN = n;
    while (localN > 0) {
        result += localN % 10;
        localN /= 10;
    }
    return crosssum1(n+1);

}


int main(int argc, char **argv) {

    cout << crosssum(5) <<endl;
    return 0;
}