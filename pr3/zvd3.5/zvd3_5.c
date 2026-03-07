#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/resource.h>
void handle_fsize_error(int sig) {
    fprintf(stderr, "\n[ПОМИЛКА] SIGXFSZ: Файл-призначення перевищив допустимий ліміт розміру!\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Використання: %s <джерело> <призначення>\n", argv[0]);
        return 1;
    }
    char *src = argv[1];
    char *dest = argv[2];

    if (access(src, R_OK) != 0) {
        perror("Помилка доступу до джерела (read)");
        return 1;
    }
    signal(SIGXFSZ, handle_fsize_error);
    FILE *f_src = fopen(src, "rb");
    FILE *f_dest = fopen(dest, "wb");

    if (!f_src || !f_dest) {
        perror("Помилка відкриття файлів");
        if (f_src) fclose(f_src);
        return 1;
    }
    char buffer[4096];
    size_t bytes;
    printf("Копіювання %s -> %s...\n", src, dest);

    while ((bytes = fread(buffer, 1, sizeof(buffer), f_src)) > 0) {
        if (fwrite(buffer, 1, bytes, f_dest) != bytes) {
            break;
        }
    }

    printf("Копіювання завершено успішно.\n");

    fclose(f_src);
    fclose(f_dest);
    return 0;
}
