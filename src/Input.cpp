#include "../header/Input.h"

using namespace std;


Input::Input(string str){
  command = str; 
}

string Input::getCommand(){
  return command;
}
