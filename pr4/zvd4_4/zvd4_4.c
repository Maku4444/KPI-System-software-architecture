#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = NULL;
    int n = 128;

    for (int i = 1; i <= 2; i++) {
        printf("Ітерація %d:\n", i);
        if (!ptr) {
            ptr = malloc(n);
            printf("  Пам'ять виділена: %p\n", ptr);
        } else {
            printf("  ПОМИЛКА: ptr не NULL, хоча пам'ять була звільнена!\n");
        }
        free(ptr);
         ptr = NULL; 
    }
    return 0;
}
