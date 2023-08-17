#include "calc.h"

int main() {
    char input[1000]; // Буфер для входной строки

    printf("Введите математическое выражение (или 'exit' для выхода):\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Удаление символа новой строки из входной строки
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (validate_string(input)) {
            int size;
            char** tokens = parse_string(input, &size);

            printf("Токены:\n");
            for (int i = 0; i < size; i++) {
                printf("%s\n", tokens[i]);
                free(tokens[i]);
            }
				printf("Строка корректна.\n");
            free(tokens);
        } else {
            printf("Строка некорректна.\n");
        }
    }

    return 0;
}
