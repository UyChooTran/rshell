#ifndef INPUT_H
#define INPUT_H

#include <string>

using namespace std;

class Input{

public:
  Input(string str);
  virtual int execute() = 0;
  string getCommand();

protected:
  string command;


};

class Connectors : public Input{
  public:
    Connectors(Input* A, Input* B);
    virtual int execute() = 0;
  
  protected:
    Input* A;
    Input* B;

};

class Commands : public Input{
  public: 



}

#endif
