#include <stdio.h> // Include the standard input/output header file for input/output operations

#define TAB_TO_SPACE_LIMIT 4 // Defines the number of spaces that the \t (tabs) will be replaced with in the input

int main() {
    int i; // Loop counter for spaces
    int character; // Variable to hold the current character

    printf("Enter multiple lines of text (Ctrl+D to end on Unix, Ctrl+Z to end on Windows):\n"); // Prompt the user for input
    
    printf("\n"); //Insert a new line
    
    // Read characters until EOF (End of File) is encountered
    while ((character = getchar()) != EOF) {
        if (character == '\t') { // Check if the character is a tab
            // Replace the tab with spaces
            for (i = 0; i <= TAB_TO_SPACE_LIMIT; ++i) { // Loop to print spaces
                putchar(' '); // Print a space character
            }
        } else {
            putchar(character); // Print the character as is if it's not a tab
        }
    }

    return 0; // Return 0 to indicate successful completion
}
