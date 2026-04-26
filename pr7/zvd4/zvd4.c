#include <stdio.h>

int main(int argc, char *argv[]) {
    char line[256];
    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        int count = 0;
        while (fgets(line, sizeof(line), f)) {
            printf("%s", line);
            if (++count % 20 == 0) {
                printf("-- Натисніть Enter --");
                getchar();
            }
        }
        fclose(f);
    }
    return 0;
}
