#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../SystemCalls/ExeObj.h"


using namespace std;

int main()
{
	cout << "$ ";
	string userInput;
	getline(cin, userInput);
	cout << endl << userInput << endl;

	istringstream input (userInput);
	string word;
	
	vector<string> words;
	while(input >> word){
		words.push_back(word);}
	for(int i = 0; i < words.size(); ++i)
	{
		cout << words.at(i) << endl;
	}

	vector<string> v1;
	vector<string> v2;

	for(int i = 0; i < words.size(); ++i)
	{
		if(words.at(i) != "&&" && words.at(i) != "||")
		{
			v1.push_back(words.at(i));
		}
		else{
			i = words.size();
		}
	}
		


return 0;
}
