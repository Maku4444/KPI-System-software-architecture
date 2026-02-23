#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100
int stack[STACK_SIZE];
int sp = -1; // Stack Pointer (вказівник вершини)

void push(int val) {
    if (sp < STACK_SIZE - 1) {
        stack[++sp] = val;
    } else {
        printf("Помилка: Переповнення стека\n");
    }
}

int pop() {
    if (sp >= 0) {
        return stack[sp--];
    } else {
        printf("Помилка: Стек порожній\n");
        return 0;
    }
}

// Виконання операцій
void calculate(char op) {
    int b = pop();
    int a = pop();
    switch (op) {
        case '+': push(a + b); break;
        case '-': push(a - b); break;
        case '*': push(a * b); break;
        case '/': 
            if (b != 0) push(a / b); 
            else printf("Помилка: Ділення на нуль\n");
            break;
    }
}

int main() {
    printf("--- Симуляція стекової машини (ZVD 2.6) ---\n");
    printf("Обчислюємо вираз: (5 + 3) * 2\n");

    push(5);
    push(3);
    calculate('+'); // 5 + 3 = 8
    push(2);
    calculate('*'); // 8 * 2 = 16

    printf("Результат на вершині стека: %d\n", pop());

    return 0;
}
