// This is main.cpp

#include "../header/RShell.h"
#include "../header/Input.h"
#include <queue>
#include <iostream>


using namespace std;

int main(){
  RShell* terminal = new RShell();
  while(!terminal->getExitStatus()){
    terminal->input();
  }

  return 0;
}
