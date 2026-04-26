#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char data[] = {4, 5, 2, 2, 3, 3, 7, 9, 1, 5};
    char buffer[4];

    int fd = open("temp.dat", O_CREAT | O_RDWR | O_TRUNC, 0644);
    write(fd, data, sizeof(data));

    lseek(fd, 3, SEEK_SET);

    ssize_t bytes_read = read(fd, buffer, 4);

    printf("Прочитано байтів: %zd\n", bytes_read);
    printf("Вміст буфера: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    close(fd);
    unlink("temp.dat"); 
    return 0;
}
