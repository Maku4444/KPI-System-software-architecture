#include <stdio.h>
int main() {
    printf("Програма запущена. Очікуйте завершення за лімітом CPU...\n");
    unsigned long long counter = 0;
    while (1) {
        counter++;
        if (counter == 0) break; 
    }

    return 0;
}
