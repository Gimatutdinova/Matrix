#include "test.h"

void run_testcase(Suite *testcase) {
  SRunner *runner = srunner_create(testcase);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  srunner_ntests_failed(runner);
  srunner_free(runner);
}

void run_all_testcases() {
  Suite *list_cases[] = {suite_s21_create_remove(),
                         suite_s21_equal(),
                         suite_s21_sum(),
                         suite_s21_sub(),
                         suite_s21_mult(),
                         suite_s21_transpose(),
                         suite_s21_calc_complements(),
                         suite_s21_determinant(),
                         suite_s21_inverse_matrix(),
                         NULL};
  for (int i = 0; list_cases[i] != NULL; i++) run_testcase(list_cases[i]);
}

int main() {
  srand(time(0));
  run_all_testcases();
  return 0;
}