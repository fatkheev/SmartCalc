#include "../calc.h"

// Функция для создания нового стека
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (char**)malloc(stack->capacity * sizeof(char*));
    return stack;
}

// Проверка, пуст ли стек
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Проверка, полон ли стек
bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Добавление элемента в стек
int push(Stack* stack, char* item) {
    if (isFull(stack)) {
        return -1;  // Ошибка: стек полон
    }
    stack->items[++stack->top] = item;
	 return 0;  // Успешное добавление
}

// Удаление и возврат верхнего элемента стека
char* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Стек пуст. Невозможно удалить элемент.\n");
        return NULL;
    }
    return stack->items[stack->top--];
}

// Возврат верхнего элемента стека без его удаления
char* peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Стек пуст.\n");
        return NULL;
    }
    return stack->items[stack->top];
}

// Освобождение памяти стека
void freeStack(Stack* stack) {
    free(stack->items);
    free(stack);
}