#include <stdio.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 // Maximum number of lines

int main(int argc, char *argv[]) {
    // Check if a filename was provided
    if (argc < 2) {
        printf("Please provide a filename as an argument.\n");
        return 1;
    }

    char *filename = argv[1]; // The first argument is the filename
    FILE *file; // File pointer
    char content[MAX_FILE_SIZE][MAX_FILE_SIZE]; // 2D array to hold the content of the file
    int i = 0; // Counter for the number of lines

    // Open the file in read mode
    file = fopen(filename, "rt");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Could not open file\n");
    }
    else {
        // Read the file line by line into the 2D array 'content'
        while (fgets(content[i], sizeof(content[i]), file) != NULL && i < MAX_FILE_SIZE - 1) {
            i++; // Increment the line counter
        }
        printf("\nThe file has %d lines. \n\n", i); // Output the number of lines

        // Close the file
        fclose(file);
    }

    // Print the content of the file
    for (int j = 0; j < i; j++) {
        printf("[%d] %s", j + 1, content[j]);
    }

    // Ask the user for the line number to append text to
    printf("\n\nLine number to append: ");
    int lineNum;
    scanf("%d", &lineNum);
    getchar(); // Clear the input buffer

    // Ask the user for the text to append
    printf("Text to append: \n");
    char appendText[MAX_FILE_SIZE];
    fgets(appendText, sizeof(appendText), stdin);

    // Check if the last character is a newline
    size_t len = strlen(appendText);
    if (len > 0 && appendText[len - 1] == '\n') {
        appendText[len - 1] = '\0'; // remove the newline
    }

    // Check if the line number is valid
    if (lineNum > 0 && lineNum <= i+1) {
        // Shift all lines down
        for (int j = i; j > lineNum; j--) {
            strcpy(content[j], content[j-1]);
        }
        // Replace the next line after selected line with the new text
        strcpy(content[lineNum], appendText);
        strcat(content[lineNum], "\n"); // Add newline at the end

        i++; // increment the line count
    } else {
        printf("Invalid line number. \n");
    }

    // Open the file in write mode
    file = fopen(filename, "w");
    if (file != NULL) {
        // Write the modified content back to the file
        for (int j = 0; j < i; j++) {
            fputs(content[j], file);
        }
        fclose(file); // Close the file
    } else {
        printf("Error \n");
    }
    return 0;
}
