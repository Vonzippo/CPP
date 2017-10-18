#include <iostream>
#include <cstdlib>
using namespace std;

class Trader{
public:
    static int calculateMaxProfit(const int *values, const int ARRAY_SIZE) ;
};


// Noch wann gekauft werden soll, wann verkauft werden soll ein Wert soll definiert werden, höchster und tiefster wert um welche zeit

int Trader::calculateMaxProfit(const int *values, const int ARRAY_SIZE){

    int *TempArray;
    TempArray = new int[ARRAY_SIZE];
    int res = 0;
    int pos = 0;
    for(int i = 0; i < ARRAY_SIZE-1; i++) {
        TempArray[i] = 0;
        if (values[i] < values[i + 1]) {
        TempArray[i] = values[i + 1] - values[i];
        if (res < TempArray[i]) {
            res = TempArray[i];
            pos = i;
        }
    }
    }
    cout << endl << "von Po = " << pos << " zu " << pos+1 << endl;
    return res;
}

int main() {
    srand(time(NULL));

    int *ary;
    int size = 5;
    ary = new int[size];
    for (int i= 0; i < size; i++){
        ary[i] = rand() % 20;
        cout << "Rand " << i << " = " << ary[i] << endl;
    }

    int res = 0;
    Trader obj;
    res = obj.calculateMaxProfit(ary,size);
    cout << "Max Gewinn = " << res << endl;

    return 0;
}