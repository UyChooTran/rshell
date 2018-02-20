#ifndef RSHELL_H
#define RSHELL_H

#include <queue>
#include <string>
#include "Input.h"
using namespace std;

// this class also uses type Input from input class
// it is responsible for running everything
class RShell{
  public:
    RShell();
    bool getExitStatus();
    void input();
  private:
    string cmd;
    int status;
    queue<string>* strings;
    queue<Input*>* inputs;
    bool exit;
    void output();
    void output(string str);
    void parseCommands();
    void createInputs();
    void runInput();
};
#endif
