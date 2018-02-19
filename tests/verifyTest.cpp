#include <string>
#include <iostream>
#include <queue>
#include <vector>
 

using namespace std;


int main(){
  
  queue<string> strings = queue<string>();
  strings.push("ls");
  strings.push("-a;");
  strings.push("echo");
  strings.push("test");
  strings.push("||");
  strings.push("ls");

  vector<string>* commands = new vector<string>();
  string parse;

  while(!strings.empty()){
    parse = strings.front();
    strings.pop();
    
    if(parse == "||"){
    
    }
    else if(parse == "&&"){
    
    }
    else if(parse.back() != ';'){
      commands->push_back(parse);
    }
    else{
      parse.pop_back();
      commands->push_back(parse);
      //DOSOMETHING
      for(unsigned i = 0; i < commands->size(); i++){
	cout << commands->at(i) << endl;
      }
      cout << "New vector" << endl;
      delete commands;
      commands = new vector<string>();
    }

  }


  return 0;

}
