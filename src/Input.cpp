#include "../header/Input.h"

using namespace std;


Input::Input(){

}

Exit::Exit() : Input(){}

// returns -1 to flag if exit was executed
int Exit::execute(queue<Input*>* q, int status){
  return -1;
}
