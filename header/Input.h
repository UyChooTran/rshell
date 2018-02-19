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

class Or:  public Input
{ 

  public:
  int evaluate(queue<*Input>);

};

class And: public Input
{
  public:
  int evaluate(queue<*Input> );
};


class Comment: public Input
{
  public:
  int evaluate(queue<Input>);

};
#endif
