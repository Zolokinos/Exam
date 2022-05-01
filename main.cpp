#include <iostream>
#include <QApplication>
#include "View/view.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  View view;
  view.show();

  return QApplication::exec();
}