#ifndef RSHELL_H
#define RSHELL_H

#include <queue>
#include <string>
#include "Input.h"
using namespace std;

class RShell{
  public:
     RShell();
     string cmd;
     void parseCommands(queue<Input*>* fill);
  private:
    void input();
    void output();
    void output(string str);

};
#endif
