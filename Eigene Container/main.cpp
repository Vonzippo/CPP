#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <cstdlib>
#include <set>
using namespace std;

char* createRandomString(int n) {
    char *result;
    result = new char[n];

    for( int i = 0; i < n; i++){
        result[i] = ('A' + rand() % 26) ;
        cout << result[i] << " ";
    }
    cout << endl;
    return result;
}

template<class t>
vector<t> Vector(t *Ary, int size){
    vector<t> v;
    for(int i = 0; i< size; i++){
        v.push_back(Ary[i]);
        cout << v.at(i) << "  ";
    }
/*
    v.insert(v.begin()+3, 50);
    vector<int>::iterator it;

    for(it = v.begin();it != v.end(); it++){
        cout << *it << endl;
    }
    */
    return v;
}

template<class t>
deque<t> Deque(t *Ary, int size){
    // Macht Reverse Array
    deque<t> d;
    int maxpos = size;
    for(int i = 0; i< size; i++){
        d.push_front(Ary[i]);
        maxpos--;
    }
    for(int i = 0; i< size; i++){
        cout << d.at(i) << " ";
    }
    return d;
}


template<class t>
std::ostream& operator<<(std::ostream& stream, Klassenname &obj) {

    stream << "===============================" << endl;
    stream << "Länge = " << obj << endl;
    stream << "===============================" << endl;
    stream << endl;

    return stream;
}


template<class t>
set<int> Set(t * Ary, int size){
    // gibt alle Zahlen unique aus
    set<int> s;
    set<int> cpys;



    for(int i = 0; i < size; i++){
        s.insert(Ary[i]);
    }


    set<int>::iterator it;
    for(it = s.begin(); it != s.end(); it++){
        cout << *it << endl;
    }

/*
    cpys = s;

    cout << cpys;
*/
}

/*
template<class t>
set<t> operator= (set<t> b) {

    set<t> obj;
    obj = b;
    return obj;
}
*/
int main() {
    srand(time(NULL));
    int size = 5;
    char *ary;
    clock_t start, stop;
    ary = createRandomString(size);
    start = clock();
    Vector(ary,size);
    //Deque(ary,size);
    //Set(ary,size);
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


/*
    vector<int> v;
    deque<int> d;

    for(int i = 0; i< 10; i++){
        v.push_back(i);
        if(i % 2== 0){
            d.push_back(i);
        }
        else{
           d.push_front(i);
        }
    }

    for (int i = 0; i < 10; i++){
        cout << v.at(i) << "  ";
    }

// between 2 und 3 50 einfügen
    v.insert(v.begin()+3, 50);

    vector<int>::iterator it;

    for(it = v.begin();it != v.end(); it++){
        cout << *it << endl;
    }
    */

   // map<char ,int> cc;

    /*
    map<char, int>::iterator it;
    //cc.insert(pair<char,int>('A' , 1));

    for( int i = 0; i < s.length();i++){
        char ch = s.at(i);
        if(cc.find(ch) == cc.end()) {
            cc.insert(pair<char, int>(ch,1));
        }
        else{
            cc.at(ch)++;

        }
    }

    int zähler = 0;
*/
    /*
    string s = createRandomString(10);
    cout << s;
    set<char> GesetzteListe;

    for(int i = 0; i < s.length(); i++){
        GesetzteListe.insert(s.at(i));

    }
    cout <<endl << GesetzteListe.size() << endl;
     */
    /*
    for( int i = 0; i < s.length();i++){
        char ch = s.at(i);
        if(cc.find(ch) == cc.end()) {
            cc.insert(pair<char, int>(ch, 1));
            zähler++;
            cout << zähler;
        }
    }

    it = cc.begin();
    //for(int i = it;)
*/
    /*
for ( it = cc.begin(); it != cc.end();it++ ){
    char key= it->first;
    int value = it->second;
    cout << key << " : " << value;
}
*/
    //pair<map<char,int>::iterator>
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}