#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
/*
bool NumberUnique(int *vorgabe,int size){

    for (int i = 0 ; i < size; i++){
        number[i] = 0;
        for (int j = 0; j < size; j++){

            if (vorgabe[i] == vorgabe[j]){
                number[i] += 1;
                if (number[i] == 2){
                    //spez[i] = i+1;
                    isNumberDouble = true;
                }
            }
        }
        // cout << "spez " <<  spez[i]<< "   ";
    }

}
*/

struct Numbi{
public:
    int Wert= 0;
    int Position = 0;
};
int main() {
    srand(time(NULL));
    int size = 4;
    int versuche = 6;
    int block[versuche][size];
    int vorgabe[size];
    //for(int i = 0; i < size; i++){
    //vorgabe[i] = (rand()%6)+1;
    //  cout << vorgabe[i]  << "    ";
    //}
    vorgabe[0] = 1;
    vorgabe[1] = 1;
    vorgabe[2] = 2;
    vorgabe[3] = 3;
    for(int i = 0; i < size; i++){
        //vorgabe[i] = (rand()%6)+1;
          cout << vorgabe[i]  << "    ";
        }
    int checker = 0;
    int isNumberDouble =false;
    int number[size];

    Numbi obj[size];

    for (int i = 0 ; i < size; i++){
        for (int j = i+1; j < size; j++){
            if (vorgabe[i] == vorgabe[j]){
                obj[i].Wert += 1;
                if (obj[i].Wert > 0){
                    obj[i].Position = i;
                    isNumberDouble = true;
                }
            }
        }
    }
    cout << endl;
    int kategorie = 0;
    int gezählt = 0;

    for (int i= 0; i < size; i++){
        if (obj[i].Wert == 1){
            gezählt++;
            kategorie = 1;
            cout << "Hat 2 gleiche Zahlen";
            if(gezählt == 2){
                cout  << " Es sind 4 gleiche zahlen";
                kategorie = 4;
                break;
            }
        }else if(obj[i].Wert == 2){
            cout << "Hat 3 gleiche  Zahlen";
            kategorie = 2;
            break;
        }
            else if (obj[i].Wert == 3){
            cout << "Hat 4 gleiche  Zahlen";
            kategorie = 3;
            break;
        }

    }

    for (int i =0; i < size;i++) {
            cout << endl<< "Wert     " <<obj[i].Wert << "     " << endl;
            cout << "Position " <<obj[i].Position << "" << endl;
    }
    cout << endl;

    if (isNumberDouble){
        cout << "true" << endl;
    }
//Arten :  A:1 1 2 3 ; B:1 1 1 2 ; C:1 1 1 1 ; D:1 1 2 2 ;
    // if array > 2 gleiche zahlen
    //1 A,D >> if 2*  2gleiche zahlen >>D
    //2 B,C >> if  alle zahlen gleich >> C

    cout << "Geben Sie eine Zahlenfolge von 1 - 6 ind die kästchen ein: " << endl;
    for (int i =0; i < versuche;i++ ){
        cout << endl;

        for (int j= 0; j < size; j++){
            block[0][j] = 0;
            cin >> block[i][j];
        }
        for (int x= 0; x < size; x++){
            if (block[i][x]== vorgabe[x]){
                cout << " o ";
            }

            else {
                int zähler = 0;
                int count = 3;
                Numbi neues[i];
                bool warSchon = true;
                for (int y = 0; y < size; y++) {
                    if (block[i][x] == vorgabe[y] && !isNumberDouble){
                        cout << " . ";
                    }
                    else if (isNumberDouble && block[i][x] == vorgabe[y]){
                        if (kategorie == 1){

                            for (int s = 0; s < size; s++) {
                                if (block[i][y] == block[i][s]) {
                                    zähler++;
                                    neues[s].Wert = block[i][s];
                                    neues[s].Position = s;
                                }
                            }

                            if(zähler == 2){
                                cout << "Eingegebene Zahl = " << zähler <<endl;
                                zähler= 0;
                            }
                            else if (zähler == 3){
                                cout << "Eingegebene Zahl = " << zähler <<endl;
                                zähler= 0;
                                if (block[i][x] == vorgabe[y] && neues[y].Position != y) {

                                    if (!warSchon) {
                                        //cout << "es war schon";

                                    }

                                    else if (warSchon) {
                                        cout << " . ";
                                        warSchon = false;
                                    }

                                }

                                if(block[x][y] == vorgabe[y]/* && vorgabe[y] != vorgabe[x]*/){
                                   cout << " G ";
                                }
                            }
                            else if (zähler == 4){
                                //cout << "Eingegebene Zahl = " << zähler <<endl;
                                zähler= 0;
                            }

                            count++;
                            //cout << "count = " << count  << endl;


                        }
                        else if (kategorie == 2){}
                        else if (kategorie == 3){}
                        else if (kategorie == 4){}

                    }
/*
                    bool warSchon = true;

                    for (int o = 0; o < size; o++) {
                        if (block[i][y] == block[i][o]) {
                            zähler++;

                        }
                    }
                    if (zähler > 2) {
                        //cout << endl << " mehr als 2  " << zähler;
                        for (int s = y + 1; s < size; s++) {
                            if (block[i][y] == block[i][s]) {
                                warSchon = false;
                                count++;
                                //cout << "count = " << count  << endl;
                            }

                                else if (block[i][x] == vorgabe[y]) {
                                    cout << " . ";
                                }

                        }
                    } else if (zähler == 4) {
                        for (int s = y + 1; s < size; s++) {
                            if (block[i][y] == block[i][s]) {
                                warSchon = false;
                                count++;
                                //cout << "count = " << count  << endl;
                            }
                                else if (block[i][x] == vorgabe[y]) {
                                    cout << " . ";
                                }

                        }
                    }

                    if (block[i][x] == vorgabe[y]) {

                        if (!warSchon) {
                            //cout << "es war schon";

                        }

                        else if (number[y] > 1 && schonGemacht){
                                schonGemacht = false;
                                //cout << "geklappt";
                        }

                        else if (warSchon) {
                            cout << " . ";
                        }

                    }
                    */
               }

            }

        }

    }

    for(int i = 0; i < size; i++){
        //vorgabe[i] = (rand()%6)+1;
        cout << vorgabe[i]  << "    ";
    }
    return 0;
}