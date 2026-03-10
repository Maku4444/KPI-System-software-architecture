#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int main() {
    // 1. Отримуємо розмір сторінки системи (зазвичай 4096 байт)
    long page_size = sysconf(_SC_PAGESIZE);
    
    // 2. Виділяємо 3 сторінки пам'яті
    void *pages = mmap(NULL, 3 * page_size, PROT_READ | PROT_WRITE, 
                       MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (pages == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Розділяємо вказівники
    char *guard_start = (char *)pages;
    char *buffer_page = (char *)pages + page_size;
    char *guard_end   = (char *)pages + (2 * page_size);

    // 3. Встановлюємо сторожові сторінки 
    if (mprotect(guard_start, page_size, PROT_NONE) != 0 ||
        mprotect(guard_end, page_size, PROT_NONE) != 0) {
        perror("mprotect");
        return 1;
    }

    printf("Сторінки налаштовані:\n");
    printf("  [Guard Start] %p (PROT_NONE)\n", guard_start);
    printf("  [Buffer Page] %p (PROT_READ|WRITE)\n", buffer_page);
    printf("  [Guard End]   %p (PROT_NONE)\n\n", guard_end);

    printf("Спроба запису в робочу область... ");
    strcpy(buffer_page, "Привіт");
    printf("Успішно: %s\n", buffer_page);

    printf("Спроба виходу за межі (запис у Guard End)...\n");
    
    guard_end[0] = 'X'; 

    printf("Цей рядок ніколи не буде надрукований.\n");

    return 0;
}
