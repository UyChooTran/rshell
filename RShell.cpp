#include "header/RShell.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

RShell::RShell(){
 this->input();
}

void RShell::input(){
  output();
  getline(cin, cmd);
}

void RShell::output(){
//TODO: Print the current working directory and user
  cout << "$ ";

  return;
}

void RShell::output(string str){
//Newline?
  cout << str << endl;

  return;
}

void RShell::parseCommands(queue<Input*>* fill){
  stringstream parse(cmd);
  string inString;

  while(parse.good()){
    parse >> inString;
    fill->push(new Input(inString));
  }

}
