// #include "./libs/s21_math.a"
#include <stdio.h>
#include <stdlib.h>

#include "s21_calc.h"
// правильно освободить память
s21_linked_list *s21_polish_notanion(s21_linked_list *head) {
  s21_linked_list *signs = s21_create_node(0, 0, -5);
  s21_linked_list *head_stack = s21_create_node(0, 0, -5);
  s21_linked_list *tail_stack = NULL;

  while (head != NULL) {
    if (head->type == -1) {
      // разгрузить
      if (head_stack->type == -5) {
        s21_copy_head(head, head_stack);
        tail_stack = head_stack;
      } else
        tail_stack =
            s21_add_node(tail_stack, head->num, head->sign, head->type);

    } else {
      if (signs->type == -5)
        s21_copy_head(head, signs);
      else
        signs = s21_add_node(signs, head->num, head->sign, head->type);
      s21_put_sign(&tail_stack, &signs);
    }
    head = head->next;
  }
  while (signs != NULL) {
    if (signs->type != -5)
      tail_stack =
          s21_add_node(tail_stack, signs->num, signs->sign, signs->type);
    signs = s21_del_node(signs);
  }

  return head_stack;
}

void s21_put_sign(s21_linked_list **tail_stack, s21_linked_list **tail_signs) {
  if ((*tail_signs)->prev != NULL) {
    while ((*tail_signs)->prev != NULL &&
           (*tail_signs)->type <= (*tail_signs)->prev->type &&
           (*tail_signs)->prev->type != 4) {
      (*tail_stack) =
          s21_add_node((*tail_stack), (*tail_signs)->prev->num,
                       (*tail_signs)->prev->sign, (*tail_signs)->prev->type);
      (*tail_signs) = s21_del_node((*tail_signs)->prev);
    }
  }
  if ((*tail_signs)->sign == ')') {
    // s21_linked_list *save = (*tail_signs);
    // (*tail_signs) = (*tail_signs)->prev;
    // free(save);
    (*tail_signs) = (*tail_signs)->prev;
    s21_del_node((*tail_signs)->next);
    while ((*tail_signs)->sign != '(') {
      (*tail_stack) = s21_add_node((*tail_stack), (*tail_signs)->num,
                                   (*tail_signs)->sign, (*tail_signs)->type);
      // save = (*tail_signs);
      // (*tail_signs) = (*tail_signs)->prev;
      // free(save);
      (*tail_signs) = (*tail_signs)->prev;
      s21_del_node((*tail_signs)->next);
    }
    (*tail_signs) = s21_del_node(*tail_signs);
    if ((*tail_signs) != NULL) {
      (*tail_signs)->next = NULL;
    } else {
      *tail_signs = s21_create_node(0, 0, -5);
    }
  }
}

int s21_copy_head(s21_linked_list *head, s21_linked_list *clone) {
  int flag = 0;
  if (head == NULL || clone == NULL)
    flag = 1;
  else {
    clone->num = head->num;
    clone->sign = head->sign;
    clone->type = head->type;
  }
  return flag;
}
