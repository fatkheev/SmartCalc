#include "../calc.h"
#include <check.h>

// Глобальные переменные для хранения имен тестов
const char* test_names[100]; // Максимальное количество тестов
int test_count = 0;

// Макрос для добавления теста и сохранения его имени
#define ADD_TEST(tc, test) do { \
    tcase_add_test(tc, test); \
    test_names[test_count++] = #test; \
} while(0)

// ANSI escape коды для цветов текста
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_RESET "\033[0m"

// Тесты для валидатора
START_TEST(test_validator)
{
    ck_assert(validate_string("3 + 5"));
    ck_assert(!validate_string("3 +"));
    ck_assert(validate_string("sin(0.5)"));
    ck_assert(!validate_string("sin(0.5"));
    ck_assert(validate_string(".7 + 3"));
}
END_TEST

// Тесты для парсера
START_TEST(test_parser_1)
{
    int size;

    char** tokens = parse_string("3 + 5", &size);
    ck_assert_int_eq(size, 3);
    ck_assert_str_eq(tokens[0], "3");
    ck_assert_str_eq(tokens[1], "+");
    ck_assert_str_eq(tokens[2], "5");

    for (int i = 0; i < size; i++) {
        free(tokens[i]);
    }
    free(tokens);
}
END_TEST

START_TEST(test_parser_2)
{
    int size;

    char** tokens = parse_string("1    + .7", &size);
    ck_assert_int_eq(size, 3);
    ck_assert_str_eq(tokens[0], "1");
    ck_assert_str_eq(tokens[1], "+");
    ck_assert_str_eq(tokens[2], "0.7");

    for (int i = 0; i < size; i++) {
        free(tokens[i]);
    }
    free(tokens);
}
END_TEST

START_TEST(test_parser_3)
{
    int size;

    char** tokens = parse_string("(-1)", &size);
    ck_assert_int_eq(size, 5);
    ck_assert_str_eq(tokens[0], "(");
	 ck_assert_str_eq(tokens[1], "0");
    ck_assert_str_eq(tokens[2], "-");
    ck_assert_str_eq(tokens[3], "1");
	 ck_assert_str_eq(tokens[4], ")");

    for (int i = 0; i < size; i++) {
        free(tokens[i]);
    }
    free(tokens);
}
END_TEST

START_TEST(test_parser_4)
{
    int size;

    char** tokens = parse_string("sin(-0.5)", &size);
    ck_assert_int_eq(size, 6);
    ck_assert_str_eq(tokens[0], "sin");
	 ck_assert_str_eq(tokens[1], "(");
    ck_assert_str_eq(tokens[2], "0");
    ck_assert_str_eq(tokens[3], "-");
	 ck_assert_str_eq(tokens[4], "0.5");
	 ck_assert_str_eq(tokens[5], ")");

    for (int i = 0; i < size; i++) {
        free(tokens[i]);
    }
    free(tokens);
}
END_TEST

Suite* calculator_suite(void)
{
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
    
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    int total_tests;
    Suite* s;
    SRunner* sr;

    s = calculator_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    total_tests = srunner_ntests_run(sr);

    TestResult **all_results = srunner_results(sr);
    
    printf("\n------------------------------------\n");
    for (int i = 0; i < total_tests; i++) {
        const char *test_name = test_names[i];
        if (tr_rtype(all_results[i]) == CK_PASS) {
            printf("Тест %s - " COLOR_GREEN "Пройден" COLOR_RESET "\n", test_name);
        } else {
            printf("Тест %s - " COLOR_RED "Провален" COLOR_RESET "\n", test_name);
        }
    }

    printf("------------------------------------\n");
    printf("Всего тестов: %d\n", total_tests);
    printf("Провалено тестов: %d\n", number_failed);
    printf("------------------------------------\n");

    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
