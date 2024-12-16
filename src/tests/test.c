#include <stdio.h>

#include "s21_calc.h"

int main() {
  s21_linked_list* ll = s21_create_node(0, '-', 0);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 2, 'E', -1);
  s21_add_node(ll, 0, '+', 0);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 2.13, 'E', -1);
  s21_add_node(ll, 0, '+', 0);
  s21_add_node(ll, 3, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, '/', 1);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 0, 's', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 9, 'E', -1);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 2, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, '^', 2);
  s21_add_node(ll, 2, 'E', -1);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 6, 'E', -1);
  s21_add_node(ll, 0, '/', 1);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 7, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, ')', 4);
  s21_validator(ll);
  s21_clear(ll);
  ll = s21_create_node(0, '/', 1);
  ll->next = NULL;
  // s21_add_node(ll, 0, '*', 1);
  s21_validator(ll);
  s21_clear(ll);

  ll = s21_create_node(15, 'E', -1);
  s21_add_node(ll, 0, 's', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 4, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_validator(ll);
  s21_clear(ll);

  ll = s21_create_node(0, '-', 0);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 2, 'E', -1);
  s21_add_node(ll, 0, '+', 0);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 2.13, 'E', -1);
  s21_add_node(ll, 0, '+', 0);
  s21_add_node(ll, 3, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, '/', 1);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 0, 's', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 9, 'E', -1);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 2, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, '^', 2);
  s21_add_node(ll, 2, 'E', -1);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 6, 'E', -1);
  s21_add_node(ll, 0, '/', 1);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 7, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_validator(ll);
  s21_clear(ll);

  ll = s21_create_node(15, 'E', -1);
  s21_add_node(ll, 0, '*', 1);
  s21_add_node(ll, 0, '*', 1);
  s21_validator(ll);
  s21_clear(ll);

  ll = s21_create_node(0, '(', 4);
  s21_add_node(ll, 0, '*', 1);
  s21_add_node(ll, 15, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_validator(ll);
  s21_clear(ll);

  ll = s21_create_node(0, '(', 1);
  s21_add_node(ll, 0, '-', 1);
  s21_add_node(ll, 4, 'E', 0);
  s21_add_node(ll, 0, ')', 1);
  s21_validator(ll);
  s21_clear(ll);

  ll = s21_create_node(0, '(', 4);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 4, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, 't', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 4, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_validator(ll);
  s21_clear(ll);

  ll = s21_create_node(0, '-', 0);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 2, 'E', -1);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 2.13, 'E', -1);
  s21_add_node(ll, 0, '+', 0);
  s21_add_node(ll, 3, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, '/', 1);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 0, 's', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 9, 'E', -1);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 2, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, '^', 2);
  s21_add_node(ll, 2, 'E', -1);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 6, 'E', -1);
  s21_add_node(ll, 0, '/', 1);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 7, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, ')', 4);
  s21_validator(ll);
  s21_clear(ll);

  long double res = 0;
  s21_linked_list* polish = NULL;
  ll = s21_create_node(0, '-', 0);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 2, 'E', -1);
  s21_add_node(ll, 0, '+', 0);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 2.13, 'E', -1);
  s21_add_node(ll, 0, '+', 0);
  s21_add_node(ll, 3, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, '/', 1);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 0, 's', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 9, 'E', -1);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 2, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, '^', 2);
  s21_add_node(ll, 2, 'E', -1);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 6, 'E', -1);
  s21_add_node(ll, 0, '/', 1);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 7, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, ')', 4);
  if (!s21_validator(ll)) {
    polish = s21_polish_notanion(ll);
    s21_calculator(polish, &res);
  }

  s21_clear(ll);
  return 0;
}