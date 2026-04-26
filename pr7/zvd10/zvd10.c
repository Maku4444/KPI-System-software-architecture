#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float n = 10.5;
    srand(time(NULL));
    printf("0 to 1: %f\n", (float)rand()/RAND_MAX);
    printf("0 to n: %f\n", ((float)rand()/RAND_MAX) * n);
    return 0;
}
