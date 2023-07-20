#include <stdio.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 // The maximum size that a file's content can be

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a filename as an argument.\n");
        return 1;
    }

    char *filename = argv[1]; // filename is now the first command line argument

    // Declare a file pointer
    FILE *file;

    // This will now be an array of character arrays, or an array of strings.
    // This allows us to store each line of the file as a separate string.
    char content[MAX_FILE_SIZE][MAX_FILE_SIZE];
    int i = 0;

    file = fopen(filename, "rt"); // Open the file in read mode

    if (file == NULL) {
        printf("Could not open file\n");
    }
    else {
        char line[MAX_FILE_SIZE]; // Buffer to hold each line read from the file

        // Read each line from the file until EOF is reached
        while ((fgets(line, sizeof(line), file)) != NULL && i < MAX_FILE_SIZE - 1) {
            strcpy(content[i], line); // Copy each line into the content array
            i++;
        }
        printf("\nThe file has %d lines. \n\n", i); //Prints the number of lines on a file
        content[i][0] = '\0'; // End the final line with a null character
        fclose(file); // Close the file
    }
    // Loop through each line of content and print it
    for (int j = 0; j < i; j++) {
        printf("[%d] %s", j + 1, content[j]);
    }

    printf("\n\nEnter new text to add to the file (or just hit enter to leave the file unchanged): \n");
    char input[MAX_FILE_SIZE]; // Buffer to hold user input
    fgets(input, sizeof(input), stdin); // Get user input
    input[strlen(input) - 1] = '\0'; // Remove the newline character from user input

    strcat(content[i-1], input); // Add user input to the last line of content

    file = fopen(filename, "w"); // Open the file in write mode
    if (file != NULL) {
        // Loop through each line of content and write it to the file
        for (int j = 0; j < i; j++) {
            fputs(content[j], file);
        }
        fclose(file); // Close the file
    } else {
        printf("Could not open file for writing\n");
    }
    
    return 0;
}
