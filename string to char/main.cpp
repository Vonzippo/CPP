#include <iostream>
#include <string>
using namespace std;


void prüf(string s){
    char *u ;

    u = new char[s.length()];
    for (int i = 0; i <s.length(); i++ ){
        u[i] = s.at(i);
        cout << u[i];
    }

}


int main() {

    string s = {"hallo"};


    prüf(s);


    return 0;
}