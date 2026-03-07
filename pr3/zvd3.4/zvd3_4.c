#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void handle_cpu_limit(int sig) {
    printf("\n[STOP] SIGXCPU: Вичерпано ліміт процесорного часу! Програма зупинена.\n");
    exit(0);
}
void run_lottery(int count, int range) {
    printf("Генерація лотереї (%d із %d): ", count, range);
    for (int i = 0; i < count; i++) {
        printf("%d ", (rand() % range) + 1);
    }
    printf("\n");
}

int main() {
    struct rlimit rl;
    rl.rlim_cur = 1; 
    rl.rlim_max = 2; 

    if (setrlimit(RLIMIT_CPU, &rl) != 0) {
        perror("setrlimit");
        return 1;
    }
    signal(SIGXCPU, handle_cpu_limit);

    srand(time(NULL));
    printf("Починаю інтенсивну генерацію лотерейних чисел...\n");

    unsigned long long counter = 0;
    while (1) {
        if (counter % 100000 == 0) {
            run_lottery(7, 49);
            run_lottery(6, 36);
        }
        counter++;
    }

    return 0;
}
