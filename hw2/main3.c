#include <stdio.h>

int main() {
    FILE *fp = fopen(__FILE__, "r");
    if (fp == NULL) {
        printf("無法打開文件");
        return 1;
    }

    char line[100];
    int line_num = 0;
    while (fgets(line, sizeof(line), fp)) {
        line_num++;
        if (strstr(line, "int main()")) {
            printf("%d\n", line_num);
            break;
        }
    }

    fclose(fp);
    return 0;
}
