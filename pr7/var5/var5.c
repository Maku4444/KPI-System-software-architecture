#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void internal_logic() {
    // Системні виклики: open, write, close
    int fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd != -1) {
        write(fd, "Syscall Tree Demo\n", 18);
        close(fd);
    }
}

int main() {
    printf("Початок трасування...\n");
    internal_logic();
    sleep(1); // Системний виклик nanosleep
    printf("Завершено.\n");
    return 0;
}
