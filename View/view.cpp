#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include "view.h"
View::View() :
    model_(new Model),
    count_(new QSpinBox(this)),
    grid_layout_(new QGridLayout()),
    question_view_(new QGroupBox(this)),
    question_view_layout(new QHBoxLayout(question_view_)) {
  grid_layout_->addWidget(count_, 0, 0);
  SetWidgets();
}

void View::SetWidgets() {
  SetView();
  FullSetView(1, QMainWindow::tr("23"));
}

void View::SetView() {
  grid_layout_->addWidget(question_view_, 1, 1);
  question_view_->setLayout(question_view_layout);
}

void View::FullSetView(int num, const QString& string) {
  QLabel* number = new QLabel(QMainWindow::tr("%1").arg(num), question_view_);
  QLabel* name = new QLabel(QMainWindow::tr("%1").arg(num) + QMainWindow::tr("Билет"), question_view_);
  QLineEdit* name_edit = new QLineEdit(QMainWindow::tr("%1").arg(num) + QMainWindow::tr("Билет"), question_view_);
  QComboBox* status = new QComboBox(question_view_);
  status->addItems(std::initializer_list<QString> {QMainWindow::tr("Не просматривался"), QMainWindow::tr("Не выучен"), QMainWindow::tr("Выучен")});
}
