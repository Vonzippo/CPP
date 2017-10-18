#include <iostream>
#include <cstdlib>
using namespace std;

class Trader{
public:
    static int calculateMaxProfit(const int *values, const int ARRAY_SIZE) ;
};


// Noch wann gekauft werden soll, wann verkauft werden soll ein Wert soll definiert werden, höchster und tiefster wert um welche zeit
/*
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
*/
/*
int Trader::calculateMaxProfit(const int *values, const int ARRAY_SIZE){

    int kauf = values[0];
    int verkauf =  0;
    int res = 0;
    int posk = 0;
    int posv = 0;

    for(int i = 0; i < ARRAY_SIZE-1; i++) {
        for (int j= i+1; j < ARRAY_SIZE;j++) {
            if (kauf > values[j]) {
                posk = j;
                kauf = values[j];
            }
        }
    }
    for (int i = posk; i < ARRAY_SIZE;i++){
        for (int j= i+1; j < ARRAY_SIZE;j++) {
                if (verkauf < values[j]) {
                    posv = j;
                    if (posv > posk) {
                        verkauf = values[j];
                    }
                }
        }
    }
    res = verkauf - kauf;
    cout << endl<< "Kaufen hier : "<< kauf << endl << "Verkaufen hier : "<< verkauf << endl;
*/
/*
    int kaufen = values[0];
    int verkaufen =  0;
    int res2= 0;
    int posk2 = 0;
    int posv2 = 0;
    for(int i = 0; i < ARRAY_SIZE-1; i++) {

        for (int j= i+1; j < ARRAY_SIZE;j++) {
            if (verkaufen > values[j]) {
                posk2 = j;
                verkaufen = values[j];
            }
        }
    }
    for (int i = 0; i < posk2;i++){
        for (int j= i+1; j < ARRAY_SIZE;j++) {
            if (kaufen < values[j]) {
                posv = j;
                if (posv > posk) {
                    kaufen = values[j];
                }
            }
        }
    }

    res2 = verkaufen - kaufen;
    cout << endl << res2;

    return res;
}
*/
int Trader::calculateMaxProfit(const int *values, const int ARRAY_SIZE) { // quadratisch
    int high = 0; // die höchste mögliche differenz
    int posk = 0; // position von kaufen
    int posv = 0; // position von verkaufen
    for (int i= 0; i < ARRAY_SIZE; i++){
        for (int j=i+1; j< ARRAY_SIZE;j++){
            if (values[i] < values[j]){
                if ((values[j] - values[i]) > high){ // hier wird überprüft ob es eine höhere differenz am Tag gibpt
                    high = values[j] - values[i];  // differenz wird bereechnet
                    posk = i;                   // position wird gesetzt
                    posv = j;                   // "
                }
            }
        }
    }

    cout << endl << "kaufen : " << posk << endl<< "verkaufen : " << posv << endl;
    return high;
}/*
void xy(const int *values, const int ARRAY_SIZE){
    int high = 0;
    int posk = 0;
    int posv = 0;
    for (int i= 0; i < ARRAY_SIZE; i++){
        for (int j=i+1; j< ARRAY_SIZE;j++){
            if (values[i] < values[j]){
                if ((values[j] - values[i]) > high){
                    high = values[j] - values[i];
                    posk = i;
                    posv = j;
                }
            }
        }
    }
    cout << endl << "high : " << high << endl<< "kaufen : " << posk << endl<< "verkaufen : " << posv << endl;
}
*/

int main() {
    srand(time(NULL));
    clock_t start, stop;

    int *ary;
    int size = 100;
    ary = new int[size];
    for (int i= 0; i < size; i++){
        ary[i] = rand() % 20;
        cout << "Rand " << i << " = " << ary[i] << endl;
    }
    //xy(ary,size);
    int res = 0;
    Trader obj;
    start = clock();
    res = obj.calculateMaxProfit(ary,size);
    stop = clock();
    cout << "Max Gewinn = " << res << endl;

    cout<<"Zeit: "<<(double)(stop-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}