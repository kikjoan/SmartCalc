#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "s21_graph.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  S21_graph s21_graph;
  QFont font;

 private slots:
  // 0-num 1-oper 3-logic
  void s21_add();
  void s21_remove();
  void s21_eq();
  void on_b_graph_clicked();
  void s21_credit_calc();
};

#endif  // MAINWINDOW_H
