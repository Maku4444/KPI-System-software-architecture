#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    DIR *d = opendir(".");
    struct dirent *e;
    while ((e = readdir(d))) {
        if (strstr(e->d_name, ".c")) {
            printf("Надати доступ до %s? (y/n): ", e->d_name);
            if (getchar() == 'y') chmod(e->d_name, 0644);
            while(getchar() != '\n');
        }
    }
    closedir(d);
    return 0;
}
