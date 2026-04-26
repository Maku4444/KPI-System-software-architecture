#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== Перевірка облікового запису (whoami) ===\n");
    system("whoami");

    printf("\n=== Перевірка груп та ідентифікаторів (id) ===\n");
    system("id");

    return 0;
}
