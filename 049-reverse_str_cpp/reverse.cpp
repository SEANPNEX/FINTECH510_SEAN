#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string reverseSTRrec(string str){
  if (str.length()>1){
    return reverseSTRrec(str.substr(1))+str.substr(0,1);
  }
  else{
    return str;
  }
}

void reverse(string &str) {
  //WRITE ME
  int n = str.length();
  for(int i=0;i<n/2;++i){
    swap(str[i], str[n - i - 1]);
  }
}

int main(void) {
    vector<string> strings;

    strings.push_back("");
    strings.push_back("123");
    strings.push_back("abcd");
    strings.push_back("Captain's log, Stardate 42523.7");
    strings.push_back("Hello, my name is Inigo Montoya.");
    strings.push_back("You can be my wingman anyday!");
    strings.push_back("Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!");
    strings.push_back("amanap lanac a nalp a nam a");


    for (string test: strings) {
        reverse(test);
        cout << test << endl;
    }

    return EXIT_SUCCESS;
}