#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    FILE *fp;
    char line[512];
    uid_t my_uid = getuid();

    printf("--- Аналіз облікових записів ---\n");
    printf("Мій поточний UID: %d\n\n", my_uid);

    fp = popen("getent passwd", "r");
    if (fp == NULL) {
        perror("Помилка виконання getent");
        return 1;
    }

    printf("Інші звичайні користувачі (UID >= 1000):\n");
    int found = 0;

    while (fgets(line, sizeof(line), fp)) {
        char *user = strtok(line, ":");
        strtok(NULL, ":");
        char *uid_str = strtok(NULL, ":");
        
        if (uid_str != NULL) {
            int uid = atoi(uid_str);
            if (uid >= 1000 && uid != 65534 && uid != my_uid) {
                printf("👤 Користувач: %-15s | UID: %d\n", user, uid);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Інших звичайних користувачів не знайдено.\n");
    }

    pclose(fp);
    return 0;
}

