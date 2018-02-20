#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>
#include <queue>

using namespace std;

// Input class includes a constructor 
// and pure virtual function for executing command which is placed in a queue
// second parameter of virtual function is and int for previous command status
class Input{

  public:
    Input(); 
    virtual int execute(queue<Input*>*, int) = 0;
};

// Command class is derived from input class
// constructor stores user command in vector
// has destructor
// and implements virtual function from Input class
class Command : public Input{
  public:
    Command(vector<string>*); 
    ~Command(); 
    int execute(queue<Input*>*, int);

  private:
   const char* cmd;
   char* args[255];
};

// Exit class derives from Input class
// has constructor
// implements virtual function from Input class
class Exit : public Input{
  public:
    Exit();
    int execute(queue<Input*>*, int);
};
           
// Connector class derives from Input class 
// has constructor
// has pure virtual function for derived classes to implement
// virtual function takes in queue for execution and and int for previous
// command status
class Connector : public Input{
  public:
    Connector();
    virtual int execute(queue<Input*>*, int) = 0;
};

// And class derives from Connector class
// has constructor
// Implements virtual function from connector class
class And : public Connector{
  public:
    And();
    int execute(queue<Input*>*, int);
};

// comment class derives from connector class
// has constructor
// implements virtual functions from connector class
class Comment : public Connector{
  public:
    Comment();
    int execute(queue<Input*>*, int);
};

// Or class derives from connector class 
// has constructor
// implements virtual function from connector class
class Or : public Connector{
  public:
    Or();
    int execute(queue<Input*>*, int);
};

#endif
