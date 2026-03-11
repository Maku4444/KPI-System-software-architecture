#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== Демонстрація Завдання 5: Витік при помилці ===\n\n");
    void *ptr = malloc(1024);
    if (!ptr) return 1;
    printf("[1] Пам'ять виділена за адресою: %p\n", ptr);
    
    void *tmp = realloc(ptr, 2048);
    if (tmp) {
        ptr = tmp;
        printf("[2] Успішний сценарій: Пам'ять розширено до 2 КБ. Адреса: %p\n", ptr);
    }

    size_t huge_size = (size_t)-1; 
    printf("[3] Спроба системного виклику realloc на %zu байт...\n", huge_size);

    void *new_ptr = realloc(ptr, huge_size);

    if (new_ptr == NULL) {
        fprintf(stderr, "!!! ПОМИЛКА: realloc повернув NULL.\n");
        return 1;
    }
    free(new_ptr);
    return 0;
}
