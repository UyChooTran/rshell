#include "../header/RShell.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

RShell::RShell(){
  this->exit = false;
  this->strings = new queue<string>();
  this->inputs = queue<Input*>();
  this->input();
}

void RShell::input(){
  output();
  getline(cin, cmd);
  this->parseCommands();
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

void RShell::parseCommands(){
  stringstream parse(cmd);
  string inString;
  while(parse.good()){
    parse >> inString;
    strings->push(inString);
  }

}

void RShell::createInputs(){
  
  vector<string>* commands = new vector<string>();
  string parse;

  while(!this->strings.empty()){
    parse = strings.front();
    strings.pop();
    
    if(parse == "||"){
      inputs.push(new Or();
    }
    else if(parse == "&&"){
      inputs.push(new And();
    }
    else if(parse.front() == '#'){
      inputs.push(new Comment();
    }
    else if(parse.back() != ';'){
      commands->push_back(parse);
    }
    else{
      parse.pop_back();
      commands->push_back(parse);
      inputs.push(new Command(commands) 
      delete commands;
      commands = new vector<string>();
    }

  }
  
  delete commands;
}

bool RShell::getExitStatus(){
  return this->exit;
}
