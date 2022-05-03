#include <QInputEvent>
#include <iostream>
#include "controller.h"
Controller::Controller() :
    view_(new View) {
  Connect();
}

void Controller::Connect() {
  ConnectView();
  ConnectCount();
  ConnectQuestionView();
}

void Controller::ConnectCount() {
  connect(view_, &View::ValueChanged, this, [&] (int num) {
    view_->ClearQuestionView();
    view_->FullSetView(num);
  });
}

void Controller::ConnectQuestionView() {
  connect(view_, &View::NameChanged, this, [&] (const QString& name) {
    view_->ChangeQVName(name);
  });
}

void Controller::ConnectView() {
  connect(view_, &View::QTableWidgetCellClicked, this, [&] (int num){
    QString name = view_->GetNameTicket(num);
    view_->FullSetQuestionView(num, name);
  });
  connect(view_, &View::QTableWidgetCellDoubleClicked, this, [&] (int num) {
    view_->CastView(num);
    std::cout << num << std::endl;
  });
  connect(view_, &View::NameChanged, this, [&] (const QString& name) {
    view_->ChangeVName(name);
  });
}
