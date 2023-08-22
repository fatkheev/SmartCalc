#include "../calc.h"

char** parse_string(const char* str) {
    if (!validate_string(str)) {
        return NULL;
    }

    int max_tokens = 3 * strlen(str) + 1;  
    char** tokens = (char**)malloc(sizeof(char*) * max_tokens);
    memset(tokens, 0, sizeof(char*) * max_tokens);

    char* token = (char*)malloc(sizeof(char) * (strlen(str) + 1));
    memset(token, 0, sizeof(char) * (strlen(str) + 1));
    int token_index = 0, tokens_count = 0;

    int i = 0;
    while (str[i]) {
        int prev_non_space_index = i - 1;
        while (prev_non_space_index >= 0 && str[prev_non_space_index] == ' ') {
            prev_non_space_index--;
        }

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
                (prev_non_space_index >= 0 && str[prev_non_space_index] == '(' &&
                 str[j] == ')');

            if (!isAlreadyInParentheses) {
                tokens[tokens_count++] = strdup("(");
                tokens[tokens_count++] = strdup("0");
                tokens[tokens_count++] = strdup("-");
            } else {
                tokens[tokens_count++] = strdup("0");
                tokens[tokens_count++] = strdup("-");
            }

            i++;
            while (str[i] == ' ') {
                i++;
            }

            if (str[i] == '.') {
                token[token_index++] = '0';
            }

            while (str[i] && !is_operator(str[i]) && str[i] != ')' && str[i] != '(') {
                token[token_index++] = str[i];
                i++;
            }

            if (token[token_index - 1] == '.') {
                token[token_index++] = '0';
            }

            if (token_index > 0) {
                token[token_index] = '\0';
                tokens[tokens_count++] = strdup(token);
                token_index = 0;
            }

            if (!isAlreadyInParentheses) {
                tokens[tokens_count++] = strdup(")");
            }
            continue;
        }

        if (str[i] == 'm' && str[i + 1] == 'o' && str[i + 2] == 'd' && (str[i + 3] == ' ' || !str[i + 3])) {
            tokens[tokens_count++] = strdup("mod");
            i += 2;
        } else if (is_operator(str[i]) || str[i] == ' ' || str[i] == '(' || str[i] == ')') {
            if (token_index > 0) {
                token[token_index] = '\0';
                tokens[tokens_count++] = strdup(token);
                token_index = 0;
            }
            if (is_operator(str[i]) || str[i] == '(' || str[i] == ')') {
                tokens[tokens_count] = (char*)malloc(2);
                tokens[tokens_count][0] = str[i];
                tokens[tokens_count][1] = '\0';
                tokens_count++;
            }
        } else if (str[i] == '.') {
            if (i == 0 || !isdigit(str[i - 1])) {
                token[token_index++] = '0';
            }
            token[token_index++] = '.';
            if (!isdigit(str[i + 1])) {
                token[token_index++] = '0';
            }
        } else if (isalpha(str[i])) {
            int start = i;
            while (isalpha(str[i])) {
                i++;
            }
            int len = i - start;
            tokens[tokens_count++] = strndup(str + start, len);
            i--;
        } else {
            token[token_index++] = str[i];
        }

        i++;

        if (tokens_count >= max_tokens) {
            max_tokens *= 2;
            tokens = (char**)realloc(tokens, sizeof(char*) * max_tokens);
            memset(tokens + tokens_count, 0, sizeof(char*) * (max_tokens - tokens_count));
        }
    }

    if (token_index > 0) {
        token[token_index] = '\0';
        tokens[tokens_count++] = strdup(token);
    }

    tokens[tokens_count] = NULL; 

    free(token);
    return tokens;
}
