#include <stdio.h>

int main() {
    FILE *in = popen("who", "r");
    FILE *out = popen("more", "w");
    char buf[256];
    if (!in || !out) return 1;
    while (fgets(buf, sizeof(buf), in)) fputs(buf, out);
    pclose(in); pclose(out);
    return 0;
}
