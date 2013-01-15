// getline with strings
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string str;
    ifstream ifs("data.txt");
      getline (ifs,str);
        cout << "first line of the file is " << str << ".\n";
	}
