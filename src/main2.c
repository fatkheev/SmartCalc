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
void MathFunction(char* ch, char* operators, int* top, size_t* i,
                  const char* expression);
// Обработка оператора mod
void ModOperator(char* operators, int* top, size_t* i, char* output, int* k);
// Обработка десятичных чисел
void DecimalNumbers(const char* expression, size_t* i, char* output, int* k);
// Обработка целых чисел
void CeilNumbers(const char* expression, size_t* i, char* output, int* k);
// Обработка закрытой скобки
void ClosingParenthesis(char* operators, int* top, char* output, int* k);
// Обработка операторов с приоритетами
void OperatorsPriority(char ch, char* operators, int* top, char* output,
                       int* k);
// Арифметические действия
void ArithmeticOperations(char ch, double* values, int* top);
// Стандартная обработка цифр в постфиксном выражении
void StandartValueOperations(const char* postfix, size_t* i, double* values,
                             int* top);
// Обработка функций
void MathFunctions(char ch, double* values, int* top);

// Вспомогательные функции валидатора:

// Проверка ввода функций
bool validate_functions_in_string(const char* str);
// Часть функции validate_string для рефакторинга
bool isInvalidChar(const char* str, int i, int dot_count);


// Проверяем, является ли символ оператором.
int isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' ||
          c == '%' || c == 'm' || c == 'U');
}

// Проверяем, является ли символ математической функцией.
int isFunction(char c) {
  return (c == 'C' || c == 'S' || c == 'T' || c == 'A' || c == 'B' ||
          c == 'N' || c == 'R' || c == 'L' || c == 'G');
}

// Проверяем, является ли символ унарным оператором.
int isUnaryOperator(char c) { return (c == 'U'); }

// Возвращает приоритет оператора.
int priority(char c) {
  int prio = -1;

  if (c == 'U') {
    prio = 5;
  } else if (c == '^') {
    prio = 4;
  } else if (c == '*' || c == '/' || c == '%' || c == 'm') {
    prio = 3;
  } else if (c == '+' || c == '-') {
    prio = 2;
  } else if (c == 'C' || c == 'S' || c == 'T' || c == 'A' || c == 'B' ||
             c == 'N' || c == 'R' || c == 'L' || c == 'G') {
    prio = 1;
  }

  return prio;
}

// Возвращает символьное представление математической функции.
char getFunctionChar(const char* str) {
  char functionChar = '\0';

  if (strncmp(str, "cos", 3) == 0) {
    functionChar = 'C';
  } else if (strncmp(str, "sin", 3) == 0) {
    functionChar = 'S';
  } else if (strncmp(str, "tan", 3) == 0) {
    functionChar = 'T';
  } else if (strncmp(str, "acos", 4) == 0) {
    functionChar = 'A';
  } else if (strncmp(str, "asin", 4) == 0) {
    functionChar = 'B';
  } else if (strncmp(str, "atan", 4) == 0) {
    functionChar = 'N';
  } else if (strncmp(str, "sqrt", 4) == 0) {
    functionChar = 'R';
  } else if (strncmp(str, "ln", 2) == 0) {
    functionChar = 'L';
  } else if (strncmp(str, "log", 3) == 0) {
    functionChar = 'G';
  }

  return functionChar;
}

void converter(
    const char* expression,
    char* output) {  // Конвертирует инфиксное выражение в постфиксное.
  if (!validate_string(expression)) {
    printf("Error\n");
    *output = '\0';
    return;
  }
  char operators[strlen(expression) + 1];
  int top = -1;
  int k = 0;

  for (size_t i = 0; i < strlen(expression);
       i++) {  // Обходим каждый символ в выражении.
    char ch = expression[i];

    ch = UnaryMinus(ch, i, expression);  // Обработка унарного минуса.

    if (UnaryPlus(ch, i, expression)) {  // Пропускаем унарный плюс.
      continue;
    }
    if (isFunction(getFunctionChar(expression +
                                   i))) {  // Обработка математических функций.
      MathFunction(&ch, operators, &top, &i, expression);
    } else if (ch == 'm' &&
               i + 2 < strlen(expression) &&  // Обработка оператора mod.
               strncmp(expression + i, "mod", 3) == 0) {
      ModOperator(operators, &top, &i, output, &k);
    } else if (ch == '.') {  // Обработка десятичных чисел.
      DecimalNumbers(expression, &i, output, &k);
    } else if (isdigit(ch)) {  // Обработка целых чисел.
      CeilNumbers(expression, &i, output, &k);
    } else if (ch == '(') {  // Обработка открывающей скобки.
      operators[++top] = ch;
    } else if (ch == ')') {  // Обработка закрывающей скобки.
      ClosingParenthesis(operators, &top, output, &k);
    } else if (isOperator(ch)) {  // Обработка операторов.
      OperatorsPriority(ch, operators, &top, output, &k);
    }
  }

  while (top != -1) {  // Добавляем оставшиеся операторы в выходную строку.
    output[k++] = operators[top--];
    output[k++] = ' ';
  }
  output[k] = '\0';
}

// Вычисляет результат постфиксного выражения.
double calculate(const char* infixExpression) {
  if (!validate_string(infixExpression)) {
    printf("Error\n");
    return 0.0;
  }
  char postfix[strlen(infixExpression) * 2];
  converter(infixExpression, postfix);

  double values[strlen(postfix)];
  int top = -1;

  for (size_t i = 0; i < strlen(postfix); i++) {
    char ch = postfix[i];

    if (ch == 'm') {
      double value2 = values[top--];
      double value1 = values[top--];
      values[++top] = fmod(value1, value2);
    } else if (isUnaryOperator(ch)) {
      double value = values[top];
      values[top] = -value;
    } else if (isdigit(ch) || (ch == '-' && isdigit(postfix[i + 1]))) {
      StandartValueOperations(
          postfix, &i, values,
          &top);  // Стандартная обработка цифр в постфиксном выражении
    } else if (isOperator(ch)) {  // Арифметические действия.
      ArithmeticOperations(ch, values, &top);
    } else if (isFunction(ch)) {  // Обработка функций.
      MathFunctions(ch, values, &top);
    }
  }

  return values[0];
}

// Вспомогательные функции:

// Обработка унарного минуса
char UnaryMinus(char ch, size_t i, const char* expression) {
  char result = ch;
  if (ch == '-') {
    int condition =
        (i == 0 || expression[i - 1] == '(' || isOperator(expression[i - 1]));
    if (condition) {
      result = 'U';
    }
  }
  return result;
}

// Обработка унарного плюса
int UnaryPlus(char ch, size_t i, const char* expression) {
  int skip = 0;  // Не пропускаем символ по умолчанию
  if (ch == '+') {
    int condition =
        (i == 0 || expression[i - 1] == '(' || isOperator(expression[i - 1]));
    if (condition) {
      skip = 1;  // Пропускаем символ
    }
  }
  return skip;
}

// Обработка математических функций
void MathFunction(char* ch, char* operators, int* top, size_t* i,
                  const char* expression) {
  char functionChar = getFunctionChar(expression + *i);
  if (isFunction(functionChar)) {
    *ch = functionChar;
    operators[++(*top)] = *ch;
    while (*i < strlen(expression) && !isdigit(expression[*i]) &&
           expression[*i] != '(') {
      (*i)++;
    }
    (*i)--;
  }
}

// Обработка оператора mod
void ModOperator(char* operators, int* top, size_t* i, char* output, int* k) {
  while (*top != -1 && priority(operators[*top]) >= priority('m')) {
    output[(*k)++] = operators[(*top)--];
    output[(*k)++] = ' ';
  }
  operators[++(*top)] = 'm';
  *i += 2;
}

// Обработка десятичных чисел
void DecimalNumbers(const char* expression, size_t* i, char* output, int* k) {
  if (*i == 0 || !isdigit(expression[*i - 1])) {
    output[(*k)++] = '0';
  }
  output[(*k)++] = '.';

  (*i)++;

  if (*i == strlen(expression) || !isdigit(expression[*i])) {
    output[(*k)++] = '0';
    output[(*k)++] = ' ';
  } else {
    while (*i < strlen(expression) && isdigit(expression[*i])) {
      output[(*k)++] = expression[(*i)++];
    }
    (*i)--;
    output[(*k)++] = ' ';
  }
}

// Обработка целых чисел
void CeilNumbers(const char* expression, size_t* i, char* output, int* k) {
  while (*i < strlen(expression) &&
         (isdigit(expression[*i]) || expression[*i] == '.')) {
    output[(*k)++] = expression[(*i)++];
  }
  (*i)--;
  output[(*k)++] = ' ';
}

// Обработка закрытой скобки
void ClosingParenthesis(char* operators, int* top, char* output, int* k) {
  while (*top != -1 && operators[*top] != '(') {
    output[(*k)++] = operators[(*top)--];
    output[(*k)++] = ' ';
  }

  // Если функция находится перед открывающей скобкой, добавляем её в выходную
  // строку.
  if (*top > 0 && isFunction(operators[*top - 1])) {
    (*k)--;
    output[(*k)++] = operators[--(*top)];
    output[(*k)++] = ' ';
  }

  (*top)--;
}

// Обработка операторов с приоритетами
void OperatorsPriority(char ch, char* operators, int* top, char* output,
                       int* k) {
  while (*top != -1 && priority(operators[*top]) >= priority(ch)) {
    output[(*k)++] = operators[(*top)--];
    output[(*k)++] = ' ';
  }
  operators[++(*top)] = ch;
}

// Арифметические действия
void ArithmeticOperations(char ch, double* values, int* top) {
  double value2 = values[(*top)--];
  double value1 = values[(*top)--];

  if (ch == '+') {
    values[++(*top)] = value1 + value2;
  } else if (ch == '-') {
    values[++(*top)] = value1 - value2;
  } else if (ch == '*') {
    values[++(*top)] = value1 * value2;
  } else if (ch == '/') {
    values[++(*top)] = value1 / value2;
  } else if (ch == '^') {
    values[++(*top)] = pow(value1, value2);
  } else if (ch == 'm' || ch == '%') {
    values[++(*top)] = fmod(value1, value2);
  }
}

// Стандартная обработка цифр в постфиксном выражении
void StandartValueOperations(const char* postfix, size_t* i, double* values,
                             int* top) {
  double value = 0;
  double factor = 1.0;
  bool isDecimal = false;

  while ((*i) < strlen(postfix) &&
         (isdigit(postfix[*i]) || postfix[*i] == '.')) {
    if (postfix[*i] == '.') {
      isDecimal = true;
    } else {
      value = value * 10 + (postfix[*i] - '0');
      if (isDecimal) {
        factor *= 10.0;
      }
    }
    (*i)++;
  }

  (*i)--;
  values[++(*top)] = value / factor;
}

// Обработка функций
void MathFunctions(char ch, double* values, int* top) {
  double value = values[(*top)--];

  if (ch == 'C') {
    values[++(*top)] = cos(value);
  } else if (ch == 'S') {
    values[++(*top)] = sin(value);
  } else if (ch == 'T') {
    values[++(*top)] = tan(value);
  } else if (ch == 'A') {
    // Не забудьте добавить проверку диапазона!
    values[++(*top)] = acos(value);
  } else if (ch == 'B') {
    // Не забудьте добавить проверку диапазона!
    values[++(*top)] = asin(value);
  } else if (ch == 'N') {
    values[++(*top)] = atan(value);
  } else if (ch == 'R') {
    // Не забудьте добавить проверку на отрицательные числа!
    values[++(*top)] = sqrt(value);
  } else if (ch == 'L') {
    // Не забудьте добавить проверку на отрицательные числа и ноль!
    values[++(*top)] = log(value);
  } else if (ch == 'G') {
    // Не забудьте добавить проверку на отрицательные числа и ноль!
    values[++(*top)] = log10(value);
  }
}



bool validate_string(const char* str) {
  int open_parentheses = 0;
  int close_parentheses = 0;
  int dot_count = 0;
  bool is_valid = true;

  if (str[0] == ')') {
    is_valid = false;
  }

  for (int i = 0; is_valid && str[i]; i++) {
    if (str[i] == ' ' || isOperator(str[i])) {
      dot_count = 0;
    }

    if (isInvalidChar(str, i, dot_count)) {
      is_valid = false;
    }

    int j = i + 1;
    while (is_valid && str[j] != ')') {  // ищет скобку
      j++;
    }

    int k = j - 1;
    while (str[k] == ' ' &&
           k > i) {  // потом двигается назад, схлопывая пробелы
      k--;
    }

    if (isOperator(
            str[k])) {  // потом проверяет, есть ли перед скобкой оператор
      is_valid = false;
    }
  }

  if (open_parentheses != close_parentheses ||
      !validate_functions_in_string(str) || isOperator(str[strlen(str) - 1])) {
    is_valid = false;
  }

  return is_valid;
}

bool has_function(const char* str, const char* func) {
  return strstr(str, func) != NULL;
}

// Часть функции validate_string для рефакторинга
bool isInvalidChar(const char* str, int i, int dot_count) {
  bool result = false;

  if (dot_count > 1 ||
      ((str[i] == '/' || str[i] == '*' || str[i] == '^' || str[i] == 'm' ||
        str[i] == '%') &&
       (i == 0 || str[i - 1] == '(')) ||
      (!isdigit(str[i]) && !isOperator(str[i]) && !isalpha(str[i]) &&
       str[i] != '.' && str[i] != ' ' && str[i] != '(' && str[i] != ')')) {
    result = true;
  } else if (isdigit(str[i]) && i > 0 && str[i - 1] == ' ') {
    int j = i - 2;
    while (j >= 0 && str[j] == ' ') j--;
    if (j >= 0 && isdigit(str[j])) {
      result = true;
    }
  } else if (isOperator(str[i])) {
    int j = i - 1;
    while (j >= 0 && str[j] == ' ') j--;
    if (j >= 0 && isOperator(str[j]) &&
        !((str[j] == '/' && str[i] == '-') ||
          (str[j] == '*' && str[i] == '-') ||
          (str[j] == '*' && str[i] == '+'))) {
      result = true;
    }
  } else if (str[i] == '.') {
    if (i == 0 || !isdigit(str[i - 1])) {
      int j = i + 1;
      if (!isdigit(str[j])) {
        result = true;
      }
    }
  }

  return result;
}

// Проверка ввода функций
bool validate_functions_in_string(const char* str) {
  const char* functions[] = {"sin",  "cos",  "tan", "asin", "acos",
                             "atan", "sqrt", "ln",  "log",  "mod"};
  int num_functions = sizeof(functions) / sizeof(functions[0]);

  bool is_all_valid = true;

  for (int i = 0; is_all_valid && str[i]; i++) {
    if (isalpha(str[i])) {
      bool is_valid = false;

      for (int j = 0; !is_valid && j < num_functions; j++) {
        if (strncmp(str + i, functions[j], strlen(functions[j])) == 0) {
          if (strcmp(functions[j], "mod") == 0) {
            int k = i - 1;
            while (k >= 0 && str[k] == ' ') k--;
            bool is_previous_digit = k >= 0 && isdigit(str[k]);

            k = i + 3;
            while (str[k] && str[k] == ' ') k++;
            bool is_next_digit = isdigit(str[k]);

            if (!is_previous_digit || !is_next_digit) {
              is_all_valid = false;
            }

            i += 2;
            is_valid = true;
          } else if (str[i + strlen(functions[j])] != '(') {
            is_all_valid = false;
          } else {
            i += strlen(functions[j]) - 1;
            is_valid = true;
          }
        }
      }

      if (!is_valid) {
        is_all_valid = false;
      }
    }
  }

  return is_all_valid;
}


int main() {
  char expression[100];
  char postfix[100];

  printf("Введите инфиксное выражение: ");
  fgets(expression, sizeof(expression), stdin);
  expression[strcspn(expression, "\n")] = 0;

  converter(expression, postfix);
  printf("Обратная польская запись: %s\n", postfix);

  double result = calculate(expression);
  printf("Результат вычисления: %lf\n", result);

  return 0;
}