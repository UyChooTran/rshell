#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>
#include <queue>

using namespace std;

// Input class is the interface user will use
// it has constructor, destructor
// and pure virtual function for derived classes
class Input{

public:
  Input();
  virtual ~Input(){};
  virtual int execute(queue<Input*>*, int) = 0;
};

// Command class is derived from Input class
// constructor needs a vector of strings
// has destructor and implements virtual function from Input class
class Command : public Input{
  public:
    Command(vector<string>*);
    ~Command(){};
    int execute(queue<Input*>*, int);

  private:
    vector<string>* deleteThis;
    const char* cmd;
    char* args[255];
};

//derived from input class
//has constructor, destructor
//and implements virtual function from input class
class Connector : public Input{
  public:
    Connector();
    virtual ~Connector(){};
    virtual int execute(queue<Input*>*, int) = 0;
};

// derived from input class
// has constructor destructor
// implements execute from input class
class Exit : public Input{
  public:
    Exit();
    ~Exit(){};
    int execute(queue<Input*>*, int);
};

// derived from connector class
// implements functionality for execution from connector class
class And : public Connector{
  public:
    And();
    ~And(){};
    int execute(queue<Input*>*, int);
};

// derived from connector class
// implements its own execute function
class Comment : public Connector{
  public:
    Comment();
    ~Comment(){};
    int execute(queue<Input*>*, int);
};

// derived from connector class
// implements its own execute function
class Or : public Connector{
  public:
    Or();
    ~Or(){};
    int execute(queue<Input*>*, int);
};

#endif
