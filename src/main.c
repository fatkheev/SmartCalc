#include "calc.h"

int main() {
    int size;
    char input[] = "sin(-1-(2+(.3-6)))";

    char** tokens = parse_string(input, &size);

    printf("Токены:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }
	 printf("\nСтрока: %s\n", input);
    bool is_valid = validate_string(input);
    printf("Проверка: %s\n\n", is_valid ? "true" : "false");
    free(tokens);

    return 0;
}