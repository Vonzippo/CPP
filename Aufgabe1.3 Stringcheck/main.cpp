#include <iostream>
#include <set>
using namespace std;
class StringUtil {
public:
    static bool checkUniqueness(string s);
};
bool StringUtil::checkUniqueness(string s){
    set<char> s2;
    for(int i =0; i < s.size(); i++) {
        s2.insert(s.at(i));
    }
    if(s2.size() != s.size()){
        cout << "false";
        return false;
    }
    cout << "true";
    return true;
}

int main() {

    string s1 = "abcdee";
    StringUtil obj;
    clock_t start, stop;
    start = clock();
     obj.checkUniqueness(s1);
    stop = clock();

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