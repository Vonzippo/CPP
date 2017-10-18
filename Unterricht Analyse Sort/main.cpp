#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

char analyseNew(string s){
    int array[25] = {0};
    char result = '$';

    for(int i = 0;i < s.length();i++){
        array[s.at(i) - 'A']++;
    }

    for(int i = s.length()-1;i >=0;i--){
        if(array[s.at(i) - 'A'] == 1){
            result = s.at(i);
        }
    }
    return result;
}

char analyseNewX(string s){

    // mit Sortierungsalglorythmus

    int array[26] = {0};
    char result = '$';

    for(int i = 0;i < s.length();i++){
        array[s.at(i) - 'A']++;
    }

    for(int i = s.size()-1;i >=0;i--){
        if(array[s.at(i) - 'A'] == 1){
            cout << array[i] << endl;
            result = s.at(i);
        }
    }
    char st[s.length()] = {'A','A','B','B','G','H'};
    char stx[s.length()] = {'A','A','B','B','G','H'};
    int counter = 0;
    int tempC = counter++;
    bool notSame = false;
    for (int i = 0; i < (s.length() * s.length());i++){
        if (st)

            if (notSame){
                return result;
            }
    }
    return result;
}
char analyse(string s){
    for (int i = 0; i < s.length(); i++) {
        char rch = s.at(i);
        bool additionalCharFound = false;
        for (int j = 0;j < s.length(); j++) {
            if (i == j)continue;

            if (rch == s.at(j)){
                additionalCharFound = true;
            }

        }
        if (!additionalCharFound) {
            return rch;
        }
    }
    return '$';
}

string createString(int size){

    string result = "";
    for(int i = 0; i < size;i++){
        result += ('A'+ rand() % 25);
    }
    result += 'Z';
    return result;
}

int main(int argc, char **argv) {

    //srand(time(NULL));
    clock_t start,stop;
/*
    string s = "ZFGJHGGKHSGVGVJSJHCGJ";
    char result = analyseNew(s);
    cout << result;
*/
    string s = "AABBGH";
    //string s = createString(1000);
    cout << s << endl;
    start = clock();
    //char result = analyse(s);
    char result = analyseNewX(s);
    cout << result;
    stop = clock();
    double time  = (double)(stop-start)/CLOCKS_PER_SEC;
    cout << endl << time << " sec" << endl;
    /*
    string s = "ZFGJHGGKHSGVGVJSJHCGJ";
    char result = analyseNew(s);
    cout << result;
*/
    return 0;
}