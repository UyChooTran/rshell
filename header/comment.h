#ifndef COMMENT_H
#define COMMENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Comment: public Input
{
  public:
  int evaluate(queue<Input>);

};

#endif
