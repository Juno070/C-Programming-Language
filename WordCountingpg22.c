#include <stdio.h> // Include the standard input/output library for handling input and output operations
#include <ctype.h>  // For isspace() function from the character classification and transformation library

// Executable version
int main() {
    int c;              // Variable to store the current character
    int inWord = 0;     // Flag to indicate if we are inside a word
    int wordCount = 0;  // Counter for words

    printf("Enter text (Ctrl+D to end):\n");  // Prompt the user for input

    // Loop to read characters until EOF is encountered
    while ((c = getchar()) != EOF) {
        if (isspace(c)) {
            // If the character is a whitespace (space, tab, newline)
            inWord = 0;  // Set the flag to indicate we are outside a word
        } else {
            if (!inWord) { // ! negates a single value (e.g., !inWord means "if inWord is false" or "if inWord is zero")
                // If the previous character was whitespace and current is not
                wordCount++;  // Increment the word count
                inWord = 1;   // Set the flag to indicate we are inside a word
            }
        }
    }

    // Print the total word count
    printf("Total words: %d\n", wordCount);
    return 0;  // Indicate successful program termination
}
