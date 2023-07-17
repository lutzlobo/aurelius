#include <stdio.h>

int main() {
    FILE *file = fopen("test.txt", "r"); /*assigning a file to the variable file with file informations providede by the pointer FILE*/
    
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    char c;
    while ((c = fgetc(file)) != EOF ) { /*Loop for reading all each and all characters of the file until it reaches End Of File(EOF)*/
        printf("%c", c); /*printing the characters*/
    }
    printf("\n");
    fclose(file); /*closing the file that was open before on fopen for better management of system resources.*/
    return 0;
}