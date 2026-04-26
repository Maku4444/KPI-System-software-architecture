#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

int main() {
    DIR *d = opendir(".");
    struct dirent *e;
    while ((e = readdir(d))) {
        if (e->d_type == DT_REG) {
            printf("Видалити %s? (y/n): ", e->d_name);
            char c = getchar();
            if (c == 'y') unlink(e->d_name);
            while(getchar() != '\n');
        }
    }
    closedir(d);
    return 0;
}
