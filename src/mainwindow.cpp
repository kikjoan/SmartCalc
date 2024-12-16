#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include "s21_calc.h"

static int i = -1, counter = 0;
static s21_linked_list *head = NULL;
static s21_linked_list *tail = NULL;
static bool isX = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  font = ui->label->font();
  ui->credit_table->setColumnCount(3);
  ui->credit_table->setHorizontalHeaderLabels(
      {"Сумма платежа", "Платеж по процентам", "Остаток долга"});
  ui->credit_table->horizontalHeaderItem(0);
  // ui->credit_table->setColumnWidth(0, 25);
  ui->credit_table->setColumnWidth(0, 163);
  ui->credit_table->setColumnWidth(1, 165);
  ui->credit_table->setColumnWidth(2, 180);

  connect(ui->b0, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b1, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b2, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b3, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b4, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b5, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b6, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b7, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b8, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b9, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_plus, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_muilti, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_minus, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_div, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_mod, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_right, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_left, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_pow, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_log, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_ln, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_sqrt, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_atan, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_asin, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_acos, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_cos, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_sin, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_tan, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_dot, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_x, SIGNAL(clicked()), this, SLOT(s21_add()));
  connect(ui->b_c, SIGNAL(clicked()), this, SLOT(s21_remove()));
  connect(ui->b_equal, SIGNAL(clicked()), this, SLOT(s21_eq()));
  connect(ui->credit_calc, SIGNAL(clicked()), this, SLOT(s21_credit_calc()));
}

MainWindow::~MainWindow() { delete ui; }

// 0-num 1-oper 3-logic
void MainWindow::s21_add() {
  QPushButton *b = (QPushButton *)sender();
  // double d;

  if (head == NULL) {
    head = s21_create_node(0, 'E', -2);
    tail = head;
    ui->label->setText("");
  }

  if (counter >= 256) {
    counter = 0;
    s21_remove();
    ui->label->setText("Too many characters");
  } else if (b->text() >= '0' && b->text() <= '9') {
    if (tail->sign != 'x') {
      if (i == 1) {
        tail = s21_add_node(head, 0, 'E', -1);
        ui->label->setText(ui->label->text() + ' ');
      }
      QString str = ui->label->text() + b->text();
      tail->num = str.split(' ').takeLast().toDouble();
      tail->type = -1;
      ui->label->setText(str);
      i = 0;
    }
  } else if (b->text() == 'x') {
    if (i == -1) {
      ui->label->setText(ui->label->text() + ' ' + 'x');
      tail->num = ui->doubleSpinBox->value();
      tail->type = -1;
      tail->sign = 'x';
      ui->doubleSpinBox->setValue(0);
      isX = true;
      i = 0;
    } else if (i == 1) {
      tail = s21_add_node(head, 0, 'x', -1);
      ui->label->setText(ui->label->text() + ' ' + 'x');
      tail->num = ui->doubleSpinBox->value();
      ui->doubleSpinBox->setValue(0);
      isX = true;
      i = 0;
    }
  } else if (b->text() == '.') {
    if (i == 0 && tail->sign != 'x') {
      if (!ui->label->text().split(' ').takeLast().contains('.')) {
        QString str = ui->label->text() + b->text();
        tail->num = str.split(' ').takeLast().toDouble();
        ui->label->setText(str);
      }
    }
  } else {
    if (i != -1) {
      tail = s21_add_node(head, 0, 'E', 0);
    }
    i = 1;
    ui->label->setText(ui->label->text() + ' ' + b->text());
    // log - l; ln - n; sqrt - q; atan - a; asin -i; acos - o;
    tail->type = 3;
    if (b->text() == "log")
      tail->sign = 'l';
    else if (b->text() == "ln")
      tail->sign = 'n';
    else if (b->text() == "sqrt")
      tail->sign = 'q';
    else if (b->text() == "atan")
      tail->sign = 'a';
    else if (b->text() == "asin")
      tail->sign = 'i';
    else if (b->text() == "acos")
      tail->sign = 'o';
    else if (b->text() == "tan")
      tail->sign = 't';
    else if (b->text() == "cos")
      tail->sign = 'c';
    else if (b->text() == "sin")
      tail->sign = 's';
    else if (tail->sign == 'E')
      tail->type = 1;
    // if (tail->sign == '~') tail->type = 1;
    if (b->text() == "mod")
      tail->sign = 'm';
    else if (b->text() == '*')
      tail->sign = '*';
    else if (b->text() == '/')
      tail->sign = '/';
    else if (tail->sign == 'E')
      tail->type = 4;
    if (b->text() == '(')
      tail->sign = '(';
    else if (b->text() == ')')
      tail->sign = ')';
    else if (tail->sign == 'E')
      tail->type = 2;
    if (b->text() == '^')
      tail->sign = '^';
    else if (tail->sign == 'E')
      tail->type = 0;
    if (b->text() == '-')
      tail->sign = '-';
    else if (b->text() == '+')
      tail->sign = '+';
    if (tail->type == 3) {
      ui->label->setText(ui->label->text() + ' ' + '(');
      tail = s21_add_node(tail, 0, '(', 4);
    }
  }
  counter = ui->label->text().length();
  // if (head != NULL &&
  //     font.pointSize() - (int)(counter / 4 - head->type * 1.4) >= 15)
  //   font.setPointSize(font.pointSize() - (int)(counter / 4 - head->type
  //   * 1.4));
  // else
  //   font.setPointSize(15);
  // ui->label->setFont(font);
}

void MainWindow::s21_remove() {
  s21_clear(head);
  head = NULL;
  i = -1;
  isX = false;
  counter = 0;
  ui->label->setText("");
  // font.setPointSize(60);
  // ui->label->setFont(font);
}

void MainWindow::s21_eq() {
  int valid = s21_validator(head);
  // std::printf("%d\n", valid);
  if (!valid && head != NULL) {
    QString str;
    double res;
    int flag;
    // s21_print_list(head);
    s21_linked_list *polish = s21_polish_notanion(head);
    // s21_print_list(polish);
    if (isX) {
      s21_graph.show();
      s21_graph.s21_print(polish);
    }
    s21_remove();
    flag = s21_calculator(polish, &res);
    if (!flag)
      str = QString::number(res, 'f', 7);
    else
      str = "NULL";
    ui->label->setText(str);
  } else {
    s21_remove();
    ui->label->setText("ERROR");
  }
}

void MainWindow::on_b_graph_clicked() {
  // s21_graph.s21_print(head);
  s21_graph.show();
}

void MainWindow::s21_credit_calc() {
  ui->credit_table->clear();
  ui->credit_table->setHorizontalHeaderLabels(
      {"Сумма платежа", "Платеж по процентам", "Остаток долга"});
  s21_bank blank = {0};
  if (ui->credit_radio_annu->isChecked()) {
    s21_credit(ui->s_loan->value(), ui->s_term->value(), ui->s_percent->value(),
               0, 0, &blank);
    ui->mount_pay->setText("Ежемесячный платеж: " +
                           QString::number(blank.mpai, 'F', 2));
  } else {
    QTableWidgetItem *qtwi;
    blank.body_payment = ui->s_loan->value() / ui->s_term->value();
    for (int i = 1; i <= ui->s_term->value(); i++) {
      ui->credit_table->insertRow(ui->credit_table->rowCount());
      s21_credit(ui->s_loan->value(), ui->s_term->value(),
                 ui->s_percent->value(), 1, i - 1, &blank);

      qtwi = new QTableWidgetItem();
      qtwi->setText(
          QString::number(blank.body_payment + blank.total_payout, 'F', 2));
      ui->credit_table->setItem(i - 1, 0, qtwi);

      qtwi = new QTableWidgetItem();
      qtwi->setText(QString::number(blank.total_payout, 'F', 2));
      ui->credit_table->setItem(i - 1, 1, qtwi);

      qtwi = new QTableWidgetItem();
      qtwi->setText(QString::number(
          ui->s_loan->value() - blank.body_payment * i, 'F', 2));
      ui->credit_table->setItem(i - 1, 2, qtwi);
    }
    blank.total_payout = blank.toll + ui->s_loan->value();
    if (ui->s_term->value() == 0)
      ui->mount_pay->setText("Ежемесячный платеж: NAN");
    else
      ui->mount_pay->setText(
          "Ежемесячный платеж: " + ui->credit_table->item(0, 0)->text() +
          "..." + ui->credit_table->item(ui->s_term->value() - 1, 0)->text());
  }
  ui->overpayment->setText("Переплата по кредиту: " +
                           QString::number(blank.toll, 'F', 2));
  ui->total_payout->setText("Общая выплата: " +
                            QString::number(blank.total_payout, 'F', 2));
}
