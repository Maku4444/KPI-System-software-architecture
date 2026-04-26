#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("=== Права у домашньому каталозі (~/) ===\n");
    system("ls -ld ~/");

    printf("\n=== Права у каталозі бінарників (/usr/bin) ===\n");
    system("ls -ld /usr/bin");

    printf("\n=== Права у каталозі конфігурацій (/etc) ===\n");
    system("ls -ld /etc");

    printf("\n=== ДЕМОНСТРАЦІЯ СПРОБ ДОСТУПУ ===\n");
    
    printf("Спроба 1: Читання /etc/passwd (Дозволено всім)\n");
    if (access("/etc/passwd", R_OK) == 0) {
        printf("Результат: Успіх! Ми можемо читати файл.\n");
    }

    printf("\nСпроба 2: Запис у /etc/passwd (Тільки для root)\n");
    if (access("/etc/passwd", W_OK) == -1) {
        printf("Результат: Відмова! (Permission denied) - Захист працює.\n");
    }

    printf("\nСпроба 3: Виконання /etc/passwd \n");
    if (access("/etc/passwd", X_OK) == -1) {
        printf("Результат: Відмова! (Permission denied)\n");
    }

    return 0;
}
