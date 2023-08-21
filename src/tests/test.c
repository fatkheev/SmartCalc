#include <check.h>

#include "../calc.h"

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

// Тесты для валидатора
START_TEST(test_validator) {
  ck_assert(validate_string("3 + 5"));
  ck_assert(!validate_string("3 +"));
  ck_assert(validate_string("sin(0.5)"));
  ck_assert(!validate_string("sin(0.5"));
  ck_assert(validate_string(".7 + 3"));
  ck_assert(validate_string("sin(-1-(2+(.3-6)))"));
  ck_assert(!validate_string("sin(4 + )1+8( )"));
}
END_TEST

// Тесты для парсера
START_TEST(test_parser_1) {
  char** tokens = parse_string("3 + 5");
  ck_assert_str_eq(tokens[0], "3");
  ck_assert_str_eq(tokens[1], "+");
  ck_assert_str_eq(tokens[2], "5");

  int i = 0;
  while (tokens[i]) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
END_TEST

START_TEST(test_parser_2) {
  char** tokens = parse_string("1    + .7");
  ck_assert_str_eq(tokens[0], "1");
  ck_assert_str_eq(tokens[1], "+");
  ck_assert_str_eq(tokens[2], "0.7");

  int i = 0;
  while (tokens[i]) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
END_TEST

START_TEST(test_parser_3) {
  char** tokens = parse_string("(-1)");
  ck_assert_str_eq(tokens[0], "(");
  ck_assert_str_eq(tokens[1], "0");
  ck_assert_str_eq(tokens[2], "-");
  ck_assert_str_eq(tokens[3], "1");
  ck_assert_str_eq(tokens[4], ")");

  int i = 0;
  while (tokens[i]) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
END_TEST

START_TEST(test_parser_4) {
  char** tokens = parse_string("sin(-0.5)");
  ck_assert_str_eq(tokens[0], "sin");
  ck_assert_str_eq(tokens[1], "(");
  ck_assert_str_eq(tokens[2], "0");
  ck_assert_str_eq(tokens[3], "-");
  ck_assert_str_eq(tokens[4], "0.5");
  ck_assert_str_eq(tokens[5], ")");

  int i = 0;
  while (tokens[i]) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
END_TEST

START_TEST(test_parser_5) {
  char** tokens = parse_string("sin((-1)-(2+(.3-6)))");
  ck_assert_str_eq(tokens[0], "sin");
  ck_assert_str_eq(tokens[1], "(");
  ck_assert_str_eq(tokens[2], "(");
  ck_assert_str_eq(tokens[3], "0");
  ck_assert_str_eq(tokens[4], "-");
  ck_assert_str_eq(tokens[5], "1");
  ck_assert_str_eq(tokens[6], ")");
  ck_assert_str_eq(tokens[7], "-");
  ck_assert_str_eq(tokens[8], "(");
  ck_assert_str_eq(tokens[9], "2");
  ck_assert_str_eq(tokens[10], "+");
  ck_assert_str_eq(tokens[11], "(");
  ck_assert_str_eq(tokens[12], "0.3");
  ck_assert_str_eq(tokens[13], "-");
  ck_assert_str_eq(tokens[14], "6");
  ck_assert_str_eq(tokens[15], ")");
  ck_assert_str_eq(tokens[16], ")");
  ck_assert_str_eq(tokens[17], ")");

  int i = 0;
  while (tokens[i]) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
END_TEST

START_TEST(test_parser_6) {
  char** tokens = parse_string("sin(-3+(-.5))");

  ck_assert_str_eq(tokens[0], "sin");
  ck_assert_str_eq(tokens[1], "(");
  ck_assert_str_eq(tokens[2], "(");
  ck_assert_str_eq(tokens[3], "0");
  ck_assert_str_eq(tokens[4], "-");
  ck_assert_str_eq(tokens[5], "3");
  ck_assert_str_eq(tokens[6], ")");
  ck_assert_str_eq(tokens[7], "+");
  ck_assert_str_eq(tokens[8], "(");
  ck_assert_str_eq(tokens[9], "0");
  ck_assert_str_eq(tokens[10], "-");
  ck_assert_str_eq(tokens[11], "0.5");
  ck_assert_str_eq(tokens[12], ")");
  ck_assert_str_eq(tokens[13], ")");

  int i = 0;
  while (tokens[i]) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
END_TEST

START_TEST(test_parser_7) {
  char** tokens = parse_string("tan(-1+5)");
  ck_assert_str_eq(tokens[0], "tan");
  ck_assert_str_eq(tokens[1], "(");
  ck_assert_str_eq(tokens[2], "(");
  ck_assert_str_eq(tokens[3], "0");
  ck_assert_str_eq(tokens[4], "-");
  ck_assert_str_eq(tokens[5], "1");
  ck_assert_str_eq(tokens[6], ")");
  ck_assert_str_eq(tokens[7], "+");
  ck_assert_str_eq(tokens[8], "5");
  ck_assert_str_eq(tokens[9], ")");

  int i = 0;
  while (tokens[i]) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
END_TEST

START_TEST(test_parser_8) {
  char** tokens = parse_string("sin(1    + -.7)");
  ck_assert_str_eq(tokens[0], "sin");
  ck_assert_str_eq(tokens[1], "(");
  ck_assert_str_eq(tokens[2], "1");
  ck_assert_str_eq(tokens[3], "+");
  ck_assert_str_eq(tokens[4], "(");
  ck_assert_str_eq(tokens[5], "0");
  ck_assert_str_eq(tokens[6], "-");
  ck_assert_str_eq(tokens[7], "0.7");
  ck_assert_str_eq(tokens[8], ")");
  ck_assert_str_eq(tokens[9], ")");

  int i = 0;
  while (tokens[i]) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
END_TEST

// Тесты для стека:
START_TEST(test_stack_push_pop) {
  Stack* stack = createStack(10);

  char* item1 = "5";
  char* item2 = "+";
  char* item3 = "10";

  push(stack, item1);
  push(stack, item2);
  push(stack, item3);

  ck_assert_str_eq(pop(stack), item3);
  ck_assert_str_eq(pop(stack), item2);
  ck_assert_str_eq(pop(stack), item1);

  freeStack(stack);
}
END_TEST

START_TEST(test_stack_peek) {
  Stack* stack = createStack(10);

  char* item = "7";

  push(stack, item);

  ck_assert_str_eq(peek(stack), item);
  ck_assert_str_eq(peek(stack), item);  // Убедимся, что peek не удаляет элемент

  freeStack(stack);
}
END_TEST

START_TEST(test_stack_overflow) {
  Stack* stack = createStack(2);

  char* item1 = "1";
  char* item2 = "+";
  char* item3 = "2";

  push(stack, item1);
  push(stack, item2);

  ck_assert_int_eq(isFull(stack), 1);
  ck_assert_int_eq(push(stack, item3),
                   -1);  // Ожидаем ошибку, так как стек полон

  freeStack(stack);
}
END_TEST

Suite* calculator_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("Calculator");

  tc_core = tcase_create("Core");

  // Тесты для валидатора
  ADD_TEST(tc_core, test_validator);

  // Тесты для парсера
  ADD_TEST(tc_core, test_parser_1);
  ADD_TEST(tc_core, test_parser_2);
  ADD_TEST(tc_core, test_parser_3);
  ADD_TEST(tc_core, test_parser_4);
  ADD_TEST(tc_core, test_parser_5);
  ADD_TEST(tc_core, test_parser_6);
  ADD_TEST(tc_core, test_parser_7);
  ADD_TEST(tc_core, test_parser_8);

  // Тесты для стека
  ADD_TEST(tc_core, test_stack_push_pop);
  ADD_TEST(tc_core, test_stack_peek);
  ADD_TEST(tc_core, test_stack_overflow);

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
