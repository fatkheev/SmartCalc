#include "../calc.h"

char** parse_string(const char* str) {
  if (!validate_string(str)) {
    return NULL;
  }

  char** tokens = (char**)malloc(sizeof(char*) * (2 * strlen(str) + 1));
  memset(tokens, 0, sizeof(char*) * (2 * strlen(str) + 1));

  char* token = (char*)malloc(sizeof(char) * (strlen(str) + 1));
  memset(token, 0, sizeof(char) * (strlen(str) + 1));
  int token_index = 0, tokens_count = 0;

  for (int i = 0; str[i]; i++) {
    if (str[i] == '-' &&
        (i == 0 || str[i - 1] == ' ' || is_operator(str[i - 1]) ||
         str[i - 1] == '(') &&
        (isdigit(str[i + 1]) || str[i + 1] == '.')) {
      // Проверяем, заключено ли выражение в скобки
      int j = i + 1;
      while (str[j] && (isdigit(str[j]) || str[j] == '.')) {
        j++;
      }
      bool isAlreadyInParentheses = (str[i - 1] == '(' && str[j] == ')');

      if (!isAlreadyInParentheses) {
        tokens[tokens_count++] = strdup("(");
        tokens[tokens_count++] = strdup("0");
        tokens[tokens_count++] = strdup("-");
      } else {
        tokens[tokens_count++] = strdup("0");
        tokens[tokens_count++] = strdup("-");
      }

      i++;  // Переходим к следующему символу
      while (str[i] == ' ') {
        i++;  // Пропускаем пробелы
      }
      if (str[i] ==
          '.') {  // Если следующий символ - точка, добавляем 0 перед ней
        token[token_index++] = '0';
      }
      while (str[i] && !is_operator(str[i]) && str[i] != ')' && str[i] != '(') {
        token[token_index++] = str[i];
        i++;
      }
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
        i--;  // Возвращаемся к текущему символу для дальнейшей обработки
      }
      continue;
    }

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
    } else if (str[i] == '.' && (i == 0 || !isdigit(str[i - 1]))) {
      token[token_index++] = '0';
      token[token_index++] = '.';
    } else if (isalpha(str[i])) {
      int start = i;
      while (isalpha(str[i])) i++;
      int len = i - start;
      tokens[tokens_count] = strndup(str + start, len);
      tokens_count++;
      i--;
    } else {
      token[token_index] = str[i];
      token_index++;
    }
  }

  if (token_index > 0) {
    token[token_index] = '\0';
    tokens[tokens_count] = strdup(token);
  }

  free(token);
  return tokens;
}

bool validate_string(const char* str) {
  int open_parentheses = 0;
  int close_parentheses = 0;

  char* corrected_str = (char*)calloc(strlen(str) * 2 + 2, sizeof(char));
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

  const char* functions[] = {"sin", "cos", "tan"};
  int num_functions = sizeof(functions) / sizeof(functions[0]);

  for (int i = 0; corrected_str[i]; i++) {
    if (isalpha(corrected_str[i])) {
      bool is_valid = false;
      for (int j = 0; j < num_functions; j++) {
        if (strncmp(corrected_str + i, functions[j], strlen(functions[j])) ==
            0) {
          // Проверяем, следует ли за именем функции открывающая скобка
          if (corrected_str[i + strlen(functions[j])] != '(') {
            free(corrected_str);
            return false;
          }
          is_valid = true;
          i += strlen(functions[j]) - 1;  // Продолжаем после имени функции
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
