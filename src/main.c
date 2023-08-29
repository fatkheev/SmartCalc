#include "stack.h"

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