#include "ExeObj.h"
#include <vector>
#include <iostream>

using namespace std;


int main(){


vector<string> stuff = vector<string>();

stuff.push_back("ls"); //change around to test
stuff.push_back("-a");
ExeObj* A = new ExeObj(stuff);
cout << A->run();

return 0;


}