#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int isOperator(char c);
int priority(char c);
void converter(const char* expression, char* output);
double calculate(const char* postfix);

bool validate_string(const char* str);