#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


class StringUtil{
public:
    static bool isPalindrome(string input);
};

bool StringUtil::isPalindrome(string input){
    static int Start = 0;
    static int Stop = input.length()-1;

/*
// ohne Gross und kleinbuchstaben
    char *arx;
    arx = new char[input.length()];


        arx[Start] = input.at(Start);
       // cout << "  arx = " << arx[Start];
        if (arx[Start] + 32 >= 97 && arx[Start] + 32 <= 122 ) {

            //cout <<endl << "vorher: " << s1.at(Start)<<endl;
            input.at(Start) = (char)(arx[Start] + 32);
           // cout <<endl << "arx[] : " <<  (char)(arx[Start] + 32) <<endl;
        }

    arx[Stop] = input.at(Stop);
    //cout << "  arx = " << arx[Stop];
    if (arx[Stop] + 32 >= 97 && arx[Stop] + 32 <= 122 ) {

     //   cout <<endl << "vorher: " << s1.at(Stop)<<endl;
        input.at(Stop) = (char)(arx[Stop] + 32);
     ///   cout <<endl << "arx[] : " <<  (char)(arx[Stop] + 32) <<endl;

    }
*/

    if(Start == Stop || Start-1 == Stop){
        cout << "true";
        return true;
    }
    cout << input.at(Start) << " : " << input.at(Stop) << endl;
    if( input.at(Start) ==  input.at(Stop)){
        //cout <<  input.at(Start) << " : " <<  input.at(Stop) << endl;
        Stop--;
        Start++;
        return isPalindrome(input);
    }
    else{
        cout << "false";
        return false;
    }
}
/*
bool rw(string s1){
    static int Start = 0;
    static int Stop = s1.length()-1;


    char *arx;
    arx = new char[s1.length()];


        arx[Start] = s1.at(Start);
        //cout << "  arx = " << arx[Start];
        if (arx[Start] + 32 >= 97 && arx[Start] + 32 <= 122 ) {

           // cout <<endl << "vorher: " << s1.at(Start)<<endl;
            s1.at(Start) = (char)(arx[Start] + 32);
            //cout <<endl << "arx[] : " <<  (char)(arx[Start] + 32) <<endl;
        }

    arx[Stop] = s1.at(Stop);
   // cout << "  arx = " << arx[Stop];
    if (arx[Stop] + 32 >= 97 && arx[Stop] + 32 <= 122 ) {

       // cout <<endl << "vorher: " << s1.at(Stop)<<endl;
        s1.at(Stop) = (char)(arx[Stop] + 32);
        //cout <<endl << "arx[] : " <<  (char)(arx[Stop] + 32) <<endl;

    }

    cout << s1.at(Start) << " : " << s1.at(Stop) << endl;
    if(Start == Stop || Start-1 == Stop){
        cout << "true";
        return true;
    }

    if( s1.at(Start) ==  s1.at(Stop)){
        //cout <<  input.at(Start) << " : " <<  input.at(Stop) << endl;
        Stop--;
        Start++;
        return true + rw(s1);
    }
    else{
        cout << "false";
        return false;
    }


}
*/
int main() {
    clock_t start,stop;

    string s1 = "anasffsana";
    StringUtil obj;

    start = clock();
    bool res = obj.isPalindrome(s1);
    stop = clock();

    if (((double)(stop-start)/CLOCKS_PER_SEC) > 0.0000001){
        cout << endl << "mikro sekunden";
    }

    double runden = ((double)(stop-start)/CLOCKS_PER_SEC) *1000000;
    //cout << endl << runden << " ms "<< endl;

    cout << endl << "Zeit : " <<(double)(stop-start)/CLOCKS_PER_SEC;

    return 0;
}