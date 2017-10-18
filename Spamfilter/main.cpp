#include <iostream>
#include <ctime>

using namespace std;

bool isKeyword(string Message){
    string *Arry;
    Arry =new string[3];
    Arry[0] = {"cash"};
    Arry[1] = {"subscribe"};
    Arry[2] = {"marketing"};

    for (int i = 0; i < 3; i++){
        if (Message.find(Arry[i]) != std::string::npos) {
            //cout << "found! : " << Message<< '\n';
            return true;
        }

    }
    return false;
}
class Message{
public:

    Message();
    string value;
    int classification;

    void setV(string );
    string getV();

    void setC(int);
    int getC();

};
Message::Message(): value(""), classification(0) {}
void Message::setV(string NewString){
    value = NewString;
}
string Message::getV(){
return value;
}
void Message::setC(int classific){
    classification = classific;


}

int Message::getC(){
return classification;
}
class Classifier{
public:

    static Message* classifyMessages(string* messages, int size);
};
Message* Classifier::classifyMessages(string* messages, int size){
    Message obj[size];
// setze alle werte
    for(int i = 0; i < size; i++){
        obj[i].setV(messages[i]);
    }

    string *Arry;
    Arry =new string[3];
    Arry[0] = {"cash"};
    Arry[1] = {"subscribe"};
    Arry[2] = {"marketing"};

    int *vergleicherarry = new int[size];
    for(int i =0 ; i < size; i++){
        vergleicherarry[i] = 0;
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < 3; j++){
            if (messages[i].find(Arry[j]) != std::string::npos) {
                cout << "found! : " << messages[i]<< '\n';
               vergleicherarry[i]++;
            }

        }
    }
    int *vergleichsarry = new int[size];
    for(int i =0 ; i < size; i++){
        vergleichsarry[i] = 0;
    }

    for (int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++) {
            if(messages[i].find(messages[j]) != string::npos){
                //cout << "Message mehrfach" << messages[i]<< endl;
                vergleichsarry[i]++;
                vergleichsarry[j]++;
            }
        }
    }


    int klasse = 0;
    // ist mesage grösser als 12
   for(int i = 0; i < size; i++){
       klasse = 0;
       if(messages[i].size() <= 12){
           klasse++;
           cout << "kürzer als 12 : " << obj[i].value<< endl;
       }

       if(vergleichsarry[i] > 0){
           klasse++;
           cout << "Message mehrfach : " << messages[i]<< endl;
       }

       if(vergleicherarry[i] > 0){
           klasse++;
           cout << "Messagehat key : " << messages[i]<< endl;
       }

       obj[i].setC(klasse);
   }

    for(int i= 0;i < size ; i++){

        cout << "Message Object " << i+1 << ":[" << obj[i].getV() <<" ," << obj[i].getC() <<"]"<< endl;
    }
}


int main() {
    int size = 6;
    string *inputArray;
    inputArray = new string[size];
    inputArray[0] = "sales";
    inputArray[1] = "hallo martin, alles klar";
    inputArray[2] = "marketing";
    inputArray[3] = "brandnew dvd...";
    inputArray[4] = "marketing";
    inputArray[5] = "friday appointment";
    clock_t start, stop;
    Classifier obj;
    start = clock();
    obj.classifyMessages(inputArray,size);
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