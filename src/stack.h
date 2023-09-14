#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isOperator(char c);
int priority(char c);
void converter(const char* expression, char* output);
double calculate(const char* postfix);
bool validate_string(const char* str);

// Вспомогательные функции:

// Обработка унарного минуса
char UnaryMinus(char ch, size_t i, const char* expression);
// Обработка унарного плюса
int UnaryPlus(char ch, size_t i, const char* expression);
// Обработка математических функций
void MathFunction(char* ch, char* operators, int* top, size_t* i, const char* expression);
// Обработка оператора mod
void ModOperator(char* operators, int* top, size_t* i, char* output, int* k);
// Обработка десятичных чисел
void DecimalNumbers(const char* expression, size_t* i, char* output, int* k);
// Обработка целых чисел
void CeilNumbers(const char* expression, size_t* i, char* output, int* k);
// Обработка закрытой скобки
void ClosingParenthesis(char* operators, int* top, char* output, int* k);
// Обработка операторов с приоритетами
void OperatorsPriority(char ch, char* operators, int* top, char* output, int* k);
// Арифметические действия
void ArithmeticOperations(char ch, double* values, int* top);
// Стандартная обработка цифр в постфиксном выражении
void StandartValueOperations(const char* postfix, size_t* i, double* values, int* top);
// Обработка функций
void MathFunctions(char ch, double* values, int* top);

// Вспомогательные функции валидатора:

// Проверка ввода функций
bool validate_functions_in_string(const char* str);
// Часть функции validate_string для рефакторинга
bool isInvalidChar(const char* str, int i, int dot_count);