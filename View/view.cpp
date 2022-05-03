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
    left_part_(new QVBoxLayout()),
    right_part_(new QVBoxLayout()),
    linked_parts_(new QHBoxLayout()),
    question_view_(new QGroupBox(this)),
    question_view_layout(new QVBoxLayout(question_view_)) {
  show();
  setGeometry(650, 300, 400, 300);
  central_->setLayout(linked_parts_);
  linked_parts_->addLayout(left_part_, 4);
  linked_parts_->addLayout(right_part_, 6);
  setCentralWidget(central_);
  SetWidgets();
}

void View::SetWidgets() {
  SetCount();
  SetView();
  SetQuestionView();
}

void View::SetQuestionView() {
  right_part_->addWidget(question_view_);
  question_view_->setLayout(question_view_layout);
  number_ = new QLabel(question_view_);
  number_->setAlignment(Qt::AlignCenter);
  name_ = new QLabel(question_view_);
  name_->setWordWrap(true);
  name_edit_ = new QLineEdit(question_view_);
  name_edit_->setDisabled(true);
  status_ = new QComboBox(question_view_);
  status_->addItems(std::initializer_list<QString> {
      QMainWindow::tr("Не просматривался"),
      QMainWindow::tr("Не выучен"),
      QMainWindow::tr("Выучен")});
  question_view_layout->addWidget(number_);
  question_view_layout->addWidget(name_);
  question_view_layout->addWidget(name_edit_);
  question_view_layout->addWidget(status_);
  connect(name_edit_, &QLineEdit::textChanged, this, &View::NameChanged);
}

void View::FullSetQuestionView(int num, const QString& name_ticket) {
  number_->show();
  number_->setText(QMainWindow::tr("%1").arg(num + 1));
  name_->setText(name_ticket);
  name_edit_->setDisabled(false);
  name_edit_->setText(name_ticket);
}

void View::SetCount() {
  left_part_->addWidget(count_);
  connect(count_, &QSpinBox::valueChanged, this, &View::ValueChanged);
}

void View::SetView(int num) {
  left_part_->addWidget(view_);
  connect(view_, &QTableWidget::cellClicked, this, &View::QTableWidgetCellClicked);
  connect(view_, &QTableWidget::cellDoubleClicked, this, &View::QTableWidgetCellDoubleClicked);
  view_->setEditTriggers(QAbstractItemView::NoEditTriggers);
  view_->setSelectionMode(QAbstractItemView::NoSelection);
  view_->verticalHeader()->hide();
  view_->horizontalHeader()->hide();
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
  view_->setColumnCount(1);
  view_->setRowCount(num);
  for (int i = 0; i < num; ++i) {
    QTableWidgetItem* newItem = new QTableWidgetItem(QMainWindow::tr("Билет №") + QMainWindow::tr("%1").arg(i + 1));
    newItem->setBackground(Qt::white);
    view_->setItem(i, 0, newItem);
  }
}

QString View::GetNameTicket(int num) {
  QTableWidgetItem* item = view_->item(num, 0);
  return item->text();
}

void View::ClearQuestionView() {
  number_->hide();
  name_->setText(QMainWindow::tr(""));
  name_edit_->setText(QMainWindow::tr(""));
  name_edit_->setDisabled(true);
}

void View::ChangeQVName(const QString& name) {
  name_->setText(name);
}

void View::ChangeVName(const QString& name) {
  int num = number_->text().toInt();
  --num;
  view_->item(num, 0)->setText(name);
}

