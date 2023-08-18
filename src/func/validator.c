#include "../calc.h"

char** parse_string(const char* str) {
  // Проверка валидации на начальном этапе
  if (!validate_string(str)) {
    return NULL;
  }

  char** tokens = malloc(sizeof(char*) * (2 * strlen(str) + 1));
  memset(tokens, 0, sizeof(char*) * (2 * strlen(str) + 1));

  char* token = malloc(sizeof(char) * (strlen(str) + 1));
  memset(token, 0, sizeof(char) * (strlen(str) + 1));
  int token_index = 0, tokens_count = 0;

  for (int i = 0; str[i]; i++) {
    // Проверка на унарный минус
    if (str[i] == '-' && (i == 0 || str[i - 1] == ' ' ||
                          is_operator(str[i - 1]) || str[i - 1] == '(')) {
      if (token_index > 0) {
        token[token_index] = '\0';
        tokens[tokens_count] = strdup(token);
        tokens_count++;
        token_index = 0;
      }
      tokens[tokens_count] =
          strdup("0");  // Добавляем '0' перед унарным минусом
      tokens_count++;
    }

    if (is_operator(str[i]) || str[i] == ' ' || str[i] == '(' ||
        str[i] == ')') {
      if (token_index > 0) {
        token[token_index] = '\0';  // Завершение текущего токена
        tokens[tokens_count] = strdup(token);  // Добавление токена в список
        tokens_count++;
        token_index = 0;
      }

      // Если это оператор или скобка (и не пробел), добавляем его как отдельный
      // токен
      if (is_operator(str[i]) || str[i] == '(' || str[i] == ')') {
        tokens[tokens_count] = malloc(2);
        tokens[tokens_count][0] = str[i];
        tokens[tokens_count][1] = '\0';
        tokens_count++;
      }
    } else if (str[i] == '.' && (i == 0 || !isdigit(str[i - 1]))) {
      token[token_index++] = '0';  // Добавление '0' перед точкой
      token[token_index++] = '.';
    } else if (isalpha(str[i])) {
      // Обработка функций
      int start = i;
      while (isalpha(str[i])) i++;
      int len = i - start;
      tokens[tokens_count] = strndup(str + start, len);
      tokens_count++;
      i--;  // Компенсация инкремента цикла
    } else {
      token[token_index] = str[i];
      token_index++;
    }
  }

  // Добавление последнего токена
  if (token_index > 0) {
    token[token_index] = '\0';
    tokens[tokens_count] = strdup(token);
    tokens_count++;
  }

  free(token);
  return tokens;
}

bool validate_string(const char* str) {
  int open_parentheses = 0;
  int close_parentheses = 0;

  char* corrected_str = calloc(strlen(str) * 2 + 2, sizeof(char));
  int corrected_index = 0;

  for (int i = 0; str[i]; i++) {
    if (str[i] == '.' && (i == 0 || !isdigit(str[i - 1]))) {
      corrected_str[corrected_index++] = '0';
    }

    corrected_str[corrected_index++] = str[i];

    if (!isdigit(str[i]) && !is_operator(str[i]) && !isalpha(str[i]) &&
        str[i] != '.' && str[i] != ' ' && str[i] != '(' && str[i] != ')') {
      free(corrected_str);
      return false;
    }

    if (is_operator(str[i]) && i > 0 && is_operator(str[i - 1])) {
      free(corrected_str);
      return false;
    }

    if (str[i] == '(') open_parentheses++;
    if (str[i] == ')') close_parentheses++;

    // После закрывающей скобки не следует непосредственно число или открывающая
    // скобка
    if (corrected_str[i] == '(' && i > 0 &&
        (isdigit(corrected_str[i - 1]) || corrected_str[i - 1] == ')')) {
      free(corrected_str);
      return false;
    }
    // Перед открывающей скобкой не следует число или закрывающая скобка
    if (corrected_str[i] == ')' &&
        (isdigit(corrected_str[i + 1]) || corrected_str[i + 1] == '(')) {
      free(corrected_str);
      return false;
    }
  }

  corrected_str[corrected_index] = '\0';

  if (open_parentheses != close_parentheses) {
    free(corrected_str);
    return false;
  }

  const char* functions[] = {"sin", "cos"};
  int num_functions = sizeof(functions) / sizeof(functions[0]);

  for (int i = 0; corrected_str[i]; i++) {
    if (isalpha(corrected_str[i])) {
      bool is_valid = false;
      for (int j = 0; j < num_functions; j++) {
        if (strncmp(corrected_str + i, functions[j], strlen(functions[j])) ==
            0) {
          is_valid = true;
          i += strlen(functions[j]) - 1;
          break;
        }
      }
      if (!is_valid) {
        free(corrected_str);
        return false;
      }
    }
  }

  int len = strlen(corrected_str);
  if (is_operator(corrected_str[len - 1])) {
    free(corrected_str);
    return false;
  }

  free(corrected_str);
  return true;
}

bool is_operator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool has_function(const char* str, const char* func) {
  return strstr(str, func) != NULL;
}
