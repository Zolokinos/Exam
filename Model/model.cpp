#include <iostream>
#include "model.h"

Model::Model() {
  srand(time(nullptr));
}

int Model::TopPop() {
  if (questions_.size() > 1) {
    questions_.pop();
    return questions_.top();
  }
  return -1;
}

void Model::Push(int num) {
  questions_.push(num);
}

void Model::Clear() {
  questions_ = {};
}

int Model::Top() {
  if (!questions_.empty()) {
    return questions_.top();
  }
  return -1;
}

void Model::GreenAdd(int num) {
  green_.insert(num);
  non_green_.erase(num);
}

std::set<int> Model::GreenGet() const {
  return green_;
}

void Model::NonGreenAdd(int num) {
  non_green_.insert(num);
  green_.erase(num);
}

std::set<int> Model::NonGreenGet() const {
  return non_green_;
}

void Model::GreenErase(int num) {
  green_.erase(num);
}

void Model::NonGreenErase(int num) {
  non_green_.erase(num);
}

void Model::GreenClear() {
  green_.clear();
}

void Model::NonGreenClear() {
  non_green_.clear();
}

int Model::GetRand(int max) {
  if (max > 0) {
    return rand() % max;
  }
  return -1;
}

void Model::SetFormated(int num) {
  NonGreenClear();
  GreenClear();
  for (int i = 0; i < num; ++i) {
    non_green_.insert(i);
  }
}

int Model::PrevColor() const {
  if (is_default_) {
    return 0;
  } else if (is_yellow_) {
    return 1;
  } else if (is_green_) {
    return 2;
  }
  return -1;
}

void Model::PrevDefault() {
  is_default_ = true;
  is_yellow_ = false;
  is_green_ = false;
}

void Model::PrevYellow() {
  is_default_ = false;
  is_yellow_ = true;
  is_green_ = false;
}

void Model::PrevGreen() {
  is_default_ = false;
  is_yellow_ = false;
  is_green_ = true;

}
