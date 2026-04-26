#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int safe_write_with_crash(const char *filename, const char *data, int simulate_crash) {
    char temp_filename[256];
    snprintf(temp_filename, sizeof(temp_filename), "%s.tmp", filename);

    int fd = open(temp_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Помилка відкриття тимчасового файлу");
        return -1;
    }

    size_t len = strlen(data);
    size_t half_len = len / 2;

    write(fd, data, half_len);
    printf("  -> Записано першу половину даних у %s...\n", temp_filename);

    if (simulate_crash) {
        printf("  [!] КРИТИЧНА ПОМИЛКА! Збій системи під час запису!\n");
        close(fd);
        return -1; // Програма перериває запис
    }

    write(fd, data + half_len, len - half_len);
    printf("  -> Записано другу половину даних.\n");

    fsync(fd);
    close(fd);

    if (rename(temp_filename, filename) < 0) {
        perror("Помилка перейменування");
        return -1;
    }
    
    return 0;
}

void print_file_content(const char *filename) {
    char buffer[256] = {0};
    int fd = open(filename, O_RDONLY);
    if (fd >= 0) {
        read(fd, buffer, sizeof(buffer) - 1);
        printf("Вміст файлу '%s': %s\n", filename, buffer);
        close(fd);
    } else {
        printf("Файл '%s' не існує.\n", filename);
    }
}

int main() {
    const char *filename = "important_data.txt";

    printf("=== ЕТАП 1: Створення початкового файлу ===\n");
    safe_write_with_crash(filename, "СТАРІ ДАНІ (ВАЖЛИВІ)", 0);
    print_file_content(filename);
    printf("\n");

    printf("=== ЕТАП 2: Спроба оновлення зі ЗБОЄМ ===\n");
    safe_write_with_crash(filename, "НОВІ ДАНІ, ЯКІ МАЮТЬ ЗАМІНИТИ СТАРІ", 1);
    
    printf("\nПісля збою перевіряємо оригінальний файл:\n");
    print_file_content(filename); 
    printf("Висновок: Цілісність збережено! Пошкоджено лише тимчасовий файл.\n\n");

    printf("=== ЕТАП 3: Успішне оновлення ===\n");
    safe_write_with_crash(filename, "НОВІ ДАНІ (Успішно записані)", 0);
    print_file_content(filename);

    return 0;
}
