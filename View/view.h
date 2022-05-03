#ifndef EXAM_VIEW_VIEW_H__
#define EXAM_VIEW_VIEW_H__

#include <QMainWindow>
#include <QSpinBox>
#include <QListWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QString>
#include <QObject>

#include "Model/model.h"

class View : public QMainWindow {
 public:
  View();
  void SetWidgets();
  void SetView();
  void FullSetView(int num = -1, const QString& string = QString(QMainWindow::tr("")));

 private:
  Model* model_;
  QSpinBox* count_;
  QListWidget* view_;

  QGridLayout* grid_layout_;
  QGroupBox* question_view_;
  QHBoxLayout* question_view_layout;
};

#endif //EXAM_VIEW_VIEW_H__
