#include "../header/Input.h"

using namespace std;

Connector::Connector() : Input(){}

And::And() : Connector(){}

Comment::Comment() : Connector(){}

Or::Or() : Connector(){}

// executes command according to previous command status
int And::execute(queue<Input*>* inputs, int status){
  Input* next = 0;
  next = inputs->front();
  inputs->pop();
  if(status){
    int ret = next->execute(inputs, status);
    delete next;
    return ret;
  }
  delete next;
  return 0;
}

// returns -2 for to keep track if comment was executed
int Comment::execute(queue<Input*>* inputs, int status){
  return -2;
}

// executes or command according to previous command status
int Or::execute(queue<Input*>* inputs, int status){
  Input* next = 0;
  next = inputs->front();
  inputs->pop();
  if(status == 0){
    int ret = next->execute(inputs, status);
    delete next;
    return ret;
  }
  delete next;
  return 1;
}
