#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long cmp_count = 0;

int compare(const void *a, const void *b) {
    cmp_count++;
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    return (int_a > int_b) - (int_a < int_b);
}

void check_sorted(int *arr, int n, const char *test_name) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i+1]) {
            printf(" Тест '%s' ПРОВАЛЕНО!\n", test_name);
            return;
        }
    }
    printf(" Тест '%s' пройдено успішно.\n", test_name);
}

int main() {
    int n = 10000;
    int *arr = malloc(n * sizeof(int));
    srand(time(NULL));

    printf("--- АНАЛІЗ ШВИДКОДІЇ QSORT (Розмір масиву: %d) ---\n", n);

    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
    cmp_count = 0;
    qsort(arr, n, sizeof(int), compare);
    printf("Випадковий масив:        %llu порівнянь\n", cmp_count);

    cmp_count = 0;
    qsort(arr, n, sizeof(int), compare);
    printf("Відсортований масив:     %llu порівнянь\n", cmp_count);

    for (int i = 0; i < n; i++) arr[i] = n - i;
    cmp_count = 0;
    qsort(arr, n, sizeof(int), compare);
    printf("Зворотний порядок:       %llu порівнянь\n", cmp_count);

    for (int i = 0; i < n; i++) arr[i] = 42;
    cmp_count = 0;
    qsort(arr, n, sizeof(int), compare);
    printf("Всі елементи однакові:   %llu порівнянь \n", cmp_count);

    printf("\n--- ТЕСТУВАННЯ ПРАВИЛЬНОСТІ ---\n");
    check_sorted(arr, n, "Масив з однакових елементів");
    
    int test_arr[] = {9, 2, 5, 1, 7, 3, 8};
    qsort(test_arr, 7, sizeof(int), compare);
    check_sorted(test_arr, 7, "Звичайний масив");

    free(arr);
    return 0;
}
