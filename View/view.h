#ifndef EXAM_VIEW_VIEW_H__
#define EXAM_VIEW_VIEW_H__

#include <QMainWindow>
#include <QBrush>
#include <QHeaderView>
#include <QSpinBox>
#include <QListWidget>
#include <QGridLayout>
#include <QButtonGroup>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QColor>

#include "Model/model.h"

class View : public QMainWindow {
  Q_OBJECT
 public:
  View();
  void SetWidgets();
  void SetCount();
  void SetView(int num = 0);
  void FullSetView(int num = 0);
  void CastQuestionView(int num, int non_num = 0);

  signals:
  void QTableWidgetCellClicked(int row, int = 0);
  void QTableWidgetCellDoubleClicked(int row, int = 0);

  void ValueChanged(int value);
 public slots:

 private:
  Model* model_;
  QGridLayout* grid_layout_;
  QSpinBox* count_;
  QWidget* central_;
  QTableWidget* view_;
};

#endif //EXAM_VIEW_VIEW_H__
