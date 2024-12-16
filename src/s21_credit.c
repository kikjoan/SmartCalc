#include <math.h>

#include "s21_calc.h"

s21_bank* s21_credit(long double loan, int term, double rate, int type,
                     int month, s21_bank* blank) {
  long double kf;
  long double month_rate = rate / 12 / 100;
  if (type == 0) {
    kf = (month_rate * pow((1 + month_rate), term)) /
         (pow(1 + month_rate, term) - 1);
    blank->mpai = loan * kf;
    blank->total_payout = blank->mpai * term;
    blank->toll = blank->total_payout - loan;
  } else {
    // body_payment see in mainwindow
    blank->remaining_debt = loan - (blank->body_payment * month);
    blank->total_payout =
        blank->remaining_debt *
        month_rate;  // проценты, которые нужно заплатить за конкретный месяц
    blank->toll += blank->total_payout;
  }
  return blank;
}
