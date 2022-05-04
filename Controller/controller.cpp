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
  ConnectButtons();
  ConnectModel();
}

void Controller::ConnectCount() {
  connect(view_, &View::ValueChanged, this, [&] (int num) {
    view_->ClearQuestionView();
    view_->ReSetView(num);
  });
}

void Controller::ConnectQuestionView() {
  connect(view_, &View::NameChanged, this, [&] (const QString& name) {
    view_->ChangeQVName(name);
  });
  connect(view_, &View::QTableWidgetCellDoubleClicked, this, [&] (int num) {
    view_->ChangeCheckStatus(num);
  });
  connect(view_, &View::StatusChanged, view_, &View::HardCastView);
}

void Controller::ConnectView() {
  connect(view_, &View::QTableWidgetCellClicked, this, [&] (int num){
    QString name = view_->GetNameTicket(num);
    view_->CastQuestionView(num, name);
  });
  connect(view_, &View::QTableWidgetCellDoubleClicked, this, [&] (int num) {
    view_->CastView(num);
  });
  connect(view_, &View::NameChanged, this, [&] (const QString& name) {
    view_->ChangeVName(name);
  });
}

void Controller::ConnectButtons() {
  connect(view_, &View::PreviousClicked, view_, &View::PreviousActivate);
}

void Controller::ConnectModel() {
  connect(view_, &View::ValueChanged, view_, &View::ModelClear);
  connect(view_, &View::QTableWidgetCellClicked, view_, &View::ModelPush);
}
