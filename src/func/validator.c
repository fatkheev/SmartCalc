#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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
    
    for (int i = 0; str[i]; i++) {
        // Проверяем, является ли символ числом, оператором или буквой (для функций)
        if (!isdigit(str[i]) && !is_operator(str[i]) && !isalpha(str[i]) && str[i] != '.' && str[i] != ' ') {
            return false;
        }
        
        // Подсчет скобок
        if (str[i] == '(') open_parentheses++;
        if (str[i] == ')') close_parentheses++;
        
        // Корректировка чисел с плавающей точкой
        if (str[i] == '.' && (i == 0 || !isdigit(str[i-1]))) {
            memmove(&str[i+1], &str[i], strlen(str) - i + 1);
            str[i] = '0';
        }
    }

    // Проверка на равное количество открывающих и закрывающих скобок
    if (open_parentheses != close_parentheses) {
        return false;
    }
    
    // Проверка на корректность функций
    if (has_function(str, "sin") || has_function(str, "cos")) {
        // Здесь можно добавить дополнительные проверки для функций
    }

    return true;
}



// Разделение строки на токены
char** parse_string(const char* str, int* size) {
    char** tokens = malloc(sizeof(char*) * strlen(str)); // Максимальное количество токенов
    char* token = malloc(sizeof(char) * strlen(str)); // Один токен
    int token_index = 0, tokens_count = 0;

    for (int i = 0; str[i]; i++) {
        // Если символ является оператором или скобкой, добавляем текущий токен в список
        if (is_operator(str[i]) || str[i] == ' ') {
            if (token_index > 0) {
                token[token_index] = '\0'; // Завершение текущего токена
                tokens[tokens_count] = strdup(token); // Добавление токена в список
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

    *size = tokens_count;
    return tokens;
}
