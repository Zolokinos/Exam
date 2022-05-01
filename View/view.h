#ifndef EXAM_VIEW_VIEW_H__
#define EXAM_VIEW_VIEW_H__

#include <QMainWindow>
#include <QSpinBox>
#include <QListWidget>
#include <QGridLayout>

#include "Model/model.h"

class View : public QMainWindow {
 public:
  View();

 private:
  Model* model_;
  QSpinBox* spin_box_;
  QListWidget* list_widget_;
  QGridLayout* grid_layout_;
};

#endif //EXAM_VIEW_VIEW_H__
