#include <check.h>
#include "../stack.h"

// Глобальные переменные для хранения имен тестов
const char* test_names[100];  // Максимальное количество тестов
int test_count = 0;

// Макрос для добавления теста и сохранения его имени
#define ADD_TEST(tc, test)            \
  do {                                \
    tcase_add_test(tc, test);         \
    test_names[test_count++] = #test; \
  } while (0)

// ANSI escape коды для цветов текста
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_RESET "\033[0m"

// Тесты
START_TEST(test_converter_1)
{
    char expression[] = "10-5+3";
    char postfix[100];
    converter(expression, postfix);
    ck_assert_str_eq(postfix, "10 5 - 3 + ");
}
END_TEST

START_TEST(test_calculate_1)
{
    char postfix[] = "10-5+3";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, 8.0, 1e-6);
}
END_TEST

START_TEST(test_calculate_2)
{
    char postfix[] = "-5*   (3    -1)";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, -10.0, 1e-6);
}
END_TEST

START_TEST(test_calculate_3)
{
    char postfix[] = "+    5*(3-   1)";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, 10.0, 1e-6);
}
END_TEST

START_TEST(test_calculate_4)
{
    char postfix[] = "9mod   2";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, 1.0, 1e-6);
}
END_TEST

START_TEST(test_calculate_5)
{
    char postfix[] = "2* (sin(1) + 1)";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, 3.682942, 1e-6);
}
END_TEST

START_TEST(test_calculate_6)
{
    char postfix[] = "-2+2*2";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, 2.0, 1e-6);
}
END_TEST

Suite* calculator_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("Calculator");

  tc_core = tcase_create("Core");

  // Тесты для конвертера
  ADD_TEST(tc_core, test_converter_1);

  // Тесты для калькуляции
  ADD_TEST(tc_core, test_calculate_1);
  ADD_TEST(tc_core, test_calculate_2);
  ADD_TEST(tc_core, test_calculate_3);
  ADD_TEST(tc_core, test_calculate_4);
  ADD_TEST(tc_core, test_calculate_5);
  ADD_TEST(tc_core, test_calculate_6);

  suite_add_tcase(s, tc_core);

  return s;
}
int main(void) {
  int number_failed;
  int total_tests;
  Suite* s;
  SRunner* sr;

  s = calculator_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  total_tests = srunner_ntests_run(sr);

  TestResult** all_results = srunner_results(sr);

  printf("\n------------------------------------\n");
  for (int i = 0; i < total_tests; i++) {
    const char* test_name = test_names[i];
    if (tr_rtype(all_results[i]) == CK_PASS) {
      printf("Тест %s - " COLOR_GREEN "Пройден" COLOR_RESET "\n", test_name);
    } else {
      printf("Тест %s - " COLOR_RED "Провален" COLOR_RESET "\n", test_name);
    }
  }

  free(all_results);

  printf("------------------------------------\n");
  printf("Всего тестов: %d\n", total_tests);
  printf("Провалено тестов: %d\n", number_failed);
  printf("------------------------------------\n");

  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
