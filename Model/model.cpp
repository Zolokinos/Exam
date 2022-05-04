#include <iostream>
#include "model.h"
int Model::TopPop() {
  if (questions.size() > 1) {
    questions.pop();
    return questions.top();
  }
  return -1;
}

void Model::Push(int num) {
  questions.push(num);
}

void Model::Clear() {
  questions = {};
}

int Model::Top() {
  if (!questions.empty()) {
    return questions.top();
  }
}
