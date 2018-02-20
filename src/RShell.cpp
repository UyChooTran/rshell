#include "../header/RShell.h"
#include "../header/Input.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

RShell::RShell(){
  this->exit = false;
  this->strings = new queue<string>();
  this->inputs = new queue<Input*>();
  status = 0;
  this->input();
}

void RShell::input(){
  output();
  getline(cin, cmd);
  if(cmd != ""){
    this->parseCommands();
  }
}

bool RShell::getExitStatus(){
  return this->exit;
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
  this->createInputs();

}

void RShell::createInputs(){

  vector<string>* commands = new vector<string>();
  string parse;

  while(!this->strings->empty()){
    parse = strings->front();
    strings->pop();
    if(parse == "||"){
      if(!commands->empty()){
        inputs->push(new Command(commands));
        commands = new vector<string>();
      }
      inputs->push(new Or());
    }
    else if(parse == "&&"){
      if(!commands->empty()){
        inputs->push(new Command(commands));
        commands = new vector<string>();
      }
      inputs->push(new And());
    }
    else if(parse == "#"){
      inputs->push(new Comment());
    }
    else if(parse.front() == '#'){
      inputs->push(new Comment());
      commands->push_back(parse.erase(0,1));
    }
    else if(parse == "exit" && commands->empty()){
      inputs->push(new Exit());
    }
    else if(parse.back() != ';'){
      commands->push_back(parse);
      if(this->strings->empty()){
        inputs->push(new Command(commands));
        //delete commands;
        commands = 0;
      }
    }
    else{
      parse.pop_back();
      commands->push_back(parse);
      inputs->push(new Command(commands));
      //delete commands;
      commands = new vector<string>();
    }

  }

  delete commands;
  runInput();
}

void RShell::runInput(){
  Input* current;
  while(!getExitStatus() && !this->inputs->empty()){
    current = inputs->front();
    inputs->pop();
    this->status = current->execute(this->inputs, this->status);
    switch (this->status) {
      case -1:
        this->exit = true;
        while(!this->inputs->empty()){
          delete current;
          current = inputs->front();
          inputs->pop();
        }
        break;
      case -2:
        while(!this->inputs->empty()){
          delete current;
          current = inputs->front();
          inputs->pop();
        }
        break;
      default:
        break;
    }
    delete current;
  }
}
