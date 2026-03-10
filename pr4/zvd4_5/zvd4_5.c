#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = malloc(1024);
    printf("Початковий вказівник: %p\n", ptr);
    size_t huge_size = (size_t)-1; 
  
    void *tmp = realloc(ptr, huge_size);

    if (tmp == NULL) {
        printf("realloc не зміг виділити пам'ять. Старий вказівник %p все ще валідний!\n", ptr);
        free(ptr); 
    } else {
        ptr = tmp;
        free(ptr);
    }
    return 0;
}
