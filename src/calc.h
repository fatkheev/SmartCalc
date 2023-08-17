#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char** tokens;
    int size;
    bool is_valid;
} ParseResult;

// Валидатор
bool validate_string(char* str);

// Парсер
char** parse_string(const char* str, int* size);