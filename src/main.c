#include "calc.h"

// int main() {
//   char input[] = "(     -.100)";
//   char** tokens = parse_string(input);
//   printf("Обрабатываемая строка: %s\n", input);
//   if (tokens) {
//     printf("Токены:\n\n");

//     int i = 0;
//     int token_count = 0;

//     // // Для тестов:
//     // printf("char** tokens = parse_string(\"%s\");\n\n", input);
//     // while (tokens[i]) {
//     //   printf("ck_assert_str_eq(tokens[%d], \"%s\");\n", i, tokens[i]);
//     //   free(tokens[i]);
//     //   i++;
//     //   token_count++;
//     // }

//     // Для проверки в реальном времени:
//     while (tokens[i]) {
//       printf("%s", tokens[i]);
//       free(tokens[i]);
//       i++;
//       token_count++;
//     }

//     printf("\n\nКоличество символов во входной строке: %d\n",
//            (int)strlen(input));
//     printf("Количество элементов в массиве: %d\n", token_count);

//     free(tokens);
//   } else {
//     printf("Строка не прошла валидацию.\n");
//   }

//   return 0;
// }

int main() {
    Stack* stack = createStack(10);
    push(stack, "1");
    push(stack, "+");
    push(stack, "1");
    printf("Верх стека: %s\n", peek(stack));
    printf("Удален из стека: %s\n", pop(stack));
    printf("Верх стека после удаления: %s\n", peek(stack));
    freeStack(stack);
    return 0;
}