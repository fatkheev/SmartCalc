#include "calc.h"

int main() {
  char input[] = ")1+8(";
  char** tokens = parse_string(input);
  printf("Обрабатываемая строка: %s\n", input);
  if (tokens) {
    printf("Токены:\n");

    int i = 0;
    int token_count = 0;
    printf("char** tokens = parse_string(\"%s\");\n\n", input);
    while (tokens[i]) {
      printf("ck_assert_str_eq(tokens[%d], \"%s\");\n", i, tokens[i]);
      free(tokens[i]);
      i++;
      token_count++;
    }
    printf("\nКоличество символов во входной строке: %d\n", (int)strlen(input));
    printf("Количество элементов в массиве: %d\n", token_count);

    free(tokens);
  } else {
    printf("Строка не прошла валидацию.\n");
  }

  return 0;
}