#include "view.h"
View::View() :
  model_(new Model),
  spin_box_(new QSpinBox(this)),
  list_widget_(new QListWidget(this)),
  grid_layout_(new QGridLayout(this)) {
  grid_layout_->addWidget(spin_box_, 0, 0);
}
