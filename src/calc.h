#define _POSIX_C_SOURCE 200809L

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char** tokens;
  int size;
  bool is_valid;
} ParseResult;

// Валидатор
bool validate_string(const char* str);
bool is_operator(char c);
bool has_function(const char* str, const char* func);

// Парсер
char** parse_string(const char* str);

// Вспомогательные функции
char* my_strdup(const char* s);
char* my_strndup(const char* s, size_t n);