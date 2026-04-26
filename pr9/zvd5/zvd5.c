#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main() {
    const char *file = "test_permissions.txt";

    printf("1. Створення файлу...\n");
    system("touch test_permissions.txt");

    printf("2. Зміна власника на root та встановлення прав (chmod 600)...\n");
    system("sudo chown root:root test_permissions.txt");
    system("sudo chmod 600 test_permissions.txt");

    printf("3. Програмна перевірка доступу:\n");
    
    if (access(file, R_OK) == 0) {
        printf(" [v] Доступ на читання: ДОЗВОЛЕНО\n");
    } else {
        printf(" [x] Доступ на читання: ВІДМОВЛЕНО\n");
    }

    if (access(file, W_OK) == 0) {
        printf(" [v] Доступ на запис: ДОЗВОЛЕНО\n");
    } else {
        printf(" [x] Доступ на запис: ВІДМОВЛЕНО\n");
    }

    printf("4. Очищення системи...\n");
    system("sudo rm -f test_permissions.txt");
    return 0;
}
