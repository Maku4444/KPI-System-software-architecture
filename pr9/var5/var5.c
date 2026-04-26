#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main() {
    const char *filename = "blind_dropbox.txt";
    int fd;

    printf("=== МОДЕЛЮВАННЯ СИТУАЦІЇ 'WRITE-ONLY' ===\n\n");

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    write(fd, "СЕКРЕТНІ ДАНІ АДМІНІСТРАТОРА\n", 53);
    close(fd);
    printf("[+] Файл створено та заповнено даними.\n");

    if (chmod(filename, S_IWUSR) == 0) {
        printf("[+] Права змінено: тепер власник має ЛИШЕ права на запис (--w-------).\n\n");
    }

    printf("Спроба 1: Відкрити файл для ЧИТАННЯ (O_RDONLY)...\n");
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        printf("    ПОМИЛКА: Неможливо прочитати файл! (Код: %s)\n", strerror(errno));
    } else {
        printf("    Успіх (цього не мало статися).\n");
        close(fd);
    }


    printf("\nСпроба 2: Відкрити файл для ЗАПИСУ/ДОПИСУВАННЯ (O_WRONLY | O_APPEND)...\n");
    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd >= 0) {
        char *new_data = "Новий запис від 'сліпого' користувача.\n";
        write(fd, new_data, strlen(new_data));
        printf("    УСПІХ: Дані успішно дописані у файл!\n");
        close(fd);
    } else {
        printf("    Помилка запису.\n");
    }


    chmod(filename, 0600);
    unlink(filename); 

    return 0;
}
