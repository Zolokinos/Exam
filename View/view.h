#ifndef EXAM_VIEW_VIEW_H__
#define EXAM_VIEW_VIEW_H__

#include <QMainWindow>
#include <QBrush>
#include <QHeaderView>
#include <QSpinBox>
#include <QListWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QString>
#include <QObject>
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
  void SetQuestionView();
  void FullSetQuestionView(int num = -1, const QString& string = QString(QMainWindow::tr("")));
  void SetCount();
  void SetView(int num = 0);
  void FullSetView(int num = 0);
  void CastView(int num, int non_num = 0);

 signals:
  void QTableWidgetCellClicked(int row, int = 0);
  void QTableWidgetCellDoubleClicked(int row, int = 0);
  void ValueChanged(int value);

 private:
  Model* model_;
  QSpinBox* count_;
  QWidget* central_;

  QTableWidget* view_;
  QGridLayout* grid_layout_;
  QGroupBox* question_view_;

  QHBoxLayout* question_view_layout;
};

#endif //EXAM_VIEW_VIEW_H__
