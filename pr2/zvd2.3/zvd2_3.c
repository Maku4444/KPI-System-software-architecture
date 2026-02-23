#include <stdio.h>
#include <stdlib.h>


int global_data = 42; 


void expand_stack() {

    int large_array1[5000]; 
    int large_array2[5000];
    int stack_low;


    large_array1[0] = 1;
    large_array2[0] = 2;

    printf("Адреса вершини стека ПІСЛЯ збільшення: %p\n", (void*)&stack_low);
}

int main() {

    int stack_top; 
    int *heap_ptr = malloc(sizeof(int)); 


    printf("Розташування сегмента ТЕКСТУ:          %p\n", (void*)main);
    printf("Розташування сегмента ДАНИХ:           %p\n", (void*)&global_data);
    printf("Розташування КУПИ (всередині даних):   %p\n", (void*)heap_ptr);
    printf("Початкова адреса вершини СТЕКА:        %p\n", (void*)&stack_top);


    expand_stack();

    free(heap_ptr);
    return 0;
}
