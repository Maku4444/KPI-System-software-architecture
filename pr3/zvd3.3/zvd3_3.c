#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void handle_fsize_limit(int sig) {
    printf("\n[СИГНАЛ] SIGXFSZ: Досягнуто максимальний розмір файлу! Запис припинено.\n");
    exit(0); 
}

int main() {
    struct rlimit rl;
    const char *filename = "dice_results.txt";

    rl.rlim_cur = 1024; 
    rl.rlim_max = 2048; 

    if (setrlimit(RLIMIT_FSIZE, &rl) != 0) {
        perror("Помилка setrlimit");
        return 1;
    }
    signal(SIGXFSZ, handle_fsize_limit);
    FILE *f = fopen(filename, "w");
    if (!f) {
        perror("Не вдалося відкрити файл");
        return 1;
    }
    srand(time(NULL));
    printf("Починаю симуляцію кидків кубика у файл %s...\n", filename);
    printf("Встановлений ліміт: %ld байт.\n", rl.rlim_cur);

    while (1) {
        int roll = (rand() % 6) + 1;
        if (fprintf(f, "Результат кидка: %d\n", roll) < 0) {
            break;
        }
        fflush(f); 
    }

    fclose(f);
    return 0;
}
