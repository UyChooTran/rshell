// This file implements the connectors and comment classes

#include "../header/Input.h"
#include <iostream>
using namespace std;

Connector::Connector() : Input(){}

And::And() : Connector(){}

Comment::Comment() : Connector(){}

Or::Or() : Connector(){}

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

int Comment::execute(queue<Input*>* inputs, int status){
  return -2;
}


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
