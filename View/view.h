#ifndef EXAM_VIEW_VIEW_H__
#define EXAM_VIEW_VIEW_H__

#include <QMainWindow>
#include <QBrush>
#include <QHeaderView>
#include <QSpinBox>
#include <QListWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QString>
#include <QObject>
#include <QButtonGroup>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QColor>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QProgressBar>

#include "Model/model.h"

class View : public QMainWindow {
  Q_OBJECT
 public:
  View();
  void SetWidgets();
  void SetQuestionView();
  void CastQuestionView(int num = -1, const QString& name_ticket = QString(QMainWindow::tr("")));
  void SetCount();
  void SetView(int num = 0);
  void ReSetView(int num = 0);
  void CastView(int num, int non_num = 0);
  QString GetNameTicket(int num = 0);
  void SetButtons();
  void ClearQuestionView();
  void ChangeQVName(const QString& name);
  void ChangeVName(const QString& name);
  void ChangeCheckStatus(int num);
  QString InitialText(int num);
  void SetBars();

 signals:
  void QTableWidgetCellClicked(int row, int = 0);
  void QTableWidgetCellDoubleClicked(int row, int = 0);
  void ValueChanged(int value);
  void NameChanged(const QString& name);
  void StatusChanged(int num);
  void PreviousClicked();
  void NextClicked();
  void QTableWidgetCellChanged(int num);

 public slots:
  void HardCastView();
  void SetBar(int num);
  void ModelPush(int num);
  void PreviousActivate();
  void NextCall();
  void SetFormated(int num);
  void ChangeSets(int num);

 private:
  Model* model_;
  QSpinBox* count_;
  QWidget* central_;

  QTableWidget* view_;
  QVBoxLayout* left_part_;
  QVBoxLayout* right_part_;
  QHBoxLayout* linked_parts_;

  QGroupBox* question_view_;
  QVBoxLayout* question_view_layout;
  QLabel* number_{};
  QLabel* name_{};
  QLineEdit* name_edit_{};
  QComboBox* status_{};
  QPushButton* next_question_;
  QPushButton* previous_question_;
  QHBoxLayout* buttons_link_;
  QProgressBar* total_progress_;
  QProgressBar* green_progress_;
};

#endif //EXAM_VIEW_VIEW_H__
