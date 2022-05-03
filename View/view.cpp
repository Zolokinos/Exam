#include "view.h"
View::View() :
    model_(new Model),
    count_(new QSpinBox(this)),
    grid_layout_(new QGridLayout(this)),
    question_view_(new QGroupBox(this)),
    question_view_layout(new QHBoxLayout(question_view_)) {
  grid_layout_->addWidget(count_, 0, 0);
  SetWidgets();
}

void View::SetWidgets() {
  SetGroupBox();
}

void View::SetGroupBox() {
  grid_layout_->addWidget(question_view_, 1, 1);
  question_view_->setLayout(question_view_layout);
}

void View::FullSetGroupBox() {

}
