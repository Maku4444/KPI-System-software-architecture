#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>

__thread sigjmp_buf checkpoint_env;         
__thread volatile int current_step = 1;   
__thread volatile int computation_result = 0; 
__thread int crashed_already = 0;           

void handle_sigsegv(int sig) {
    printf("\n[!!!] КРИТИЧНА ПОМИЛКА: SIGSEGV перехоплено в потоці %ld!\n", pthread_self());
    printf("[!!!] Ініціюю відновлення з останньої контрольної точки...\n\n");
    
    siglongjmp(checkpoint_env, 1);
}


void* compute_task(void* arg) {
    int thread_id = *(int*)arg;
    
    if (sigsetjmp(checkpoint_env, 1) != 0) {

        printf("[Thread %d] ВІДНОВЛЕНО! Повернення до кроку %d. Збережений результат: %d\n", 
               thread_id, current_step, computation_result);

        current_step++; 
    }


    while (current_step <= 8) {
        printf("[Thread %d] Виконання кроку %d (Поточний результат: %d)\n", 
               thread_id, current_step, computation_result);
        

        computation_result += current_step * 10;

        if (thread_id == 1 && current_step == 4 && !crashed_already) {
            printf("[Thread %d]  Симуляція апаратного збою (звернення до NULL)...\n", thread_id);
            crashed_already = 1; 
            
            int *bad_ptr = NULL;
            *bad_ptr = 42; 
        }

        current_step++;
        sleep(1); 
    }

    printf("[Thread %d]  Обчислення успішно завершено. Фінальний результат: %d\n", 
           thread_id, computation_result);
    return NULL;
}

int main() {
    printf("=== Запуск системи з Checkpoint & Recovery ===\n\n");

    struct sigaction sa;
    sa.sa_handler = handle_sigsegv;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    
    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("Помилка налаштування sigaction");
        exit(1);
    }

    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_create(&t1, NULL, compute_task, &id1);
    pthread_create(&t2, NULL, compute_task, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("\n=== Роботу системи безпечно завершено ===\n");
    return 0;
}
