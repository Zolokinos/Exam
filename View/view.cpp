#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QString>
#include <iostream>
#include "view.h"

View::View() :
    model_(new Model),
    count_(new QSpinBox(this)),
    central_(new QWidget(this)),
    view_(new QTableWidget(this)),
    grid_layout_(new QGridLayout),
    question_view_(new QGroupBox(this)),
    question_view_layout(new QHBoxLayout(question_view_)) {
  show();
  central_->setLayout(grid_layout_);
  setCentralWidget(central_);
  SetWidgets();
  grid_layout_->addWidget(count_, 0, 0);
}

void View::SetWidgets() {
  SetCount();
  SetQuestionView();
  SetView();
}

void View::SetQuestionView() {
  grid_layout_->addWidget(question_view_, 1, 1);
  question_view_->setLayout(question_view_layout);
  FullSetQuestionView();
}

void View::FullSetQuestionView(int num, const QString& string) {
  QLabel* number = new QLabel(QMainWindow::tr("%1").arg(num), question_view_);
  QLabel* name = new QLabel(QMainWindow::tr("%1").arg(num) + QMainWindow::tr("Билет"), question_view_);
  QLineEdit* name_edit = new QLineEdit(QMainWindow::tr("%1").arg(num) + QMainWindow::tr("Билет"), question_view_);
  QComboBox* status = new QComboBox(question_view_);
  status->addItems(std::initializer_list<QString> {QMainWindow::tr("Не просматривался"), QMainWindow::tr("Не выучен"), QMainWindow::tr("Выучен")});
}

void View::SetCount() {
  grid_layout_->addWidget(count_, 0, 0);
  connect(count_, &QSpinBox::valueChanged, this, &View::ValueChanged);
}

void View::SetView(int num) {
  grid_layout_->addWidget(view_, 1, 0);
  connect(view_, &QTableWidget::cellClicked, this, &View::QTableWidgetCellClicked);
  connect(view_, &QTableWidget::cellDoubleClicked, this, &View::QTableWidgetCellDoubleClicked);
  view_->setEditTriggers(QAbstractItemView::NoEditTriggers);
  view_->setSelectionMode(QAbstractItemView::NoSelection);
  FullSetView(num);
}

void View::CastView(int num, int) {
  QTableWidgetItem* item = view_->item(num, 0);
  if (item->background().color() == QColor(37, 194, 84)) {
    item->setBackground(QColor(255, 242, 0));
  } else {
    item->setBackground(QColor(37, 194, 84));
  }
}

void View::FullSetView(int num) {
  view_->verticalHeader()->hide();
  view_->horizontalHeader()->hide();
  view_->setColumnCount(1);
  view_->setRowCount(num);
  for (int i = 0; i < num; ++i) {
    QTableWidgetItem* newItem = new QTableWidgetItem(tr("%1").arg(i + 1));
    newItem->setBackground(Qt::white);
    view_->setItem(i, 0, newItem);
  }
}

