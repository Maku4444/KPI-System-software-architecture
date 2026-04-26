#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Спроба прочитати /etc/shadow від імені адміністратора...\n");
    printf("(Можливо, доведеться ввести пароль sudo)\n\n");
    
    int status = system("sudo cat /etc/shadow | head -n 5");
    
    if (status == -1) {
        perror("Помилка системного виклику");
    }
    
    return 0;
}
