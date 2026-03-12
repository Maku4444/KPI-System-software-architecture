#include <stdlib.h>
#include <stdio.h>

int main() {
    char *ptr = malloc(10); 
    printf("Запис за межі malloc...\n");
    ptr[20] = 'X'; 
    
    free(ptr);
    return 0;
}
