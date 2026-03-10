#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    size_t max_size = (size_t)-1;
    printf("Спроба виділити максимальний обсяг: %zu байт\n", max_size);
    
    void *ptr = malloc(max_size);
    if (!ptr) {
        perror("Результат malloc");
    }
    return 0;
}
