#include "../stack.h"

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%' || c == 'm' || c == 'U');
}

int isFunction(char c) {
    return (c == 'C' || c == 'S' || c == 'T' || c == 'A' || c == 'B' || c == 'N' || c == 'R' || c == 'L' || c == 'G');
}

int isUnaryOperator(char c) {
    return (c == 'U');
}

int priority(char c) {
    switch (c) {
        case 'U':
            return 5;
        case '^':
            return 4;
        case '*':
        case '/':
        case '%':
        case 'm':
            return 3;
        case '+':
        case '-':
            return 2;
        case 'C':
        case 'S':
        case 'T':
        case 'A':
        case 'B':
        case 'N':
        case 'R':
        case 'L':
        case 'G':
            return 1;
        default:
            return -1;
    }
}

char getFunctionChar(const char* str) {
    if (strncmp(str, "cos", 3) == 0) return 'C';
    if (strncmp(str, "sin", 3) == 0) return 'S';
    if (strncmp(str, "tan", 3) == 0) return 'T';
    if (strncmp(str, "acos", 4) == 0) return 'A';
    if (strncmp(str, "asin", 4) == 0) return 'B';
    if (strncmp(str, "atan", 4) == 0) return 'N';
    if (strncmp(str, "sqrt", 4) == 0) return 'R';
    if (strncmp(str, "ln", 2) == 0) return 'L';
    if (strncmp(str, "log", 3) == 0) return 'G';
    return '\0';
}

void converter(const char* expression, char* output) {
    char operators[strlen(expression) + 1];
    int top = -1;
    int k = 0;

    for (size_t i = 0; i < strlen(expression); i++) {
        char ch = expression[i];

        if (ch == '-' && (i == 0 || expression[i - 1] == '(' || isOperator(expression[i - 1]))) {
            ch = 'U';
        }

        if (ch == '+' && (i == 0 || expression[i - 1] == '(' || isOperator(expression[i - 1]))) {
            continue;
        }
        
        if (isFunction(getFunctionChar(expression + i))) {
            ch = getFunctionChar(expression + i);
            operators[++top] = ch;
            while (i < strlen(expression) && !isdigit(expression[i]) && expression[i] != '(') {
                i++;
            }
            i--;
        } else if (ch == 'm' && i + 2 < strlen(expression) && strncmp(expression + i, "mod", 3) == 0) {
            while (top != -1 && priority(operators[top]) >= priority('m')) {
                output[k++] = operators[top--];
                output[k++] = ' ';
            }
            operators[++top] = 'm';
            i += 2;
        } else if (isdigit(ch)) {
            while (i < strlen(expression) && (isdigit(expression[i]) || expression[i] == '.')) {
                output[k++] = expression[i++];
            }
            i--;
            output[k++] = ' ';
        } else if (ch == '(') {
            operators[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && operators[top] != '(') {
                output[k++] = operators[top--];
                output[k++] = ' ';
            }
            if (top > 0 && isFunction(operators[top - 1])) {
                k--;
                output[k++] = operators[--top];
                output[k++] = ' ';
            }
            top--;
        } else if (isOperator(ch)) {
            while (top != -1 && priority(operators[top]) >= priority(ch)) {
                output[k++] = operators[top--];
                output[k++] = ' ';
            }
            operators[++top] = ch;
        }
    }

    while (top != -1) {
        output[k++] = operators[top--];
        output[k++] = ' ';
    }

    output[k] = '\0';
}

double calculate(const char* infixExpression) {
    char postfix[strlen(infixExpression) * 2];
    converter(infixExpression, postfix);

    double values[strlen(postfix)];
    int top = -1;

    for (size_t i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];
        
        if (ch == 'm') {
            double value2 = values[top--];
            double value1 = values[top--];
            values[++top] = fmod(value1, value2);
        } else if (isUnaryOperator(ch)) {
            double value = values[top--];
            values[++top] = -value;
        } else if (isdigit(ch) || (ch == '-' && isdigit(postfix[i+1]))) {
            double value = 0;
            while (i < strlen(postfix) && (isdigit(postfix[i]) || postfix[i] == '.')) {
                value = value * 10 + (postfix[i++] - '0');
            }
            i--;
            values[++top] = value;
        } else if (isOperator(ch)) {
            double value2 = values[top--];
            double value1 = values[top--];
            switch (ch) {
                case '+':
                    values[++top] = value1 + value2;
                    break;
                case '-':
                    values[++top] = value1 - value2;
                    break;
                case '*':
                    values[++top] = value1 * value2;
                    break;
                case '/':
                    values[++top] = value1 / value2;
                    break;
                case '^':
                    values[++top] = pow(value1, value2);
                    break;
                case '%':
                    values[++top] = fmod(value1, value2);
                    break;
            }
        } else if (isFunction(ch)) {
            double value = values[top--];
            switch (ch) {
                case 'C':
                    values[++top] = cos(value);
                    break;
                case 'S':
                    values[++top] = sin(value);
                    break;
                case 'T':
                    values[++top] = tan(value);
                    break;
                case 'A':
                    values[++top] = acos(value);
                    break;
                case 'B':
                    values[++top] = asin(value);
                    break;
                case 'N':
                    values[++top] = atan(value);
                    break;
                case 'R':
                    values[++top] = sqrt(value);
                    break;
                case 'L':
                    values[++top] = log(value);
                    break;
                case 'G':
                    values[++top] = log10(value);
                    break;
            }
        }
    }
    return values[0];
}