#include <iostream>

using namespace std;


int main() {
    string test1 = "";
    string test2 = "saper halooo";

    for(int i = 0; i < 100; i++){
        test1 += rand() % 26 + 'A';
        test2 += rand() % 26 + 'A';
    }

    std::cout << test1 << std::endl;
    return 0;
}