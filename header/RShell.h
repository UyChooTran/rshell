#ifndef RSHELL_H
#define RSHELL_H

#include <string>

using namespace std;

class RShell{
  public:
     RShell();
     string cmd;
  private:
    string input();
    void output();
    void output(string str);

};
#endif
