#include <stdio.h>

int main() {
    FILE *file, *outputFile;
    char filename[] = __FILE__;
    char c;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("无法打开文件 %s.\n", filename);
        return 1;
    }

    outputFile = fopen("main2.txt", "w");
    if (outputFile == NULL) {
        printf("无法创建输出文件.\n");
        return 1;
    }

    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
        fputc(c, outputFile);
    }

    fclose(file);
    fclose(outputFile);

    return 0;
}
