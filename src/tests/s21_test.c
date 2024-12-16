
#include "s21_test.h"

START_TEST(s21_validator_test1) {
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
  ck_assert_int_eq(s21_validator(ll), 0);
  s21_clear(ll);
}
END_TEST

START_TEST(s21_validator_test2) {
  s21_linked_list* ll = s21_create_node(0, '/', 1);
  ll->next = NULL;
  // s21_add_node(ll, 0, '*', 1);
  ck_assert_int_eq(s21_validator(ll), 1);
  s21_clear(ll);
}
END_TEST

START_TEST(s21_validator_test3) {
  s21_linked_list* ll = s21_create_node(15, 'E', -1);
  s21_add_node(ll, 0, 's', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 4, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  ck_assert_int_eq(s21_validator(ll), 1);
  s21_clear(ll);
}
END_TEST

START_TEST(s21_validator_test4) {
  s21_linked_list* ll = s21_create_node(0, '-', 0);
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
  ck_assert_int_eq(s21_validator(ll), 0);
  s21_clear(ll);
}
END_TEST

START_TEST(s21_validator_test5) {
  s21_linked_list* ll = s21_create_node(15, 'E', -1);
  s21_add_node(ll, 0, '*', 1);
  s21_add_node(ll, 0, '*', 1);
  ck_assert_int_eq(s21_validator(ll), 1);
  s21_clear(ll);
}
END_TEST

START_TEST(s21_validator_test6) {
  s21_linked_list* ll = s21_create_node(0, '(', 4);
  s21_add_node(ll, 0, '*', 1);
  s21_add_node(ll, 15, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  ck_assert_int_eq(s21_validator(ll), 1);
  s21_clear(ll);
}
END_TEST

START_TEST(s21_validator_test7) {
  s21_linked_list* ll = s21_create_node(0, '(', 1);
  s21_add_node(ll, 0, '-', 1);
  s21_add_node(ll, 4, 'E', 0);
  s21_add_node(ll, 0, ')', 1);
  ck_assert_int_eq(s21_validator(ll), 0);
  s21_clear(ll);
}
END_TEST

START_TEST(s21_validator_test8) {
  s21_linked_list* ll = s21_create_node(0, '(', 4);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 4, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, 't', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 4, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  ck_assert_int_eq(s21_validator(ll), 1);
  s21_clear(ll);
}
END_TEST

START_TEST(s21_validator_test9) {
  s21_linked_list* ll = s21_create_node(0, '-', 0);
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
  ck_assert_int_eq(s21_validator(ll), 0);
  s21_clear(ll);
}
END_TEST

START_TEST(s21_calc_test1) {
  double res = 0;
  s21_linked_list* polish = NULL;
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
  if (!s21_validator(ll)) {
    polish = s21_polish_notanion(ll);
    s21_calculator(polish, &res);
    ck_assert_float_eq_tol(res, -1.9805264, 1E-7);
  } else {
    ck_assert_float_eq(s21_validator(ll), 0);
  }
  s21_clear(ll);
}
END_TEST

START_TEST(s21_calc_test2) {
  double res = 0;
  s21_linked_list* polish = NULL;
  s21_linked_list* ll = s21_create_node(0, 'n', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 0, 'q', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 0, 'l', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 0, 'q', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 5233332.555, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, '*', 1);
  s21_add_node(ll, 0, 'l', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 3876.8768, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, ')', 4);
  if (!s21_validator(ll)) {
    polish = s21_polish_notanion(ll);
    s21_calculator(polish, &res);
    ck_assert_float_eq_tol(res, 0.6823182, 1E-7);
  } else {
    ck_assert_float_eq(s21_validator(ll), 0);
  }
  s21_clear(ll);
}
END_TEST

START_TEST(s21_calc_test3) {
  double res = 0;
  s21_linked_list* polish = NULL;
  s21_linked_list* ll = s21_create_node(2, 'E', -1);
  s21_add_node(ll, 0, '^', 2);
  s21_add_node(ll, 2, 'E', -1);
  s21_add_node(ll, 0, '^', 2);
  s21_add_node(ll, 3, 'E', -1);
  if (!s21_validator(ll)) {
    polish = s21_polish_notanion(ll);
    s21_calculator(polish, &res);
    ck_assert_float_eq_tol(res, 256, 1E-7);
  } else {
    ck_assert_float_eq(s21_validator(ll), 0);
  }
  s21_clear(ll);
}
END_TEST

START_TEST(s21_calc_test4) {
  double res = 0;
  s21_linked_list* polish = NULL;
  s21_linked_list* ll = s21_create_node(0, '~', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 0, '~', 3);
  s21_add_node(ll, 6, 'E', -1);
  s21_add_node(ll, 0, '*', 1);
  s21_add_node(ll, 0, '~', 3);
  s21_add_node(ll, 7, 'E', -1);
  s21_add_node(ll, 0, '+', 0);
  s21_add_node(ll, 0, 's', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 9, 'E', -1);
  s21_add_node(ll, 0, '*', 1);
  s21_add_node(ll, 6, 'E', -1);
  s21_add_node(ll, 0, '+', 0);
  s21_add_node(ll, 0, 'c', 3);
  s21_add_node(ll, 0, '(', 4);
  s21_add_node(ll, 0, '~', 3);
  s21_add_node(ll, 9, 'E', -1);
  s21_add_node(ll, 0, '^', 2);
  s21_add_node(ll, 0, '~', 3);
  s21_add_node(ll, 1, 'E', -1);
  s21_add_node(ll, 0, '-', 0);
  s21_add_node(ll, 5, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, '*', 1);
  s21_add_node(ll, 6, 'E', -1);
  s21_add_node(ll, 0, '+', 0);
  s21_add_node(ll, 3, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  s21_add_node(ll, 0, '/', 2);
  s21_add_node(ll, 3, 'E', -1);
  s21_add_node(ll, 0, '^', 2);
  s21_add_node(ll, 2, 'E', -1);
  s21_add_node(ll, 0, '^', 2);
  s21_add_node(ll, 3, 'E', -1);
  s21_add_node(ll, 0, ')', 4);
  if (!s21_validator(ll)) {
    polish = s21_polish_notanion(ll);
    s21_calculator(polish, &res);
    ck_assert_double_eq_tol(res, -42, 1E-7);
  } else {
    ck_assert_float_eq(s21_validator(ll), 0);
  }
  s21_clear(ll);
}
END_TEST

Suite* test_s21_calc() {
  TCase* tc_core = tcase_create("s21_calc");
  tcase_add_test(tc_core, s21_validator_test1);
  tcase_add_test(tc_core, s21_validator_test2);
  tcase_add_test(tc_core, s21_validator_test3);
  tcase_add_test(tc_core, s21_validator_test4);
  tcase_add_test(tc_core, s21_validator_test5);
  tcase_add_test(tc_core, s21_validator_test6);
  tcase_add_test(tc_core, s21_validator_test7);
  tcase_add_test(tc_core, s21_validator_test8);
  tcase_add_test(tc_core, s21_validator_test9);

  tcase_add_test(tc_core, s21_calc_test1);
  tcase_add_test(tc_core, s21_calc_test2);
  tcase_add_test(tc_core, s21_calc_test3);
  tcase_add_test(tc_core, s21_calc_test4);

  Suite* suite = suite_create("s21_calc");
  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  Suite* v = test_s21_calc();
  SRunner* srun = srunner_create(v);
  srunner_run_all(srun, CK_NORMAL);
  int fail = srunner_ntests_failed(srun);
  srunner_free(srun);
  return fail;
}