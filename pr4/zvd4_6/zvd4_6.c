#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = malloc(100);
    printf("Виділено: %p\n", ptr);
    void *new_ptr = realloc(ptr, 0); 
    printf("Після realloc(ptr, 0): %p \n", new_ptr);
    return 0;
}
