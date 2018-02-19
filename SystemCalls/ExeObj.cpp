#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ExeObj.h"
#include <iostream>


using namespace std;

//might need to change to vector pointer
ExeObj::ExeObj(vector<string> arguments){
  

  cout << "resr" <<endl;

  this->cmd = arguments.at(0).c_str();
  
  for(unsigned i = 0; i < arguments.size(); i++){
    this->args[i] = const_cast<char*>(arguments.at(i).c_str());
  }
  this->args[arguments.size()] = NULL;

}


int ExeObj::run(){

  pid_t pid = fork();
  int status = 1;

  if(pid < 0){
    printf("Failed to fork child\n");
    exit(1);
  }
  else if(pid == 0){
    cout<<"child"<<endl;
    if(execvp(cmd, args) < 0){
      printf("Invalid command\n");
      exit(1);
    }
  }
  else{   

    while(wait(&status) != pid);
//    cout << "parent" <<endl;
//    cout << status <<endl;
  }
  
  if(status){
    return 0;
  }
  return 1;

}
