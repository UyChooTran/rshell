// This file implements input ans exit classes

#include "../header/Input.h"

using namespace std;


Input::Input(){

}

Exit::Exit() : Input(){}

int Exit::execute(queue<Input*>* q, int status){
  return -1;
}
