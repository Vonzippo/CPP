#include <iostream>
#include "Collection.h"
#include "Array.h"
#include "LinkedList.h"
#include "Node.h"

using namespace std;


int main(int argc,char **argv) {



    Array<int> obj;

    for (int i= 0; i < 10;i++){
        obj.add(i);
    }
    bool ok = true;
    for(int i =0; i < 10;i++){
        cout << obj.get(i,ok) << endl;
    }

    //cout << obj;
    return 0;
}