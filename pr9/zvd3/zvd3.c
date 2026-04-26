#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("1. Створюємо файл від імені звичайного користувача...\n");
    system("touch my_user_file.txt");

    printf("2. Копіюємо файл від імені root у домашній каталог...\n");
    system("sudo cp my_user_file.txt root_copy.txt");

    printf("3. Спроба змінити файл root_copy.txt...\n");
    system("echo 'hack' >> root_copy.txt");

    printf("\n4. Спроба видалити файл root_copy.txt (додано -f, щоб обійти інтерактивний запит)...\n");
    system("rm -f root_copy.txt");
    printf("Файл успішно видалено!\n");

    system("rm -f my_user_file.txt");
    return 0;
}
