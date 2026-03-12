#include <stdio.h>

void recursive_function(int depth) {
    char array[1024 * 64]; 
    printf("Глибина рекурсії: %d\n", depth);
    recursive_function(depth + 1);
}

int main() {
    recursive_function(1);
    return 0;
}
