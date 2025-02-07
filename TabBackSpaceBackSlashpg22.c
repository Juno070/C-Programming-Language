#include <stdio.h>  // Include the standard input/output library for handling input and output operations

// Function to handle the backspace character
int handle_backspace(int character) {
    if (character == '\b') {  // Check if the current character is a backspace
        printf("\\b");        // Print a visible representation of the backspace character
        return 0;             // Return 0 to indicate that the backspace was handled
    }
    return -1;                // Return -1 to indicate that the character is not a backspace
}

// Function to handle other special characters
void handle_special_character(int character) {
    if (character == '\t') {         // Check if the current character is a tab
        printf("\\t");               // Print a visible representation of the tab character
    } else if (character == ' ') { // Check if the current character is a space
        printf("\\s");              // Print a visible representation of the space character
    } else if (character == '\\') { // Check if the current character is a backslash
        printf("\\\\");              // Print a visible representation of the backslash character
    } else {                         // If the character is neither a tab nor a backslash
        putchar(character);          // Print the character as-is to the output
    }
}

int main() {
    int character;  // Declare a variable to store the current character being read

    // Print a prompt for the user to enter text
    printf("Enter text (Ctrl+D to end):\n");

    // Loop to read characters from the input until the end-of-file (EOF) is encountered
    while ((character = getchar()) != EOF) {
        // Call the handle_backspace function to process the character
        if (handle_backspace(character) == 0) { 
            continue;  // If the backspace was handled, skip the rest of the loop iteration
        }

        // Call the handle_special_character function to process other special characters
        handle_special_character(character);  
    }

    return 0;  // Return 0 to indicate successful program execution
}
