#define _GNU_SOURCE 
#include <stdio.h>
#include <stdlib.h>

struct sbar {
    int data[10];
};

int main() {
    struct sbar *ptr, *newptr;
    ptr = calloc(1000, sizeof(struct sbar));
    printf("Виділено через calloc: %p\n", (void*)ptr);
    newptr = reallocarray(ptr, 500, sizeof(struct sbar));
    
    if (newptr) {
        printf("Успішно змінено розмір через reallocarray: %p\n", (void*)newptr);
        free(newptr);
    } else {
        free(ptr);
    }

    return 0;
}
