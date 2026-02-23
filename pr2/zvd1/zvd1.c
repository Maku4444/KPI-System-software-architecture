#include <stdio.h>
#include <time.h>
#include <limits.h>

int main() {
    printf("Ваша поточна архітектура: %zu-bit (time_t = %zu байт)\n\n", sizeof(time_t) * 8, sizeof(time_t));

    time_t max_32 = (time_t)2147483647;
    printf("ЛІМІТ ДЛЯ 32-BIT (Проблема 2038): %s", ctime(&max_32));

    if (sizeof(time_t) == 8) {
        time_t max_64 = (time_t)9223372036854775807LL; 
        printf("ЛІМІТ ДЛЯ 64-BIT:                 %s", ctime(&max_64));
    }

    return 0;
}
