#include "../stack.h"

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