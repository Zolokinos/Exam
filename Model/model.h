#ifndef EXAM__MODEL_H__
#define EXAM__MODEL_H__

#include <stack>
#include <vector>
#include <set>
#include <cstdlib>

class Model {
 public:
  Model();
  int TopPop();
  void Push(int num);
  void Clear();
  int Top();
  void GreenAdd(int num);
  void GreenErase(int num);
  void GreenClear();
  std::set<int> GreenGet() const;
  void NonGreenAdd(int num);
  void NonGreenErase(int num);
  void NonGreenClear();
  std::set<int> NonGreenGet() const;
  int GetRand(int max);
  void SetFormated(int num);
  int PrevColor() const;
  void PrevDefault();
  void PrevYellow();
  void PrevGreen();

 private:
  std::stack<int> questions_{};
  std::set<int> green_{};
  std::set<int> non_green_{};
  bool is_default_{true};
  bool is_yellow_{false};
  bool is_green_{false};
};

#endif //EXAM__MODEL_H__
