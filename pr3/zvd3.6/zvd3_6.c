#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
void recursive_function(int depth) {
    char stack_buffer[102400]; 
    
    if (depth % 10 == 0) {
        printf("Поточна глибина рекурсії: %d (використано приблизно %d КБ)\n", 
                depth, depth * 100);
    }
    
    recursive_function(depth + 1);
}

int main() {
    struct rlimit rl;

    if (getrlimit(RLIMIT_STACK, &rl) == 0) {
        printf("Поточний м'який ліміт стека: %ld байт\n", (long)rl.rlim_cur);
        printf("Поточний жорсткий ліміт стека: %ld байт\n", (long)rl.rlim_max);
    }
    printf("\nЗапуск рекурсії для переповнення стека...\n");
    recursive_function(1);

    return 0;
}
