#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main() {
    FILE *file = fopen("Retail_Transaction.csv", "r");
    if (!file) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE];

    while (fgets(line, MAX_LINE, file)) {
        char *lineCopy = strdup(line);
        char *token = strtok(line, ",");
        int column = 0;
        int isBooks = 0;

        while (token) {
            if (column == 6) { // Assuming ProductCategory is the 7th column
                if (strcmp(token, "Books") == 0) {
                    isBooks = 1;
                }
            }
            token = strtok(NULL, ",");
            column++;
        }

        if (isBooks) {
            printf("%s", lineCopy);
        }

        free(lineCopy);
    }

    fclose(file);

    return 0;
}