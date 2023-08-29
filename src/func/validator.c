#include "../stack.h"

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
    if (!isdigit(str[i]) && !isOperator(str[i]) && !isalpha(str[i]) &&
        str[i] != '.' && str[i] != ' ' && str[i] != '(' && str[i] != ')') {
      return false;
    }

    // Проверка на два подряд идущих оператора (например, ++)
    if (isOperator(str[i]) && i > 0 && isOperator(str[i - 1])) {
      return false;
    }

    // Проверка на недопустимое расположение точек
    if (str[i] == '.') {
      // Проверка, что перед точкой есть число
      if (i == 0 || !isdigit(str[i - 1])) {
        return false;
      }

      int j = i + 1;
      // Проверка, что после точки идет число
      if (!isdigit(str[j])) {
        return false;
      }

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
      if (isOperator(str[k])) {
        return false;
      }
    }
  }

  // Проверка, что количество открывающих и закрывающих скобок совпадает
  if (open_parentheses != close_parentheses) {
    return false;
  }

  // Список допустимых функций
  const char* functions[] = {"sin",  "cos",  "tan", "asin", "acos",
                             "atan", "sqrt", "ln",  "log",  "mod"};
  int num_functions = sizeof(functions) / sizeof(functions[0]);

  // Проверка на наличие корректных математических функций
  for (int i = 0; str[i]; i++) {
    if (isalpha(str[i])) {
      bool is_valid = false;
      for (int j = 0; j < num_functions; j++) {
        if (strncmp(str + i, functions[j], strlen(functions[j])) == 0) {
          // Исключение для "mod": не требуется наличие скобок
          if (strcmp(functions[j], "mod") == 0) {
            is_valid = true;
            i += 2;  // Пропускаем символы "od"
            break;
          }

          // Для остальных функций требуются скобки
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
  if (isOperator(str[len - 1])) {
    return false;
  }

  // Если все проверки пройдены, возвращаем true
  return true;
}

bool has_function(const char* str, const char* func) {
  return strstr(str, func) != NULL;
}