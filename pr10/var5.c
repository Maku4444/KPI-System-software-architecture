#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;
    int exit_val = 7; 

    pid = fork();

    if (pid < 0) {
        perror("Помилка fork");
        exit(1);
    }

    if (pid == 0) {
        printf("[CHILD] PID: %d. Працюю...\n", getpid());
        sleep(1); 
        printf("[CHILD] Завершуюсь із кодом: %d\n", exit_val);
        exit(exit_val);
    } else {
        printf("[PARENT] PID: %d. Очікую на завершення нащадка...\n", getpid());
        
        wait(&status);

        if (WIFEXITED(status)) {
            int code = WEXITSTATUS(status); 
            printf("[PARENT] Дочірній процес завершився нормально.\n");
            printf("[PARENT] ОТРИМАНИЙ КОД: %d\n", code);
        } else {
            printf("[PARENT] Дочірній процес завершився аномально.\n");
        }
    }

    return 0;
}
