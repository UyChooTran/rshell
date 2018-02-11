#ifndef INPUT_H
#define INPUT_H

#include <string>

using namespace std;

class Input{

public:
  Input(string str);
//  virtual void execute();
  string getCommand();

private:
  string command;


};



#endif
