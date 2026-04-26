#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int filter(const struct dirent *e) { return e->d_type == DT_DIR; }

int main() {
    struct dirent **list;
    int n = scandir(".", &list, filter, alphasort);
    for (int i = 0; i < n; i++) {
        printf("%s\n", list[i]->d_name);
        free(list[i]);
    }
    free(list);
    return 0;
}
