#include <iostream>
#include <string>
#include <ctime>



using namespace std;

void selectionSort(int *So, int n){
    int *rang;
    rang = new int[n];
    rang[n] = {NULL};
    for (int i = 0; i < n-1; i++){
        int pos_min = i;
        for (int j = i+1; j < n; j++) {
            if (So[j] < So[pos_min]) {
                pos_min = j;
            }
        }
        if (pos_min != i){
            int temp = 0;
            temp = So[pos_min];
            So[pos_min] = So[i];
            So[i] = temp;
        }
    }
}

int main() {
    srand(time(NULL));

    string Name;
    string Vorname;
    int rang;
    int Punkte;
    int SpeicherP[10000];
    string SpeicherN[10000];
    string SpeicherV[10000];
    int reserveR;
    string reserveNV;
    int counter = 5000;


    int size = 3;
    int *Ar ;
    Ar = new int[size];
    Ar[size] = {NULL};

    cout << "\nDie Tabelle vor der Sortierung" << endl;

    for (int a = 0; a < size; a++){
        Ar[a] = rand() % 100;
        cout << "Punkte : " << Ar[a] << "   ";

        cout << "Namen : " << SpeicherN[a] << "   ";
        cin >> Name;
        SpeicherN[a] = Name;

        cout  << "Vornamen : " <<  SpeicherV[a]<< endl;
        cin >> Vorname;
        SpeicherV[a] = Vorname;

        if (a < size-1) {
            cout << ", ";
        }
    }

    selectionSort(Ar,size);

    cout << "\nDie Tabelle nach der Sortierung" << endl;

    cout << endl;
    for (int a = 0; a < size; a++){
        cout << "Punkte : " << Ar[a] << "   ";

        cout << "Namen : " << SpeicherN[a] << "   ";


        cout << "Vornamen : " <<  SpeicherV[a]<< endl;



        if (a < size-1) {
            cout << ", ";
        }
    }
    return 0;
}