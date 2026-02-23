#include <stdio.h>

#ifdef STEP2
int global_array[1000]; 
#endif

#ifdef STEP3
int global_array_init[1000] = {1, 2, 3}; 
#endif

int main() {
    printf("Hello World\n");

#ifdef STEP4
    int local_array[1000]; 
    int local_array_init[1000] = {7}; 
#endif

    return 0;
}
