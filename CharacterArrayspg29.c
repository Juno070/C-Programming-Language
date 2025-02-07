#include <stdio.h>  // Include the standard input and output library for functions like printf and fgets
#include <string.h> // Include the string handling library for functions like strlen and strcpy

int main() {
    char lines[500];         // Array to hold the current line of input (up to 199 characters + 1 for null terminator)
    char selectedLines[500]; // Array to store the longest line encountered so far
    int length = 0;          // Variable to store the length of the longest line found

    // Prompt the user to enter multiple lines of text
    printf("Enter multiple lines of text (Ctrl+D to end on Unix, Ctrl+Z to end on Windows):\n");

    // Loop to read each line of input until the end-of-file (EOF) is reached
    while (fgets(lines, sizeof(lines), stdin) != NULL) {
        // Check if the length of the current line is greater than the stored longest line
        int currentLength = strlen(lines);
        if (currentLength > length) {
           length = currentLength;     // Update the length of the longest line
           strcpy(selectedLines, lines); // Copy the current line into selectedLines
        }
    }
    
    // If the longest line ends with a newline character, remove it 
    if (length > 0 && selectedLines[length - 1] == '\n') { 
       selectedLines[length - 1] = '\0'; // Replace the newline character with a null terminator 
       length--; // Adjust the length to exclude the newline character
    }

    // Output the longest line and its length, if valid input exists
    if (length > 0) {
       printf("\nThe longest line is: \"%s\". This line is %d characters long.\n", selectedLines, length);
    } else {
        printf("\nNo valid lines were entered.\n");
    }

    return 0; // Indicate successful program termination
}
