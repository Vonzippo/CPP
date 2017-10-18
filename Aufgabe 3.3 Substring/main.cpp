#include <iostream>
#include <set>
#include <ctime>
#include <stdlib.h>

using namespace std;
/*
typedef std::list<std::string> Stringlist;
typedef Stringlist::const_iterator Iterator;

Stringlist read_string(){
    Stringlist strings;
    string string;
    while(getline(cin, string)){
        if (string == " "){
            break;
        }
        else {
            strings.push_back(string);
        }

    }
    return strings;
}

bool is_shorter(string const& lhs,string const& rhs){
    return lhs.size() < rhs.size;
}
*/

class StringUtil{
public:
static string lcs(string input1,string input2) ;
};

string StringUtil::lcs(string input1,string input2) {

        set<string> checkString;
        set<string>::iterator it;

        string longString = "NO STRING FOUND";
        int temp = 0;
        string temp1 = "";
        int count = 0;


        for (unsigned int i = 0; i < input1.length(); i++) {
            for (unsigned int j = 0; j + i < input1.length(); j++) {
                checkString.insert(input1.substr(i, j));
                count++;
            }
        }

        for (it = checkString.begin(); it != checkString.end(); ++it) {
            temp1 = *it;
            size_t found = input2.find(temp1);
            if (found != string::npos) {
                if (temp < temp1.length()) {
                    temp = temp1.length();
                    longString = temp1;
                }
            }

        }


        cout << "Moegliche kombinationen: " << count << endl;
        return longString;
    };




string func(string input1,string input2){
    int size = 0;
    string teilstring = "";

    string arr[19] ;
    if (input1.length() < input2.length()){
        size  = input2.length();

        for (int i = input1.length()+1; i < size+1; i++){
            input1 += " ";
        }
    }
    else {

        size  = input1.length();
    }
for(int j =0 ; j< size; j++) {


    for (int i = 0; i < size; i++) {
        if (input1.at(i) == input2.at(i)) {
            arr[j] += input1.at(i);
        }
        else{
            cout << arr[j];
            break;
        }


    }
cout << endl << " runde = " << j << endl;
}
    return teilstring;

}

int main() {

    srand(time(NULL));
    time_t start, stop;
    string test1 = "hallo saper";
    string test2 = "saper halooo";
    /*
    for(int i = 0; i < 1000; i++){
        test1 += rand() % 26 + 'A';
        test2 += rand() % 26 + 'A';
    }
*/

    start = clock();
    cout << StringUtil::lcs(test1, test2) << endl;
    stop = clock();
    cout << "Zeit : " << (double)(stop-start)/CLOCKS_PER_SEC << endl;
    cout << "String laenge = " << 1000 << endl;


    /*
    for(int i = 0; i < 1000; i++){
        test1 += rand() % 26 + 'A';
        test2 += rand() % 26 + 'A';
    }

    start = clock();
    cout << StringUtil::lcs(test1, test2) << endl;
    stop = clock();
    cout << "Runtime = " << (double)(stop-start)/CLOCKS_PER_SEC << endl;
    cout << "String laenge = " << 2000 << endl;
     */
    return 0;
}