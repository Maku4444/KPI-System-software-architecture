#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Виклик malloc(0)...\n");
    void *ptr = malloc(0);

    if (ptr == NULL) {
        printf("malloc(0) повернув NULL\n");
    } else {
        printf("malloc(0) повернув вказівник: %p\n", ptr);
        printf("Звільняю пам'ять через free()...\n");
        free(ptr);
    }

    return 0;
}
