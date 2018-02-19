#include "../header/RShell.h"
#include "../header/Input.h"
#include <queue>
#include <iostream>


using namespace std;

int main(){
  queue<Input*>* commands = new queue<Input*>();
  RShell* terminal = new RShell();

  while(!terminal->getExitStatus()){
    terminal->parseCommands(commands);

    while(commands->size() && !terminal->getExitStatus()){
//    cout << (commands->front()->getCommand()) << endl;
//TODO: execute each command
      commands->pop();
    }

      terminal->input();
  }

  return 0;
}
