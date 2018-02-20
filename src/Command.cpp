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

<<<<<<< HEAD
=======
  this->deleteThis = arguments;
>>>>>>> 9a48e347e11708baf42b4a572d7b6e29f18e50b3
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
    if(execvp(this->cmd, this->args) < 0){
      cout << "Invalid command" << endl;
      exit(1);
    }
    else{
      exit(0);
    }
  }
  else{
    while(wait(&status) != pid){}
  }

<<<<<<< HEAD
  if(status ){
=======
  delete deleteThis;

  if(status){
>>>>>>> 9a48e347e11708baf42b4a572d7b6e29f18e50b3
    return 0;
  }
  return 1;

}
