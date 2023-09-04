#include "../stack.h"

bool validate_string(const char* str) {
  int open_parentheses = 0;
  int close_parentheses = 0;

  if (str[0] == ')') {
    return false;
  }

  for (int i = 0; str[i]; i++) {
    if ((str[i] == '/' || str[i] == '*' || str[i] == '^' || str[i] == 'm' ||
         str[i] == '%') &&
        (i == 0 || str[i - 1] == '(')) {
      return false;
    }

    if (!isdigit(str[i]) && !isOperator(str[i]) && !isalpha(str[i]) &&
        str[i] != '.' && str[i] != ' ' && str[i] != '(' && str[i] != ')') {
      return false;
    }

    if (isdigit(str[i]) && i > 0 && str[i - 1] == ' ') {
      int j = i - 2;
      while (j >= 0 && str[j] == ' ') j--;
      if (j >= 0 && isdigit(str[j])) {
        return false;
      }
    }

    if (isOperator(str[i])) {
      int j = i - 1;
      while (j >= 0 && str[j] == ' ') j--;  // Пропустить все пробелы
      if (j >= 0 &&
          isOperator(
              str[j])) {  // Проверка на наличие другого оператора перед текущим
        // Разрешить комбинации "/-", "*-", "*+"
        if (!((str[j] == '/' && str[i] == '-') ||
              (str[j] == '*' && str[i] == '-') ||
              (str[j] == '*' && str[i] == '+'))) {
          return false;
        }
      }
    }

    if (str[i] == '.') {
      if (i == 0 || !isdigit(str[i - 1])) {
        int j = i + 1;
        if (!isdigit(str[j])) {
          return false;
        }
      } else {
        int j = i + 1;
        if (str[j] && !isdigit(str[j]) && str[j] != ' ' &&
            !isOperator(str[j])) {
          return false;
        }
      }
    }

    if (str[i] == '(') {
      if (str[i + 1] == ')') {
        return false;
      }

      if (i > 0 && isdigit(str[i - 1])) {
        return false;
      }

      open_parentheses++;
    }

    if (str[i] == ')') {
      if (isdigit(str[i + 1])) {
        return false;
      }
      close_parentheses++;
    }

    if (str[i] == '(') {
      int j = i + 1;
      while (str[j] && str[j] != ')') {
        j++;
      }

      int k = j - 1;
      while (str[k] == ' ' && k > i) {
        k--;
      }

      if (isOperator(str[k])) {
        return false;
      }
    }
  }

  if (open_parentheses != close_parentheses) {
    return false;
  }

  const char* functions[] = {"sin",  "cos",  "tan", "asin", "acos",
                             "atan", "sqrt", "ln",  "log",  "mod"};
  int num_functions = sizeof(functions) / sizeof(functions[0]);

  for (int i = 0; str[i]; i++) {
    if (isalpha(str[i])) {
      bool is_valid = false;
      for (int j = 0; j < num_functions; j++) {
        if (strncmp(str + i, functions[j], strlen(functions[j])) == 0) {
          if (strcmp(functions[j], "mod") == 0) {
            int k = i - 1;
            while (k >= 0 && str[k] == ' ') k--;
            if (k < 0 || !isdigit(str[k])) {
              return false;
            }

            k = i + 3;
            while (str[k] && str[k] == ' ') k++;
            if (!isdigit(str[k])) {
              return false;
            }

            i += 2;
            is_valid = true;
            break;
          }

          if (str[i + strlen(functions[j])] != '(') {
            return false;
          }
          is_valid = true;
          i += strlen(functions[j]) - 1;
          break;
        }
      }
      if (!is_valid) {
        return false;
      }
    }
  }

  int len = strlen(str);
  if (isOperator(str[len - 1])) {
    return false;
  }

  return true;
}

bool has_function(const char* str, const char* func) {
  return strstr(str, func) != NULL;
}