#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval s, e;
    gettimeofday(&s, NULL);
    for(int i=0; i<1000000; i++); // Код для тесту
    gettimeofday(&e, NULL);
    printf("Time: %ld ms\n", (e.tv_sec - s.tv_sec)*1000 + (e.tv_usec - s.tv_usec)/1000);
    return 0;
}
