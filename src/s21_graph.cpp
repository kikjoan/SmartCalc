#include "s21_graph.h"

#include "ui_s21_graph.h"

S21_graph::S21_graph(QWidget *parent) : QWidget(parent), ui(new Ui::s21_graph) {
  ui->setupUi(this);
  ui->spinBox_MIN->setValue(-1000);
  ui->spinBox_max->setValue(1000);
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
}

S21_graph::~S21_graph() { delete ui; }

int S21_graph::s21_print(s21_linked_list *head) {
  int flag = 0;
  double res;
  s21_linked_list *copy_head;
  x.clear(), y.clear();
  ui->widget->clearGraphs();
  h = 0.001;
  xBegin = ui->spinBox_MIN->value();
  xEnd = ui->spinBox_max->value();
  N = (xEnd - xBegin) / h + 2;
  for (X = xBegin; X <= xEnd; X += h) {
    copy_head = s21_copy(head, X);
    flag = s21_calculator(copy_head, &res);
    if (!flag) {
      // if (isBreak) {
      //   ui->widget->addGraph();
      //   ui->widget->graph(graph++)->setData(x, y);
      //   ui->widget->replot();
      //   x.clear(), y.clear();
      // }
      x.push_back(X);
      y.push_back(res);
      // isBreak = false;
    } /*else {
      std::printf("AHAHHAHAHAHA");
      isBreak = true;
    }*/
  }
  // if (!x.isEmpty() && !y.isEmpty()) {
  ui->widget->addGraph();
  ui->widget->graph(0)->setData(x, y);
  ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
  ui->widget->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCircle, 3));
  ui->widget->replot();
  x.clear(), y.clear();
  //}
  return flag;
}

s21_linked_list *S21_graph::s21_copy(s21_linked_list *head, long double newX) {
  s21_linked_list *copy_head = s21_create_node(0, 0, 0);
  s21_linked_list *copy_copy_head = copy_head;
  s21_copy_head(head, copy_copy_head);
  if (copy_copy_head->sign == 'x') copy_copy_head->num = newX;
  head = head->next;
  while (head != NULL) {
    copy_copy_head =
        s21_add_node(copy_copy_head, head->num, head->sign, head->type);
    if (copy_copy_head->sign == 'x') copy_copy_head->num = newX;
    head = head->next;
  }
  return copy_head;
}

// скопировать head и рисоватm
