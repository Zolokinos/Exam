#include <QString>
#include <iostream>
#include "view.h"

View::View() :
    model_(new Model),
    grid_layout_(new QGridLayout),
    count_(new QSpinBox(this)),
    central_(new QWidget(this)),
    view_(new QTableWidget(this)) {
  show();
  central_->setLayout(grid_layout_);
  setCentralWidget(central_);
  SetWidgets();
}

void View::SetWidgets() {
  SetView();
  SetCount();

}

void View::SetCount() {
  grid_layout_->addWidget(count_, 0, 0);
  connect(count_, &QSpinBox::valueChanged, this, &View::ValueChanged);
}

void View::SetView(int num) {
  grid_layout_->addWidget(view_, 1, 0);
  FullSetView(num);
}

void View::CastQuestionView(int num, int) {
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
    connect(view_, &QTableWidget::cellClicked, this, &View::QTableWidgetCellClicked);
    connect(view_, &QTableWidget::cellDoubleClicked, this, &View::QTableWidgetCellDoubleClicked);
  }
  // view_->setSelectionMode(QAbstractItemView::NoSelection);
}

