#ifndef EXAM__MODEL_H__
#define EXAM__MODEL_H__

#include <stack>
class Model {
 public:
  Model() = default;
  int TopPop();
  void Push(int num);
  void Clear();
  int Top();

 private:
  std::stack<int> questions{};
};

#endif //EXAM__MODEL_H__
