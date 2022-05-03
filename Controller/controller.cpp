#include <QInputEvent>
#include "controller.h"
Controller::Controller() :
    view_(new View) {
  Connect();
}

void Controller::Connect() {
  ConnectView();
  ConnectCount();
}

void Controller::ConnectCount() {
  connect(view_, &View::ValueChanged, this, [&] (int num) {
    view_->FullSetView(num);
  });
}

void Controller::ConnectView() {
  // connect(view_, &View::QTableWidgetCellClicked, view_, &View::CastQuestionView);
  connect(view_, &View::QTableWidgetCellDoubleClicked, this, [&] (int num) {
    view_->CastQuestionView(num);
  });
}
