#include <stdio.h>  // Include the standard input/output library

int main() {
    int c;  // Declare an integer variable 'c' to store the input character
    int tab = 0;  // Initialize counter for tabs
    int space = 0;  // Initialize counter for spaces
    int newline = 0;  // Initialize counter for newlines

    printf("Type characters ('Enter' to process input. 'Ctrl+D' to exit processing):\n"); // Display a message to the user, explaining how to provide input

    while ((c = getchar()) != EOF) {  // Loop to read characters until EOF is encountered
        if (c == '\t') {  // Check if the character is a tab
            ++tab;  // Increment the tab counter
        } else if (c == ' ') {  // Check if the character is a space
            ++space;  // Increment the space counter
        } else if (c == '\n') {  // Check if the character is a newline
            ++newline;  // Increment the newline counter
        }
    }

    printf("The string you entered contains %d tabs, %d spaces, and %d new lines.\n", tab, space, newline); // Display the total number of tabs, spaces, and newlines counted
    return 0;  // Return 0 to indicate the program ended successfully
}
