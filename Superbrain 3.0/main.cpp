#include <iostream>
#include <cstdlib>

using namespace std;

struct Numbi{
public:
    int Wert= 0;
    int Position = 0;
};

int Eingabe(int *temp, int size){
    for (int f = 0; f < size;f++){
        cin >> temp[f];
    }
    return *temp;
}

int Uniquecheck(int *vorgabe, int size){
    int pos = 0;
    int zähler =0;
    for (int i = 0 ; i < size; i++){
        for (int j = i+1; j < size; j++){
            if (vorgabe[i] == vorgabe[j]){
                zähler++;
                pos = i;
            }
        }
    }
    return zähler;
}

void logik(int *vorgabe,int *temp, int  zähler,int size, bool isNumberDouble, int alter,Numbi pos){
    Numbi  gesetzt[4];
    for (int x= 0; x < size; x++) {
        gesetzt[x].Wert = 0;
        gesetzt[x].Position = 0;
        if (temp[x] == vorgabe[x]) {
            cout << " o ";
            gesetzt[x].Wert = 1;
            gesetzt[x].Position = x;
        }
    }
    bool ZahlWas = true;
    Numbi wasAlready[size];
    int nummer = 0;
    Numbi hallo[size];
    int flag[size];
    for(int z = 0; z < size; z++){
        for(int t = 0; t < size; t++) {
            if(isNumberDouble) {
                if (gesetzt[z].Wert == 0 && zähler != 3) {
                    if (gesetzt[t].Wert == 0) {
                        for (int w = 0; w < size; w++) {
                            if (wasAlready[w].Wert == vorgabe[t]) {
                                ZahlWas = false;
                                cout << "setze falsch";
                            }
                        }
                        if (temp[z] == vorgabe[t] && gesetzt[z].Position == 0) {
                            cout << " ."/* << vorgabe[t]*/;
                            gesetzt[z].Position = 1;
                            wasAlready[z].Wert = temp[t];
                        }
                    }
                }
                else if (zähler == 3) {
                    if (gesetzt[z].Wert == 0) {
                        if (gesetzt[t].Wert == 0) {
                            for (int w = 0; w < size; w++) {
                                if (wasAlready[w].Wert == vorgabe[t]) {
                                    ZahlWas = false;
                                    //cout << "setze falsch";
                                }
                            }
                            if (temp[z] == vorgabe[t] && gesetzt[z].Position == 0 && ZahlWas) {
                                cout << " . "/*<< " achtung 3er " << vorgabe[t]*/;
                                gesetzt[z].Position = 1;
                                wasAlready[z].Wert = temp[t];

                            }
                        }
                    }
                }
            }


            else {

                bool pass =true;
                if (gesetzt[z].Wert == 0 && zähler != 3 && alter < 1) {
                    if (gesetzt[t].Wert == 0) {

                       // for(int b = 0; b < size;b++) {
                            if (flag[t - 1] == temp[t - 1]) {
                              //  cout << endl << "dieser wer war schon : " << temp[t-1];
                                pass = false;
                            }

                       // }
                        if(temp[t-1] != pos.Wert){
                           // cout << " true : " << temp[t];
                            pass = true;
                        }
                        if (temp[z] == vorgabe[t] && gesetzt[z].Position == 0 && pass ) {
                                cout << " ." /*<< vorgabe[t]*/;
                                gesetzt[z].Position = 1;
                            if(pos.Wert == temp[t-1]){
                                flag[t-1] = pos.Wert;
                               // cout << "flag wird gesetzt" << endl;
                            }

                        }
                    }
                }
                else if (zähler == 3) {
                    if (gesetzt[z].Wert == 0) {
                        if (gesetzt[t].Wert == 0) {
                            for (int w = 0; w < size; w++) {
                                if (wasAlready[z].Wert == vorgabe[t]) {
                                        ZahlWas = false;
                                        //cout << "setze falsch";
                                }
                            }
                            if (temp[z] == vorgabe[t] && gesetzt[z].Position == 0 && ZahlWas) {
                                    cout << " . "/*<< " achtung 3er "<< vorgabe[t]*/;
                                    gesetzt[z].Position = 1;
                                    wasAlready[z].Wert = temp[t];

                            }
                        }
                    }
                }


            }
        }
    }
}

int main() {
    srand(time(NULL));
    int size = 4;
    int versuche = 6;
    int temp[size];
    int vorgabe[size];
/*
    vorgabe[0] = 4;
    vorgabe[1] = 5;
    vorgabe[2] = 2;
    vorgabe[3] = 1;
    //5516
    */
    int kategorie = 0;
    do {
        for (int i = 0; i < size; i++) {
            vorgabe[i] = (rand() % 6) + 1;
            //cout << vorgabe[i]  << "    ";
        }

        int gezählt = 0;
        Numbi obj1[size];
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (vorgabe[i] == vorgabe[j]) {
                    obj1[i].Wert += 1;
                    if (obj1[i].Wert > 0) {
                        obj1[i].Position = i;

                    }
                }
            }
        }
        for (int i = 0; i < size; i++) {
            if (obj1[i].Wert == 1) {
                gezählt++;
                kategorie = 1;
                //cout << "Hat 2 gleiche Zahlen";
                if (gezählt == 2) {
                   // cout << " Es sind 2 * 2gleiche zahlen";
                    kategorie = 4;
                    break;
                }
            } else if (obj1[i].Wert == 2) {
                //cout << "Hat 3 gleiche  Zahlen";
                kategorie = 2;
                break;
            } else if (obj1[i].Wert == 3) {
                //cout << "Hat 4 gleiche  Zahlen";
                kategorie = 3;
                break;
            }

        }
    }while(kategorie == 4);
    int alter = 0;
    Numbi obj;
    int isNumberDouble =false;
    for (int i = 0 ; i < size; i++){
        for (int j = i+1; j < size; j++){
            if (vorgabe[i] == vorgabe[j]){
                alter++;
                obj.Wert = vorgabe[i];
                if (obj.Wert > 0){
                    obj.Position = i;
                    isNumberDouble = true;
                }
            }
        }
    }
    //cout << " Wert vorgabe " << obj.Wert << "       Alter : " << alter<< endl;
    cout << "Geben Sie eine Zahlenfolge von 1 - 6 ind die kästchen ein: " << endl;
    for (int i =0; i < versuche;i++ ){
        cout << endl;
        *temp = Eingabe(temp,size);
       // int zähler = Uniquecheck(temp,size);
        Numbi pos;
        int zähler =0;
        for (int i = 0 ; i < size; i++){
            for (int j = i+1; j < size; j++){
                if (temp[i] == temp[j]){
                    zähler++;
                    pos.Position = i;
                    pos.Wert = temp[i];
                }
            }
        }
        //cout << "wert eingabe = " << pos.Wert;
        if(pos.Wert == obj.Wert && obj.Wert != 0){
            isNumberDouble = true;
        }
        logik(vorgabe,temp,zähler,size,isNumberDouble,alter,pos);
    }

    for(int i = 0; i < size; i++){
        cout << vorgabe[i]  << "    ";
    }
    return 0;
}