#include <stdio.h>
#include <dirent.h>
#include <string.h>

void walk(const char *path) {
    DIR *d = opendir(path);
    if (!d) return;
    struct dirent *e;
    while ((e = readdir(d))) {
        if (e->d_name[0] == '.') continue;
        printf("%s/%s\n", path, e->d_name);
        if (e->d_type == DT_DIR) {
            char next[512];
            snprintf(next, sizeof(next), "%s/%s", path, e->d_name);
            walk(next);
        }
    }
    closedir(d);
}

int main() { walk("."); return 0; }
