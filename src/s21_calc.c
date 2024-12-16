#include "s21_calc.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int s21_calculator(s21_linked_list *head, double *res) {
  // s21_linked_list *clone = head;
  *res = 0;
  int flag = 0;
  char sign;
  int mode = 0;
  if (head == NULL) {
    flag = 1;
  } else if (head->next == NULL && head->type == -1) {
    *res = head->num;
  } else {
    head = head->next;
  }
  while (head != NULL && flag != 1) {
    if (head->next == NULL && head->prev == NULL) {
      break;
    }
    if (head->type == -1) {
      head = head->next;
      continue;
    } else {
      sign = head->sign;
      mode = 0;
      if (sign == '+')
        head->prev->num += head->prev->prev->num;

      else if (sign == '-')
        head->prev->num = head->prev->prev->num - head->prev->num;

      else if (sign == '*')
        head->prev->num *= head->prev->prev->num;

      else if (sign == '/') {
        if (head->prev->num != 0)
          head->prev->num = head->prev->prev->num / head->prev->num;
        else
          flag = 1;

      } else if (sign == 'm') {
        head->prev->num = fmod(head->prev->prev->num, head->prev->num);
        if (head->prev->num == NAN) flag = 1;
      }

      else if (sign == '^') {
        if (head->next != NULL && head->next->next != NULL &&
            head->next->next->sign == '^') {
          head->prev->num = powl(head->prev->num, head->next->num);
          s21_del_node(head->next->next);
          s21_del_node(head->next);
        }
        head->prev->num = powl(head->prev->prev->num, head->prev->num);
      }

      else
        mode = 1;

      if (sign == '~') head->prev->num *= -1;

      if (sign == 'l') head->prev->num = log10(head->prev->num);

      if (sign == 'a') head->prev->num = atan(head->prev->num);

      if (sign == 'i') head->prev->num = asin(head->prev->num);

      if (sign == 'o') head->prev->num = acos(head->prev->num);

      if (sign == 't') head->prev->num = tan(head->prev->num);

      if (sign == 'c') head->prev->num = cos(head->prev->num);

      if (sign == 's') head->prev->num = sin(head->prev->num);

      if (sign == 'n') head->prev->num = log(head->prev->num);

      if (sign == 'q') head->prev->num = sqrt(head->prev->num);

      // if (head->prev->num == NAN || head->prev->num == INFINITY) flag = 1;

      head = head->prev;
      *res = flag == 1 ? NAN : head->num;
      s21_del_node(head->next);
      if (!mode) s21_del_node(head->prev);
    }
  }
  // res = head->num;
  // s21_clear(head);
  while (head != NULL) head = s21_del_node(head);
  return flag;
}
