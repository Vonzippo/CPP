#include <iostream>
using namespace std;

class StringUtil {
public:
    static char getLonelyElement(string input);
};

char StringUtil::getLonelyElement(string input){

    char res = 'a';
    int *zähler;
    zähler = new int[256];
    for (int i = 0; i < 256;i++){
        zähler[i] = 0;
    }

    for (int i = 0; i < input.size();i++){
        ++zähler[(int)input[i]];
    }

    for (int i = 0; i < 256;i++){
        if (zähler[i] == 1){
            res = (char)i;
            break;
        }
    }

    return res;

}

int main() {
srand(time(NULL));
    string test1 = "";

    for(int i = 0; i < 30; i++){
        test1 += rand() % 26 + 'A';
    }
    cout << test1 << endl;
    string input = "abcdedcba11";

    char res = ' ';
    StringUtil obj;
    res =  obj.getLonelyElement(test1);

    cout << endl <<  "Resultat : " << res << endl;
    return 0;
}