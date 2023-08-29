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
    ck_assert_double_eq_tol(result, 10-5+3, 1e-6);
}
END_TEST

START_TEST(test_calculate_2)
{
    char postfix[] = "-5*   (3    -1)";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, -5*(3-1), 1e-6);
}
END_TEST

START_TEST(test_calculate_3)
{
    char postfix[] = "+    5*(3-   1)";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, 5*(3-1), 1e-6);
}
END_TEST

START_TEST(test_calculate_4)
{
    char postfix[] = "9mod   2";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, 9%2, 1e-6);
}
END_TEST

START_TEST(test_calculate_5)
{
    char postfix[] = "2* (sin(1) + 1)";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, 2*(sin(1)+1), 1e-6);
}
END_TEST

START_TEST(test_calculate_6)
{
    char postfix[] = "-2+2*2";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, -2+2*2, 1e-6);
}
END_TEST

START_TEST(test_calculate_7)
{
    char postfix[] = "1.25/3.45";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, 1.25/3.45, 1e-6);
}
END_TEST

START_TEST(test_calculate_8)
{
    char postfix[] = "1.25mod3.45";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, fmod(1.25, 3.45), 1e-6);
}
END_TEST

START_TEST(test_calculate_9)
{
    char postfix[] = "1.25^3.45";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, powf(1.25, 3.45), 1e-6);
}
END_TEST

START_TEST(test_calculate_10)
{
    char postfix[] = "(+5.23+1.25)*(0.25+0.001)";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, (+5.23+1.25)*(0.25+0.001), 1e-6);
}
END_TEST

START_TEST(test_calculate_11)
{
    char postfix[] = "sin((5.23+1.25)*(0.25+0.001))";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, sin((5.23+1.25)*(0.25+0.001)), 1e-6);
}
END_TEST

START_TEST(test_calculate_12)
{
    char postfix[] = "cos((5.23+1.25)*(0.25+0.001))";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, cos((5.23+1.25)*(0.25+0.001)), 1e-6);
}
END_TEST

START_TEST(test_calculate_13)
{
    char postfix[] = "tan((5.23+1.25)*(0.25+0.001))";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, tan((5.23+1.25)*(0.25+0.001)), 1e-6);
}
END_TEST

START_TEST(test_calculate_14)
{
    char postfix[] = "asin(7/7.7)";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, asin(7/7.7), 1e-6);
}
END_TEST

START_TEST(test_calculate_15)
{
    char postfix[] = "acos(7/7.7)";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, acos(7/7.7), 1e-6);
}
END_TEST

START_TEST(test_calculate_16)
{
    char postfix[] = "atan(7/7.7)";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, atan(7/7.7), 1e-6);
}
END_TEST

START_TEST(test_calculate_17)
{
    char postfix[] = "sqrt(1357-245)";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, sqrt(1357-245), 1e-6);
}
END_TEST

START_TEST(test_calculate_18)
{
    char postfix[] = "ln(1357-245)";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, log(1357-245), 1e-6);
}
END_TEST

START_TEST(test_calculate_19)
{
    char postfix[] = "log(1357-245)";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, log10(1357-245), 1e-6);
}
END_TEST

START_TEST(test_calculate_20)
{
    char postfix[] = "log(32+1)*7/11*432*(sin(2)*12-45+4)/2";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, log10(32+1)*7/11*432*(sin(2)*12-45+4)/2, 1e-6);
}
END_TEST

START_TEST(test_calculate_21)
{
    char postfix[] = "cos(sin(tan(-0.005)))";
    double result = calculate(postfix);
    ck_assert_double_eq_tol(result, cos(sin(tan(-0.005))), 1e-6);
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
  ADD_TEST(tc_core, test_calculate_7);
  ADD_TEST(tc_core, test_calculate_8);
  ADD_TEST(tc_core, test_calculate_9);
  ADD_TEST(tc_core, test_calculate_10);
  ADD_TEST(tc_core, test_calculate_11);
  ADD_TEST(tc_core, test_calculate_12);
  ADD_TEST(tc_core, test_calculate_13);
  ADD_TEST(tc_core, test_calculate_14);
  ADD_TEST(tc_core, test_calculate_15);
  ADD_TEST(tc_core, test_calculate_16);
  ADD_TEST(tc_core, test_calculate_17);
  ADD_TEST(tc_core, test_calculate_18);
  ADD_TEST(tc_core, test_calculate_19);
  ADD_TEST(tc_core, test_calculate_20);
  ADD_TEST(tc_core, test_calculate_21);

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
