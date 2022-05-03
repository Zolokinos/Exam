#ifndef EXAM_CONTROLLER_CONTROLLER_H__
#define EXAM_CONTROLLER_CONTROLLER_H__

#include <QWidget>
#include <QEvent>
#include "View/view.h"

class Controller : public QWidget {
 Q_OBJECT
 public:
  Controller();
  void Connect();
  void ConnectCount();
  void ConnectView();
  void ConnectQuestionView();

 public slots:

 private:
  View* view_;
};

#endif //EXAM_CONTROLLER_CONTROLLER_H__
