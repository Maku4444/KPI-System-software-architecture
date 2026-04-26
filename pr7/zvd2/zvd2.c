#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main() {
    DIR *d = opendir(".");
    struct dirent *de;
    struct stat s;
    while ((de = readdir(d))) {
        stat(de->d_name, &s);
        printf((S_ISDIR(s.st_mode)) ? "d" : "-");
        printf("%o %ld %s\n", s.st_mode & 0777, s.st_size, de->d_name);
    }
    closedir(d);
    return 0;
}
