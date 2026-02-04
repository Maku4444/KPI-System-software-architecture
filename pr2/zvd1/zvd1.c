#include <stdio.h>
#include <time.h>
#include <limits.h>

int main() {
    printf("Дослідження розрядності time_t:\n");
    printf("Розмір типу на вашій архітектурі: %zu байт\n", sizeof(time_t));

    if (sizeof(time_t) == 4) {
        time_t max_32 = (time_t)INT_MAX;
        printf("Межа (32-bit): %s", ctime(&max_32));
    } else {
        time_t max_64 = (time_t)LLONG_MAX;
        printf("Межа (64-bit): %s", ctime(&max_64));
    }

    return 0;
}
