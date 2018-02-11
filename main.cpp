#include "header/RShell.h"
#include "header/Input.h"
#include <queue>
#include <iostream>


using namespace std;

int main(){
  queue<Input*>* commands = new queue<Input*>();
  RShell* terminal = new RShell();

  terminal->parseCommands(commands);

  while(commands->size()){
    cout << (commands->front()->getCommand()) << endl;
    commands->pop();
  }



  return 0;
}
