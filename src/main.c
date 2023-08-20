#include "calc.h"

int main() {
  char input[] = "sin(1    + -.7)";
  char** tokens = parse_string(input);
  printf("Обрабатываемая строка: %s\n", input);
  if (tokens) {
    printf("Токены:\n\n");

    int i = 0;
    int token_count = 0;

    // // Для тестов:
    // printf("char** tokens = parse_string(\"%s\");\n\n", input);
    // while (tokens[i]) {
    //   printf("ck_assert_str_eq(tokens[%d], \"%s\");\n", i, tokens[i]);
    //   free(tokens[i]);
    //   i++;
    //   token_count++;
    // }

    // Для проверки в реальном времени:
    while (tokens[i]) {
      printf("%s\n", tokens[i]);
      free(tokens[i]);
      i++;
      token_count++;
    }

    printf("\n\nКоличество символов во входной строке: %d\n", (int)strlen(input));
    printf("Количество элементов в массиве: %d\n", token_count);

    free(tokens);
  } else {
    printf("Строка не прошла валидацию.\n");
  }

  return 0;
}