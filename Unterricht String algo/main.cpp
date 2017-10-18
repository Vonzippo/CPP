#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Data {
  int firstOccurence;
  int counter;
};

char analyseNew(string s) {
  Data array[26];
  for (int i=0; i<26; i++) {
    array[i].firstOccurence = -1;
    array[i].counter = 0;
  }

  for (int i=0; i<s.length(); i++) {
   array[s.at(i) - 'A'].counter++;
   if (array[s.at(i) - 'A'].firstOccurence == -1) {
     array[s.at(i) - 'A'].firstOccurence = i;
   }
  }

  int minFirstOccurence = s.length();
  int result = -1;
  for (int i=0; i<26; i++) {  
    if (array[i].counter == 1 &&
        array[i].firstOccurence < minFirstOccurence) {
      minFirstOccurence = array[i].firstOccurence;
      result = i;
    }
  }

  if (result == -1) return '$';
  return 'A' + result;
}

/*
Returns the first character which appears only once.
*/
char analyse(string s) {
  for (int i=0; i<s.length(); i++) {
    char rch = s.at(i);
    bool twoSameCharactersFound = false;
    for (int j=0; j<s.length(); j++) {
      if (i == j) continue;
      char ch = s.at(j);
      if (ch == rch) {
        twoSameCharactersFound = true;
        //break;
      }
    }
    if (!twoSameCharactersFound) {
      return rch;
    }
  }
  return '$';
}

string createRandomString(int size) {
  string result = "";
  for (int i=0; i<size; i++) {
    char ch = 'A' + rand() % 25;
    result += ch;
  }
  result += 'Z';
  return result;
}



int main(int argc, char **argv) {

  clock_t start, stop;

  string s = createRandomString(100000000);
  //cout << s << endl;
  start = clock();
  char result = analyseNew(s);
  stop = clock();
  cout << result << endl;
  double time = (double)(stop-start)/CLOCKS_PER_SEC;
  cout << time << endl;

  /*
  string s = "AABZBCCXDD";
  char result = analyseNew(s);
  cout << result << endl;
  */
  

  return 0;
}

