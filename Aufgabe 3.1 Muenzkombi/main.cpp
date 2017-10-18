#include <iostream>
using namespace std;


class CoinCombination{
public:
static  void printCoinCombination(double value,const double *coins, const int ARRAY_SIZE);
};

void CoinCombination::printCoinCombination(double value,const double *coins, const int ARRAY_SIZE) {//lineare

    double startValue = 0;  // anfangsvariable welche erhöht wird bis sie so gross ist wie der Betrag
    int i = 0;
    int *counte;
    counte = new int[ARRAY_SIZE];

    for(int x= 0; x < ARRAY_SIZE;x++){
        counte[x] = 0;      // position mit der wie oft die münze gezählt wird
    }

    while(startValue != value){
        if(startValue < value) {
            startValue += coins[i];
            counte[i]++;
        }
        else{
            startValue -=coins[i];
            counte[i]--;
            i++;
        }
    }

    for (int z = 0; z < ARRAY_SIZE; z++) {
        if (counte[z] > 0) {
            cout << coins[z]<< " : " << counte[z] << endl;
        }
    }
    cout << endl;
}

void xy(double value,const double *coins, const int ARRAY_SIZE){ //Quadratisch
    value = value * 100;
    int val = (int) value;
    int *zm;
    zm = new int[ARRAY_SIZE];
    double *zwischenResult;
    zwischenResult = new double[ARRAY_SIZE];
    int runde = 0;
    int *zmr;
    zmr = new int[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        zwischenResult[i] = coins[i] * 100;
        zm[i] = (int)zwischenResult[i];
        zmr[i] = 0;
    }

    cout << endl;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        runde = 0;
        while ((val - zm[i]) >= -1) {
            val -= zm[i];
            runde++;
            zmr[i] = runde;
        }
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (zmr[i] > 0) {
            cout << zwischenResult[i]/100 << " : ";
            cout << zmr[i] << endl;
        }
    }

}

int main() {
    double Betrag = 63.50;
    bool checker = true;
    do {
        cout << "Geben Sie einen Betrag ein: " << endl;
        cin >> Betrag;
        Betrag = Betrag * 100;
        int check = (int) Betrag;
        if (check % 5 != 0) {
            cout << "ungültiger Betrag!" << endl;
            checker = true;
        }
        else{
            checker = false;
        }
    }while(checker);
    Betrag = Betrag/100;
    int AnzahlVerschiedeneMünzen = 7;
    double *MünzArray;
    MünzArray = new double[AnzahlVerschiedeneMünzen];
    MünzArray[0] = 5;
    MünzArray[1] = 2;
    MünzArray[2] = 1;
    MünzArray[3] = 0.5;
    MünzArray[4] = 0.2;
    MünzArray[5] = 0.1;
    MünzArray[6] = 0.05;
    clock_t start,stop;

    CoinCombination obj;
    start = clock();
    obj.printCoinCombination(Betrag,MünzArray,AnzahlVerschiedeneMünzen);
    stop = clock();
    cout << "Zeit1 : " <<(double)(stop-start)/CLOCKS_PER_SEC;

    start = clock();
    xy(Betrag,MünzArray,AnzahlVerschiedeneMünzen);
    stop = clock();

    cout << "Zeit2 : " <<(double)(stop-start)/CLOCKS_PER_SEC;


    return 0;
}