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

bool validate_string(const char* str) {
  // Инициализация счетчиков для открытых и закрытых скобок
  int open_parentheses = 0;
  int close_parentheses = 0;

  // Проверка, чтобы строка не начиналась с закрывающей скобки
  if (str[0] == ')') {
    return false;
  }

  // Проход по каждому символу исходной строки
  for (int i = 0; str[i]; i++) {
    // Проверка символа на допустимость
    if (!isdigit(str[i]) && !is_operator(str[i]) && !isalpha(str[i]) &&
        str[i] != '.' && str[i] != ' ' && str[i] != '(' && str[i] != ')') {
      return false;
    }

    // Проверка на два подряд идущих оператора (например, ++)
    if (is_operator(str[i]) && i > 0 && is_operator(str[i - 1])) {
      return false;
    }

    // Проверка на недопустимое расположение точек
    if (str[i] == '.' && (i == 0 || !isdigit(str[i - 1]))) {
      int j = i + 1;
      while (str[j] && isdigit(str[j])) j++;
      if (str[j] == '.') return false;
    }

    // Учет открывающих и закрывающих скобок
    if (str[i] == '(') {
      // Проверка на пустые скобки
      if (str[i + 1] == ')') {
        return false;
      }

      // Проверка, чтобы перед открывающей скобкой не было числа
      if (i > 0 && isdigit(str[i - 1])) {
        return false;
      }

      open_parentheses++;
    }

    if (str[i] == ')') {
      // Проверка, чтобы после закрывающей скобки не шло число
      if (isdigit(str[i + 1])) {
        return false;
      }
      close_parentheses++;
    }

    // Проверка, что выражение в скобках не заканчивается оператором
    if (str[i] == '(') {
      int j = i + 1;
      while (str[j] && str[j] != ')') {
        j++;
      }

      // Перемещаемся назад через все пробелы, чтобы найти символ перед
      // закрывающей скобкой
      int k = j - 1;
      while (str[k] == ' ' && k > i) {
        k--;
      }

      // Если перед закрывающей скобкой стоит оператор, возвращаем false
      if (is_operator(str[k])) {
        return false;
      }
    }
  }

  // Проверка, что количество открывающих и закрывающих скобок совпадает
  if (open_parentheses != close_parentheses) {
    return false;
  }

  // Список допустимых функций
  const char* functions[] = {"sin", "cos", "tan"};
  int num_functions = sizeof(functions) / sizeof(functions[0]);

  // Проверка на наличие корректных математических функций
  for (int i = 0; str[i]; i++) {
    if (isalpha(str[i])) {
      bool is_valid = false;
      for (int j = 0; j < num_functions; j++) {
        if (strncmp(str + i, functions[j], strlen(functions[j])) == 0) {
          if (str[i + strlen(functions[j])] != '(') {
            return false;
          }
          is_valid = true;
          i += strlen(functions[j]) - 1;  // Пропуск символов функции
          break;
        }
      }
      if (!is_valid) {
        return false;
      }
    }
  }

  // Проверка, что строка не заканчивается оператором
  int len = strlen(str);
  if (is_operator(str[len - 1])) {
    return false;
  }

  // Если все проверки пройдены, возвращаем true
  return true;
}

bool is_operator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool has_function(const char* str, const char* func) {
  return strstr(str, func) != NULL;
}
