#include "../stack.h"

bool validate_string(const char* str) {
  int open_parentheses = 0;
  int close_parentheses = 0;
  int dot_count = 0;
  bool is_valid = true;

  if (str[0] == ')') {
    is_valid = false;
  }

  for (int i = 0; is_valid && str[i]; i++) {
    if (str[i] == ' ' || isOperator(str[i])) {
      dot_count = 0;
    }

    if (dot_count > 1 ||
        ((str[i] == '/' || str[i] == '*' || str[i] == '^' || str[i] == 'm' ||
          str[i] == '%') &&
         (i == 0 || str[i - 1] == '(')) ||
        (!isdigit(str[i]) && !isOperator(str[i]) && !isalpha(str[i]) &&
         str[i] != '.' && str[i] != ' ' && str[i] != '(' && str[i] != ')')) {
      is_valid = false;
    } else if (isdigit(str[i]) && i > 0 && str[i - 1] == ' ') {
      int j = i - 2;
      while (j >= 0 && str[j] == ' ') j--;
      if (j >= 0 && isdigit(str[j])) {
        is_valid = false;
      }
    } else if (isOperator(str[i])) {
      int j = i - 1;
      while (j >= 0 && str[j] == ' ') j--;
      if (j >= 0 && isOperator(str[j]) &&
          !((str[j] == '/' && str[i] == '-') ||
            (str[j] == '*' && str[i] == '-') ||
            (str[j] == '*' && str[i] == '+'))) {
        is_valid = false;
      }
    } else if (str[i] == '.') {
      dot_count++;
      if (i == 0 || !isdigit(str[i - 1])) {
        int j = i + 1;
        if (!isdigit(str[j])) {
          is_valid = false;
        }
      } else if (str[i] == '(') {
        if (str[i + 1] == ')' || (i > 0 && isdigit(str[i - 1]))) {
          is_valid = false;
        }
        open_parentheses++;
      } else if (str[i] == ')') {
        if (isdigit(str[i + 1])) {
          is_valid = false;
        }
        close_parentheses++;
      } else {
        int j = i + 1;
        if (str[j] && !isdigit(str[j]) && str[j] != ' ' &&
            !isOperator(str[j])) {
          is_valid = false;
        }
      }
    }

    int j = i + 1;
    while (is_valid && str[j] && str[j] != ')') { // что это
      j++;
    }
    int k = j - 1;
    while (str[k] == ' ' && k > i) {
      k--;
    }
    if (isOperator(str[k])) {
      is_valid = false;
    }
  }

  if (open_parentheses != close_parentheses ||
      !validate_functions_in_string(str) || isOperator(str[strlen(str) - 1])) {
    is_valid = false;
  }

  return is_valid;
}

bool has_function(const char* str, const char* func) {
  return strstr(str, func) != NULL;
}

// Проверка ввода функций
bool validate_functions_in_string(const char* str) {
  const char* functions[] = {"sin",  "cos",  "tan", "asin", "acos",
                             "atan", "sqrt", "ln",  "log",  "mod"};
  int num_functions = sizeof(functions) / sizeof(functions[0]);

  bool is_all_valid = true;

  for (int i = 0; is_all_valid && str[i]; i++) {
    if (isalpha(str[i])) {
      bool is_valid = false;

      for (int j = 0; !is_valid && j < num_functions; j++) {
        if (strncmp(str + i, functions[j], strlen(functions[j])) == 0) {
          if (strcmp(functions[j], "mod") == 0) {
            int k = i - 1;
            while (k >= 0 && str[k] == ' ') k--;
            bool is_previous_digit = k >= 0 && isdigit(str[k]);

            k = i + 3;
            while (str[k] && str[k] == ' ') k++;
            bool is_next_digit = isdigit(str[k]);

            if (!is_previous_digit || !is_next_digit) {
              is_all_valid = false;
            }

            i += 2;
            is_valid = true;
          } else if (str[i + strlen(functions[j])] != '(') {
            is_all_valid = false;
          } else {
            i += strlen(functions[j]) - 1;
            is_valid = true;
          }
        }
      }

      if (!is_valid) {
        is_all_valid = false;
      }
    }
  }

  return is_all_valid;
}
