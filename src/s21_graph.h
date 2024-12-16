#ifndef S21_GRAPH_H
#define S21_GRAPH_H

#include <QVector>
#include <QWidget>

#include "s21_calc.h"

namespace Ui {
class s21_graph;
}

class S21_graph : public QWidget {
  Q_OBJECT

 public:
  explicit S21_graph(QWidget *parent = nullptr);
  ~S21_graph();

 private:
  Ui::s21_graph *ui;
  long double xBegin, xEnd, h, X;
  int N;
  QVector<double> x, y;
  s21_linked_list *s21_copy(s21_linked_list *head, long double newX);

 public slots:
  int s21_print(s21_linked_list *head);
};

#endif  // S21_GRAPH_H
