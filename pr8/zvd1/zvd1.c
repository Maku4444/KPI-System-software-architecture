#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int fd[2];
    pipe(fd); 

    fcntl(fd[1], F_SETFL, O_NONBLOCK);

    int nbytes = 1024 * 1024;
    char *buffer = malloc(nbytes);

    printf("Спроба записати %d байт...\n", nbytes);
    ssize_t count = write(fd[1], buffer, nbytes);

    printf("Успішно записано: %zd байт\n", count);
    if (count < nbytes) {
        printf("Висновок: write() записав менше, ніж просили, оскільки буфер pipe переповнився.\n");
    }

    free(buffer);
    close(fd[0]);
    close(fd[1]);
    return 0;
}
