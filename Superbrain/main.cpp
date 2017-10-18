#include <iostream>
#include <cstdlib>
using namespace std;



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
    vorgabe[2] = 4;
    vorgabe[3] = 3;



    int checker = 0;
    int isNumberDouble =false;
    int number[size];
    int spez[4] = {0,0,0,0};
    cout << endl;
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
    /*
    cout << endl;
    for (int i =0; i < size;i++) {

            cout << "number" <<number[i] << "   " ;

    }
    cout << endl;
    for (int i =0; i < size;i++) {

        if (spez[i] > 1) {
            cout << endl << "spez wird an pos gelöscht "  << i;
            spez[i] = 0;

        }
    }
*/
    //check ob zahl schon vorgekommen ist


    if (isNumberDouble){

        cout << "true" << endl;
    }

    bool schonGemacht = true;



    cout << "Geben Sie eine Zahlenfolge von 1 - 6 ind die kästchen ein: " << endl;
    for (int i =0; i < versuche;i++ ){
        cout << endl;
       for (int u = 0; u < size; u++){
           if(block[i][u] == vorgabe[u]){
               checker += 1;
           }
       }
        if (checker == 4){
            cout << "Sie haben gewonnen!!!";
            break;
        }

        for (int j= 0; j < size; j++){

        block[0][j] = 0;
        cin >> block[i][j];
    }

        for (int x= 0; x < size; x++){
            if (block[i][x]== vorgabe[x]){
                cout << " o ";
            }
            if(block[i][x] != vorgabe[x] ) {
                int zähler = 0;
                int count = 3;
                if (isNumberDouble){
                    for (int y = 0; y < size-1; y++) {
                        bool warSchon = true;

                        for (int o = 0; o < size;o++){
                            if (block[i][y] == block[i][o]){
                                zähler++;

                            }
                        }

                        if (zähler > 2){
                            //cout << endl << " mehr als 2  " << zähler;
                            for (int s = y+1; s < size; s++){
                                if (block[i][y] == block[i][s]){
                                    warSchon = false;
                                    count++;
                                    //cout << "count = " << count  << endl;
                                }/*
                                else if (block[i][x] == vorgabe[y]) {
                                    cout << " . ";
                                }
                                */
                            }

                        }

                        else if (zähler == 4){
                            for (int s = y+1; s < size; s++){
                                if (block[i][y] == block[i][s]){
                                    warSchon = false;
                                    count++;
                                    //cout << "count = " << count  << endl;
                                }/*
                                else if (block[i][x] == vorgabe[y]) {
                                    cout << " . ";
                                }
                                */
                            }
                        }

                        if (block[i][x] == vorgabe[y] ) {

                            if (!warSchon){
                                //cout << "es war schon";

                            }


                                /*
                            else if (number[y] > 1 && schonGemacht){
                                    schonGemacht = false;
                                    //cout << "geklappt";
                            }
                            */
                            else if (warSchon){
                                cout << " . ";
                            }

                        }



                    }
                }

                else {
                    for (int y = 0; y < size; y++) {
                        if (block[i][x] == vorgabe[y]) {
                            cout << " . ";
                        }
                    }
                }
            }
        }
        schonGemacht = true;
    }
    for(int i = 0; i < size; i++){
        //vorgabe[i] = (rand()%6)+1;
        cout << vorgabe[i]  << "    ";

    }



    return 0;
}