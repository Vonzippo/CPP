#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Result {
	public:
		int nPositive;
		int nZero;
		int nNegative;

		friend std::ostream & operator <<(std::ostream & stream, const Result & obj){
			stream << "nNegative : " << static_cast<double>(obj.nNegative)/10 << "%" <<  endl ;
			stream << "nZero : " << static_cast<double>(obj.nZero)/10 << "%" << endl;
			stream << "nPositive : " <<  static_cast<double>(obj.nPositive)/10 << "%" << endl;
			return stream;
		}
};

class ArrayUtil{
	public:
		static Result analyseArray(vector<int> input);

};
Result ArrayUtil::analyseArray(vector<int> input){
	Result obj;
	float *counter;
	counter = new float[3];
	float c[3];

	for(int i = 0; i < 3; i++){
		counter[i] = 0;
	}

	for(vector<int>::iterator i = input.begin(); i != input.end();i++){
		if(*i < 0){// braucht stern weil i ein iterator ist und kein integer
			//cout << *i << " kleiner als 0" << endl;
			counter[0]++;
		}
		else if(*i> 0){
			//cout << *i << " grösser als 0" << endl;
			counter[1]++;
		}
		else {
			//cout << *i << " gleich 0" << endl;
			counter[2]++;
		}
	}

	for(unsigned int i =0; i < 3 ;i++) {
		c[i] = ((counter[i] / input.size()) * 1000);
	}

	obj.nNegative = static_cast<int>(round(static_cast<double>(c[0]))); //obj.xxx need int // round need Double
	obj.nZero = static_cast<int>(round(static_cast<double>(c[2])));
	obj.nPositive = static_cast<int>(round(static_cast<double>(c[1])));

	return obj;
}

int main() {

	vector<int> input{1,10,0,-6,-9,2,5};

	ArrayUtil obj;
	Result newobj;
	newobj = obj.analyseArray(input);

	cout << newobj;

	return 0;
}
