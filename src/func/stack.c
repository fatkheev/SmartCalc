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

// Конвертирует инфиксное выражение в постфиксное.
void converter(const char* expression, char* output) {
  if (!validate_string(expression)) {
    printf("Error\n");
    *output = '\0';
    return;
  }
  char operators[strlen(expression) + 1];
  int top = -1;
  int k = 0;

  // Обходим каждый символ в выражении.
  for (size_t i = 0; i < strlen(expression); i++) {
    char ch = expression[i];

    // Обработка унарного минуса.
    if (ch == '-' &&
        (i == 0 || expression[i - 1] == '(' || isOperator(expression[i - 1]))) {
      ch = 'U';
    }

    // Пропускаем унарный плюс.
    if (ch == '+' &&
        (i == 0 || expression[i - 1] == '(' || isOperator(expression[i - 1]))) {
      continue;
    }

    // Обработка математических функций.
    if (isFunction(getFunctionChar(expression + i))) {
      ch = getFunctionChar(expression + i);
      operators[++top] = ch;
      while (i < strlen(expression) && !isdigit(expression[i]) &&
             expression[i] != '(') {
        i++;
      }
      i--;
    }
    // Обработка оператора mod.
    else if (ch == 'm' && i + 2 < strlen(expression) &&
             strncmp(expression + i, "mod", 3) == 0) {
      while (top != -1 && priority(operators[top]) >= priority('m')) {
        output[k++] = operators[top--];
        output[k++] = ' ';
      }
      operators[++top] = 'm';
      i += 2;
    }
    // Обработка десятичных чисел.
    else if (ch == '.') {
      if (i == 0 || !isdigit(expression[i - 1])) {
        output[k++] = '0';
      }
      output[k++] = ch;

      i++;

      if (i == strlen(expression) || !isdigit(expression[i])) {
        output[k++] = '0';
        output[k++] = ' ';
        continue;
      }

      while (i < strlen(expression) && isdigit(expression[i])) {
        output[k++] = expression[i++];
      }
      i--;
      output[k++] = ' ';
    }
    // Обработка целых чисел.
    else if (isdigit(ch)) {
      while (i < strlen(expression) &&
             (isdigit(expression[i]) || expression[i] == '.')) {
        output[k++] = expression[i++];
      }
      i--;
      output[k++] = ' ';
    }
    // Обработка открывающей скобки.
    else if (ch == '(') {
      operators[++top] = ch;
    }
    // Обработка закрывающей скобки.
    else if (ch == ')') {
      while (top != -1 && operators[top] != '(') {
        output[k++] = operators[top--];
        output[k++] = ' ';
      }
      // Если функция находится перед открывающей скобкой, добавляем ее в
      // выходную строку.
      if (top > 0 && isFunction(operators[top - 1])) {
        k--;
        output[k++] = operators[--top];
        output[k++] = ' ';
      }
      top--;
    }
    // Обработка операторов.
    else if (isOperator(ch)) {
      while (top != -1 && priority(operators[top]) >= priority(ch)) {
        output[k++] = operators[top--];
        output[k++] = ' ';
      }
      operators[++top] = ch;
    }
  }

  // Добавляем оставшиеся операторы в выходную строку.
  while (top != -1) {
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
      double value = 0;
      double factor = 1.0;
      bool isDecimal = false;
      while (i < strlen(postfix) &&
             (isdigit(postfix[i]) || postfix[i] == '.')) {
        if (postfix[i] == '.') {
          isDecimal = true;
        } else {
          value = value * 10 + (postfix[i] - '0');
          if (isDecimal) {
            factor *= 10.0;
          }
        }
        i++;
      }
      i--;
      values[++top] = value / factor;
    } else if (isOperator(ch)) {
      double value2 = values[top--];
      double value1 = values[top--];
      // Обработка различных операторов.
      if (ch == '+') {
        values[++top] = value1 + value2;
      } else if (ch == '-') {
        values[++top] = value1 - value2;
      } else if (ch == '*') {
        values[++top] = value1 * value2;
      } else if (ch == '/') {
        values[++top] = value1 / value2;
      } else if (ch == '^') {
        values[++top] = pow(value1, value2);
      } else if (ch == 'm' || ch == '%') {
        values[++top] = fmod(value1, value2);
      }

    } else if (isFunction(ch)) {
      double value = values[top--];
      // Обработка различных функций.
      if (ch == 'C') {
        values[++top] = cos(value);
      } else if (ch == 'S') {
        values[++top] = sin(value);
      } else if (ch == 'T') {
        values[++top] = tan(value);
      } else if (ch == 'A') {
        values[++top] = acos(value);
      } else if (ch == 'B') {
        values[++top] = asin(value);
      } else if (ch == 'N') {
        values[++top] = atan(value);
      } else if (ch == 'R') {
        values[++top] = sqrt(value);
      } else if (ch == 'L') {
        values[++top] = log(value);
      } else if (ch == 'G') {
        values[++top] = log10(value);
      }
    }
  }

  return values[0];
}
