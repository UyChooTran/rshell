#ifndef RSHELL_H
#define RSHELL_H

#include <queue>
#include <string>
#include "Input.h"
using namespace std;

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
