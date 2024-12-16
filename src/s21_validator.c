#include <stdio.h>

#include "s21_calc.h"
// (2,13 + 3) / (sin(9 − 2) ^ 2 - 6 / (-7))
int s21_validator(s21_linked_list *head) {
  int flag = 0, couneter = 0, bracket = 0;
  if (head == NULL) flag = 1;
  while (head != NULL && !flag) {
    if (head->type == -1) {
      if (head->next != NULL) {
        switch (head->next->sign) {
          case '^':
          case '-':
          case '~':
          case '*':
          case '/':
          case '+':
          case 'm':
          case ')':
            flag = 0;
            break;
          default:
            flag = 1;
            break;
        }
      }
    } else {
      // If the cycle ends and the bracket is not equal to zero, it is an error.
      if (head->sign == ')') bracket--;
      if (head->sign == '(') bracket++;
      if (head->next == NULL && (head->sign != ')' || couneter == 0)) {
        flag = 1;
        break;
      }

      switch (head->sign) {
        case '-':
        case '~':
        case '+':
          // if (/*(head->sign == '-' || head->sign == '+') &&*/ couneter == 0
          // &&
          //     head->next != NULL) {
          flag = 0;
          if (head->sign == '-') {
            if ((head->next->sign == '(' || head->next->type == -1) &&
                head->prev == NULL) {
              head->sign = '~';
              head->type = 3;
            }
          } else if (head->next->type == 1 || head->next->type == 2 ||
                     head->next->sign == '~' || head->next->sign == ')')
            flag = 1;
          // else if (head->sign == '~') {
          //   if (head->next->type == 0) {
          //     head->next->num *= -1;
          //     head->sign = '+';
          //   } else if (head->next->sign != '(')
          //     head->sign = '-';
          // }

          break;
        case '^':
        case '*':
        case '/':
        case 'm':
          // if (couneter == 0 || head->next == NULL)
          //   flag = 1;
          // else
          if (head->next->type == -1 || head->next->type == 3 ||
              head->next->sign == '(' || head->next->type == 0) {
            flag = 0;
            // if (head->next->sign == '-' || head->next->sign == '+')
            if (head->next->sign == '-') {
              head->next->type = 3;
              head->next->sign = '~';
            } else if (head->next->sign == '+')
              flag = 1;
            if (head->sign == '^' && head->next->type == 0) flag = 1;
          } else
            flag = 1;
          break;
        case '(':
          switch (head->next->sign) {
            case ')':
            case '^':
            case '*':
            case '/':
            case 'm':
              flag = 1;
              break;
            case '-':
            case '+':
            case '~':
              flag = 0;
              if (head->next->sign == '-') {
                head->next->sign = '~';
                head->next->type = 3;
              }
              break;
            default:
              flag = 0;
              break;
          }
          break;
        case ')':
          if (head->next == NULL)
            flag = 0;
          else if (head->next->type == -1 || head->next->type == 3 ||
                   head->next->sign == '(' || head->next->sign == '~')
            flag = 1;
          else
            flag = 0;
          break;
          // default:
          //  flag = 1;
          // break;
          //}
      }
    }
    couneter++;
    head = head->next;
  }
  if (bracket != 0) flag = 1;
  return flag;
}
