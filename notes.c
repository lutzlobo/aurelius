#include <stdio.h>

#define MAX_FILE_SIZE 1024

int main() {
    FILE *file;
    char content[MAX_FILE_SIZE];
    int i = 0;

    file = fopen("test.txt", "rt"); /*assigning a file to the variable file with file informations providede by the pointer FILE*/
    
    if (file == NULL) {
        printf("Could not open file \n");
    }
    else {
        char c;
        while ((c = fgetc(file)) != EOF && i < MAX_FILE_SIZE - 1) {
            content[i] = c;
            i++;
        }
        content[i] = '\0';
        fclose(file);
    }
    printf("%s", content);

    return 0;
}