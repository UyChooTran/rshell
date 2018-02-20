// This file implements command class

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include "../header/Input.h"


using namespace std;

Command::Command(vector<string>* arguments){

  this->deleteThis = arguments;
  this->cmd = arguments->at(0).c_str();
  for(unsigned i = 0; i < arguments->size(); i++){
    this->args[i] = const_cast<char*>(arguments->at(i).c_str());
  }
  this->args[arguments->size()] = NULL;
}


int Command::execute(queue<Input*>* inputs, int stat){

  pid_t pid = fork();
  int status = 1;

  if(pid < 0){
    cout << "Failed to fork child" << endl;
    exit(1);
  }
  else if(pid == 0){
    if(execvp(this->cmd, this->args) < 0){
      perror("Invalid command");
      exit(1);
    }
    else{
      exit(0);
    }
  }
  else{
    while(wait(&status) != pid);
  }

  delete deleteThis;

  if(status){
    return 0;
  }
  return 1;

}
