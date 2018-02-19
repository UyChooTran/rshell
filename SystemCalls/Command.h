#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>

using namespace std;

class Command : public Input{
  public:
    Command(vector<string>*);
    ~Command();
    int execute();

  private:
   const char* cmd;
   char* args[255];

};

#endif
