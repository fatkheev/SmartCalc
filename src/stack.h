#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int isOperator(char c);
int priority(char c);
void converter(const char* expression, char* output);
double calculate(const char* postfix);
