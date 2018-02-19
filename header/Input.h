#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>
#include <queue>

using namespace std;

class Input{

public:
  Input();
  virtual int execute(queue<Input*>*, int) = 0;
};

class Command : public Input{
  public:
    Command(vector<string>*);
    ~Command();
    int execute(queue<Input*>*, int);

  private:
   const char* cmd;
   char* args[255];
};

class Connector : public Input{
  public:
    Connector();
    virtual int execute(queue<Input*>*, int) = 0;
};

class Exit : public Input{
  public:
    Exit();
    int execute(queue<Input*>*, int);
};

class And : public Connector{
  public:
    And();
    int execute(queue<Input*>*, int);
};

class Comment : public Connector{
  public:
    Comment();
    int execute(queue<Input*>*, int);
};

class Or : public Connector{
  public:
    Or();
    int execute(queue<Input*>*, int);
};

#endif
