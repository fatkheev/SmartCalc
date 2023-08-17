#include "../calc.h"

// Проверка, является ли символ оператором
bool is_operator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

// Проверка на наличие функции в строке
bool has_function(const char* str, const char* func) {
  return strstr(str, func) != NULL;
}

// Валидация входной строки
bool validate_string(char* str) {
  int open_parentheses = 0;
  int close_parentheses = 0;

  // Создаем копию входной строки для внесения корректировок
  char* corrected_str = malloc(
      strlen(str) + 2);  // +2: один для потенциального '0' и один для '\0'
  int corrected_index = 0;

  for (int i = 0; str[i]; i++) {
    // Корректировка чисел с плавающей точкой
    if (str[i] == '.' && (i == 0 || !isdigit(str[i - 1]))) {
      corrected_str[corrected_index++] = '0';
    }

    corrected_str[corrected_index++] = str[i];

    // Проверяем, является ли символ числом, оператором или буквой (для функций)
    if (!isdigit(str[i]) && !is_operator(str[i]) && !isalpha(str[i]) &&
        str[i] != '.' && str[i] != ' ') {
      free(corrected_str);
      return false;
    }

    // Проверка на два оператора подряд
    if (is_operator(str[i]) && i > 0 && is_operator(str[i - 1]) &&
        !(str[i - 1] == '(' && (str[i] == '-' || str[i] == '+'))) {
      free(corrected_str);
      return false;  // Два оператора подряд, кроме унарного минуса или плюса
                     // после открывающей скобки
    }

    // Подсчет скобок
    if (str[i] == '(') open_parentheses++;
    if (str[i] == ')') close_parentheses++;
  }

  corrected_str[corrected_index] = '\0';  // завершающий символ для новой строки

  // Проверка на равное количество открывающих и закрывающих скобок
  if (open_parentheses != close_parentheses) {
    free(corrected_str);
    return false;
  }

  // Проверка на корректность функций
  if (has_function(corrected_str, "sin") ||
      has_function(corrected_str, "cos")) {
    // Здесь можно добавить дополнительные проверки для функций
  }

  // Проверка, чтобы строка не заканчивалась на оператор
  int len = strlen(corrected_str);
  if (is_operator(corrected_str[len - 1]) && corrected_str[len - 1] != ')') {
    free(corrected_str);
    return false;
  }

  free(corrected_str);
  return true;
}

// Разделение строки на токены
char** parse_string(const char* str, int* size) {
    char** tokens = malloc(sizeof(char*) * (strlen(str) + 1));
    char* token = malloc(sizeof(char) * (strlen(str) + 1));
    int token_index = 0, tokens_count = 0;

    for (int i = 0; str[i]; i++) {
        if (is_operator(str[i]) || str[i] == ' ') {
            if (token_index > 0) {
                token[token_index] = '\0';

                // Проверка на унарный минус
                if (strcmp(token, "-") == 0 && tokens_count > 0 && 
                    (strcmp(tokens[tokens_count-1], "(") == 0 || is_operator(tokens[tokens_count-1][0]))) {
                    tokens[tokens_count] = strdup("0");
                    tokens_count++;
                }

                tokens[tokens_count] = strdup(token);
                tokens_count++;
                token_index = 0;
            }
            
            // Если это оператор (и не пробел), добавляем его как отдельный токен
            if (is_operator(str[i])) {
                tokens[tokens_count] = malloc(2);
                tokens[tokens_count][0] = str[i];
                tokens[tokens_count][1] = '\0';
                tokens_count++;
            }
        } else if (str[i] == '.' && (i == 0 || !isdigit(str[i-1]))) {
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
        tokens_count++;
    }

    free(token);

    *size = tokens_count;
    return tokens;
}
