#include <stdio.h>
#include <string.h>

int main() {
    FILE *inputFile, *outputFile;
    char line[1000];
    int lineNumber = 0;
    int found = 0;

    inputFile = fopen("main3.c", "r");

    if (inputFile == NULL) {
        return 1;
    }

    outputFile = fopen("main3.txt", "w");

    if (outputFile == NULL) {
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        lineNumber++;

        if (strstr(line, "int main()") != NULL) {
            fprintf(outputFile, "%d\n", lineNumber);
            found = 1;
            break;
        }
    }

    if (!found) {
        fprintf(outputFile, "%d\n", -1);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
