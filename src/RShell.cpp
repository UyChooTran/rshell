#include "../header/RShell.h"
#include "../header/Input.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

// constructor to give variables initial values
RShell::RShell(){
  this->exit = false;
  this->strings = new queue<string>();
  this->inputs = new queue<Input*>();
  int status = 0;
  this->input();
}

// outputs prompt
// gets user inputs and then parses them
void RShell::input(){
  output();
  getline(cin, cmd);
  this->parseCommands();
}

// flag for if exit command was executed
bool RShell::getExitStatus(){
  return this->exit;
}

// outputs prompt
void RShell::output(){
//TODO: Print the current working directory and user
  cout << "$ ";

  return;
}

// utputs user input
void RShell::output(string str){
  cout << str << endl;

  return;
}

// parses the user input
void RShell::parseCommands(){
  stringstream parse(cmd);
  string inString;
  while(parse.good()){
    parse >> inString;
    strings->push(inString);
  }
  this->createInputs();

}

// checks for if user wrote &&, ||, # or ;
// and behaves accordingly
void RShell::createInputs(){

  vector<string>* commands = new vector<string>();
  string parse;

  while(!this->strings->empty()){
    parse = strings->front();
    //cout << parse <<endl;
    strings->pop();
    if(parse == "||"){
      inputs->push(new Or());
    }
    else if(parse == "&&"){
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
        delete commands;
        commands = 0;
      }
    }
    else{
      parse.pop_back();
      //cout << parse << endl;
      commands->push_back(parse);
      inputs->push(new Command(commands));
      delete commands;
      commands = new vector<string>();
    }

  }

  delete commands;
  runInput();
}

// executes caommands
void RShell::runInput(){
  Input* current;
  while(!getExitStatus() && !this->inputs->empty()){
    current = inputs->front();
    inputs->pop();
    this->status = current->execute(this->inputs, status);
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
