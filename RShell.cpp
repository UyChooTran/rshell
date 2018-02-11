#include "header/RShell.h"
#include <string>
#include <iostream>


using namespace std;

RShell::RShell(){
  cmd = input();
}

string RShell::input(){
  string str;
  getline(cin, str);
  return str;
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
