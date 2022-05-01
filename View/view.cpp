#include "view.h"
View::View() :
    model_(new Model),
    count_(new QSpinBox(this)),
    grid_layout_(new QGridLayout(this)),
    {
  grid_layout_->addWidget(count_, 0, 0);
}
