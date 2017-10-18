#include <iostream>
#include <cstdlib>
using namespace std;

class ArrayUtil {
    public:
    static int highestProduct(int *values, const int ARRAY_SIZE);
};

int ArrayUtil::highestProduct(int *values, const int ARRAY_SIZE){ //Quadratisch

    int *TempArray;     // neues dynamisches Array erstellt
    TempArray = new int[ARRAY_SIZE];// "

   for (int i =0; i < ARRAY_SIZE; i++){ // neues Array initialisiert weil ich ein bereits abgefülltes array brauche
       TempArray[i] = values[i];
    }
    int temp = TempArray[0];             // eine Temporäre Variable erstellt und mit dem ersten Wert des Arrrays abgefüllt
    // bubble sort alg.
    for(int i = 0; i < ARRAY_SIZE; i++) {   //erste for schlaufe um den Index. Array mit anderen zu vergleichen
        for (int j= i+1; j < ARRAY_SIZE;j++) { // der neue index J wird auf den Index der äusseren for schlaufe gesetzt um Performens zu sparen
            if (TempArray[i] < TempArray[j] ){     //
                temp = TempArray[j];            //die Temp variable hilft, ein Array mit index der inneren for schlaufe und der index der äusseren
                TempArray[j] = TempArray[i];       // schlauf zu tauschen
                TempArray[i] = temp;
            }
        }
    }

    int produkt= 1;                         // die End variable wird mit 1 Initialisiert da sonst das Produkt nicht schön gerechnet werden kann
    for (int i =0; i < 3; i++){
        produkt *= TempArray[i];            // for schlaufe mit 3 durchläufen und berechnet die drei ersten elemente des Arrays

    }
    return produkt;                            // gibt das produkt der 3 höchsten Elemente zurück
}


int xy(int *values, const int ARRAY_SIZE) {// lineare


    int *TempArray;
    TempArray = new int[ARRAY_SIZE];

    int Pro[3];

    for (int i =0; i < ARRAY_SIZE; i++){
        TempArray[i] = values[i];
    }


    int tempPos= 0;
    int temp =TempArray[0];
    for (int i = 0; i < ARRAY_SIZE;i++){
        if (TempArray[i] > temp){
            tempPos = i;
            temp = TempArray[i];
            Pro[0] = temp;

        }
        //cout << temp << endl;
    }

    cout <<"    "<< tempPos;
    cout << "Pro 0 " << Pro[0] << endl;

    TempArray[tempPos] = 0;
    for (int i = 0; i < ARRAY_SIZE;i++){
        if (TempArray[i] > temp){
            tempPos = i;
            temp = TempArray[i];
            Pro[1] = temp;
        }
        cout << temp << endl;
    }
    cout <<"    "<< tempPos;
    TempArray ;
    cout << "Pro 1 " << Pro[1] << endl;
    temp = 0;
    for (int i = 0; i < ARRAY_SIZE;i++){
        if (TempArray[i] > temp){
            tempPos = i;
            temp = TempArray[i];
            Pro[2] = temp;
        }
        cout << temp << endl;
    }

    TempArray[tempPos] = 0;
    cout << "Pro 2 " << Pro[2] << endl;

    int res= 1;
    for (int i = 0; i < 3; i++){
        res *= Pro[i];
    }
    for (int i=0; i < ARRAY_SIZE; i++){
        cout << endl<< TempArray[i];
    }

return res;
}


int main() {
    srand(time(NULL));
    clock_t start, stop;
    int *ary;
    int size = 5;
    ary = new int[size];
    for (int i= 0; i < size; i++){
        ary[i] = rand() % 20;
        cout << "Rand " << i << " = " << ary[i] << endl;
    }
/*
    start = clock();
    cout << xy(ary,size) <<endl;
    stop = clock();

    cout << "Zeit : " << (double)(stop - start)/CLOCKS_PER_SEC;
*/
    ArrayUtil obj;
    start = clock();
    cout << "Produkt = "  << obj.highestProduct(ary,size)<< endl;
    stop = clock();

    cout << "Zeit : " << (double)(stop - start)/CLOCKS_PER_SEC;

    return 0;
}