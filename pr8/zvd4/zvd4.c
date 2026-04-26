#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> 

int main() {
    int pid;
    pid = fork();
    
    printf("%d\n", pid);
    
    if (pid > 0) {
        wait(NULL); 
    }
    
    return 0;
}
