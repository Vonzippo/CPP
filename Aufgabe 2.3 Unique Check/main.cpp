#include <iostream>
#include <string>
using namespace std;


class StringUtil{
public:

    static bool anagramCheck(string s1,string s2);
};

bool StringUtil::anagramCheck(string s1,string s2){ // quadratisch
    if (s1.length() != s2.length()){     // wenn beide Strings nicht gleich gross sind dann ist es schon falsch
        return false;
    }
    char *CA1;                          // 2 dynamische Arrays werden für die String erstellt
    CA1 = new char[s1.length()];
    char *CA2;
    CA2 = new char[s1.length()];

    for(int j = 0; j < s1.length();j++){    //Arrays werden abgefüllt mit den Strings
        CA1[j] = s1.at(j);
        CA2[j] = s2.at(j);
    }

    char tmp1 = 0;                     //diese Variable ist ein zwischen speicher

    for (int i = 0;i < s1.length();i++){    // beide Arrays werden sortiert
        for(int j = i+1; j < s1.length();j++){  // nicht lineare aber die hälfte der laufzeit wie ich j = i+1
            if (CA1[i] > CA1[j]){           // hier werden beide Arrays sortiert der grösse nach
                tmp1 = CA1[j];              // sortiert nach dem asci code
                CA1[j] = CA1[i];
                CA1[i] = tmp1;
            }
            if (CA2[i] > CA2[j]){
                tmp1 = CA2[j];
                CA2[j] = CA2[i];
                CA2[i] = tmp1;
            }
        }
        if (CA1[i] != CA2[i]){      // sind beide Arrays an der stelle nicht gleich so ist das falsch
            return false;
        }
    }

    /*
    char tmp1 = 0;
    for (int i = 0;i < s1.length();i++){    // beide strings werden sortiert
        for(int j = i+1; j < s1.length();j++){  // nicht lineare aber die hälfte der laufzeit wie ich j = i+1
            if (s1.at(i) > s1.at(j)){           // hier werden beide string sortiert der grösse von den Buchstaben nach
                tmp1 = s1.at(j);
                s1.at(j) = s1.at(i);
                s1.at(i) = tmp1;
            }
            if (CA2[i] > CA2[j]){
                tmp1 = s2.at(j);
                s2.at(j) = s2.at(i);
                s2.at(i) = tmp1;
            }
        }

        if (s1.at(i) != s2.at(i)){      // sind beide strings an der stelle nicht gleich so ist das falsch
            return false;
        }
    }

     */
    return true;
}


int main() {
    string s1 = "abcdefg";
    string s2 = "gfedcba";
    bool anaC = true;
    clock_t start, stop;

    cout << "String 1 = '" << s1  << "'"<< endl << "String 2 = '" << s2 <<  "'" << endl ;

    StringUtil obj;
    start = clock();
    anaC = obj.anagramCheck(s1,s2);
    stop = clock();

    cout << "Zeit : " << (double)(stop - start)/CLOCKS_PER_SEC<< endl;
    if (anaC){
        cout << endl << "true";
    }
    else {
        cout << endl << "false";
    }

    return 0;
}