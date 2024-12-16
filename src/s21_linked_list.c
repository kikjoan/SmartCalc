#include <stdio.h>
#include <stdlib.h>

#include "s21_calc.h"

s21_linked_list *s21_create_node(double num, char sign, int type) {
  s21_linked_list *list = malloc(sizeof(s21_linked_list) * 1);
  if (list == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  list->next = NULL;
  list->prev = NULL;
  list->type = type;
  list->num = num;
  list->sign = sign;
  return list;
}

s21_linked_list *s21_add_node(s21_linked_list *node, double num, char sign,
                              int type) {
  if (node == NULL) return s21_create_node(num, sign, type);

  s21_linked_list *last = node;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = s21_create_node(num, sign, type);
  last->next->prev = last;
  return last->next;
}

s21_linked_list *s21_del_node(s21_linked_list *node) {
  s21_linked_list *ret = NULL;
  if (node == NULL) return node;

  if (node->prev != NULL) {
    node->prev->next = node->next;
    ret = node->prev;
  }

  if (node->next != NULL) {
    node->next->prev = node->prev;
    ret = node->next;
  }
  node->next = NULL;
  node->prev = NULL;

  free(node);
  return ret;
}

void s21_clear(s21_linked_list *head) {
  s21_linked_list *next = NULL;
  while (head != NULL) {
    next = head->next;
    free(head);
    head = next;
  }
  // head = s21_del_node(head);
}

// void s21_print_list(s21_linked_list *head) {
//   while (head->next != NULL) {
//     printf("%d %lf %c\n", head->type, head->num, head->sign);
//     head = head->next;
//   }
//   printf("%d %lf %c\n", head->type, head->num, head->sign);
// }
