#include "../calc.h"

char** parse_string(const char* str) {
  // Проверка валидности входной строки
  if (!validate_string(str)) {
    return NULL;
  }

  // Выделение памяти для массива строк (токенов)
  char** tokens = (char**)malloc(sizeof(char*) * (2 * strlen(str) + 1));
  memset(tokens, 0, sizeof(char*) * (2 * strlen(str) + 1));

  // Выделение памяти для отдельного токена
  char* token = (char*)malloc(sizeof(char) * (strlen(str) + 1));
  memset(token, 0, sizeof(char) * (strlen(str) + 1));
  int token_index = 0, tokens_count = 0;

  // Проход по каждому символу исходной строки
  for (int i = 0; str[i]; i++) {
    // Поиск предыдущего не-пробельного символа
    int prev_non_space_index = i - 1;
    while (prev_non_space_index >= 0 && str[prev_non_space_index] == ' ') {
      prev_non_space_index--;
    }

    // Обработка отрицательных чисел
    if (str[i] == '-' &&
        (i == 0 || prev_non_space_index < 0 ||
         is_operator(str[prev_non_space_index]) ||
         str[prev_non_space_index] == '(') &&
        (isdigit(str[i + 1]) || str[i + 1] == '.')) {
      int j = i + 1;
      while (str[j] && (isdigit(str[j]) || str[j] == '.')) {
        j++;
      }
      bool isAlreadyInParentheses =
          (str[prev_non_space_index] == '(' && str[j] == ')');

      // Если число не заключено в скобки, добавляем скобки вокруг него
      if (!isAlreadyInParentheses) {
        tokens[tokens_count++] = strdup("(");
        tokens[tokens_count++] = strdup("0");
        tokens[tokens_count++] = strdup("-");
      } else {
        tokens[tokens_count++] = strdup("0");
        tokens[tokens_count++] = strdup("-");
      }

      // Пропускаем пробелы и добавляем 0 перед точкой, если необходимо
      i++;
      while (str[i] == ' ') {
        i++;
      }
      if (str[i] == '.') {
        token[token_index++] = '0';
      }
      // Считываем число
      while (str[i] && !is_operator(str[i]) && str[i] != ')' && str[i] != '(') {
        token[token_index++] = str[i];
        i++;
      }

      // Если число заканчивается на точку, добавляем '0'
      if (token[token_index - 1] == '.') {
        token[token_index++] = '0';
      }

      // Добавляем считанное число в массив токенов
      if (token_index > 0) {
        token[token_index] = '\0';
        tokens[tokens_count] = strdup(token);
        tokens_count++;
        token_index = 0;
      }

      if (!isAlreadyInParentheses) {
        tokens[tokens_count++] = strdup(")");
      }
      if (str[i]) {
        i--;
      }
      continue;
    }

    // Обработка операторов, скобок и пробелов
    if (is_operator(str[i]) || str[i] == ' ' || str[i] == '(' ||
        str[i] == ')') {
      if (token_index > 0) {
        token[token_index] = '\0';
        tokens[tokens_count] = strdup(token);
        tokens_count++;
        token_index = 0;
      }
      if (is_operator(str[i]) || str[i] == '(' || str[i] == ')') {
        tokens[tokens_count] = (char*)malloc(2);
        tokens[tokens_count][0] = str[i];
        tokens[tokens_count][1] = '\0';
        tokens_count++;
      }
    }

    // Обработка точек
    else if (str[i] == '.') {
      // Если точка стоит в начале строки или после нецифрового символа
      if (i == 0 || !isdigit(str[i - 1])) {
        token[token_index++] = '0';
      }
      token[token_index++] = '.';
      // Если после точки не следует число, добавляем '0'
      if (!isdigit(str[i + 1])) {
        token[token_index++] = '0';
      }
    }

    // Обработка букв (функций)
    else if (isalpha(str[i])) {
      int start = i;
      while (isalpha(str[i])) i++;
      int len = i - start;
      tokens[tokens_count] = strndup(str + start, len);
      tokens_count++;
      i--;
    }
    // Добавление символа в текущий токен
    else {
      token[token_index] = str[i];
      token_index++;
    }
  }

  // Добавление последнего токена в массив, если он не пустой
  if (token_index > 0) {
    token[token_index] = '\0';
    tokens[tokens_count] = strdup(token);
  }

  // Освобождение памяти от временной строки и возвращение результата
  free(token);
  return tokens;
}