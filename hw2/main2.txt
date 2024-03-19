#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char line[1000];

    inputFile = fopen("main2.c", "r");

    if (inputFile == NULL) {
        return 1;
    }

    outputFile = fopen("main2.txt", "w");

    if (outputFile == NULL) {
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        fputs(line, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
