#include <stdio.h>
#include <string.h>

//Define a maximum file size constant
#define MAX_FILE_SIZE 1024

//Start of the program
int main() {
    //Declare a pointer to a FILE structure
    FILE *file;

    //Declare an array to hold the file content
    char content[MAX_FILE_SIZE];
    int i = 0;

    //Open the file in read mode
    file = fopen("test.txt", "rt");

    //Check if the file was opened successfully
    if (file == NULL) {
        printf("Could not open file \n");
    }
    else {
        //If the file was opened successfully, read its content
        char c;
        while ((c = fgetc(file)) != EOF && i < MAX_FILE_SIZE - 1) {
            content[i] = c;
            i++;
        }
        //Terminate the string with a null character
        content[i] = '\0';

        //Close the file after reading its content
        fclose(file);
    }

    //Print the current content of the file
    printf("%s", content);

    //Prompt the user to enter new text
    printf("Enter new text to add to the file (or just hit enter to leave the file unchanged) \n");
    
    //Declare an array to hold the user's input
    char input[MAX_FILE_SIZE]; 

    //Get the user's input
    fgets(input, sizeof(input), stdin);

    //Remove the newline character added by fgets()
    input[strlen(input) - 1] = '\0'; 

    //Append the user's input to the content
    strcat(content, input); 

    //Open the file in write mode to update its content
    file = fopen("test.txt", "w");

    //Check if the file was opened successfully
    if (file != NULL) {
        //Write the new content to the file
        fputs(content, file); 
        
        //Close the file after writing the new content
        fclose(file);
    } else {
        printf("Could not open file for writing \n");
    }
    return 0;
}
