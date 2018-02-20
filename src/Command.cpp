#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include "../header/Input.h"


using namespace std;

//converts vector of strings into c_str  
Command::Command(vector<string>* arguments){

  this->cmd = arguments->at(0).c_str();
  for( int i = 0; i < arguments->size(); ++i){
    this->args[i] = const_cast<char*>(arguments->at(i).c_str());
  }
  this->args[arguments->size()] = NULL;

}

// forks child process and wiats for parent process to finish
// doesn't execute of fork failed or invalid command
int Command::execute(queue<Input*>* inputs, int stat){

  pid_t pid = fork();
  int status = 1;

  if(pid < 0){
    cout << "Failed to fork child" << endl;
    exit(1);
  }
  else if(pid == 0){
    if(execvp(cmd, args) < 0){
      cout << "Invalid command" << endl;
      exit(1);
    }
  }
  else{
    while(wait(&status) != pid){}
  }

  if(status ){
    return 0;
  }
  return 1;

}
