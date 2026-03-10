#include <stdio.h>
#include <stdlib.h>

int main() {
    int xa = 1024 * 1024;
    int xb = 8192; 
    int num = xa * xb; 

    printf("Результат множення (signed int): %d\n", num);
    void *ptr = malloc(num);
    if (!ptr) printf("malloc повернув NULL\n");
    else printf("malloc виділив пам'ять за помилковим розміром\n");
    
    free(ptr);
    return 0;
}
