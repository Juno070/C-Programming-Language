#include <stdio.h> // Include the standard input/output library for handling input and output operations
#include <ctype.h> // Include the character classification and transformation library

// Executable version
int main() {
    int increment;
    int isdigit[10];
    for (increment = 0; increment < 10; ++increment) {
        isdigit[increment] = 0; // Initialize the isdigit array values to zero
    }

    int character;
    int istab = 0;
    int isspaceCount = 0;  
    int isnewline = 0;
    int ispunctCount = 0;  
    int isalphabet = 0;

    printf("Enter text (Ctrl+D to end):\n");  // Prompt the user for input
    
    while ((character = getchar()) != EOF) {
        if (character >= '0' && character <= '9') { // Check if the character is a digit, ASCII 0 - 9 Numerical Values: 48 = 0, 49 = 1, 50 = 2, 51 = 3, 52 = 4, 53 = 5, 54 = 6, 55 = 7, 56 = 8, 57 = 9
            ++isdigit[character - '0']; // Increment the count for the corresponding digit, ++isdigit[character - '0'] == ++isdigit[character - 48] == ++isdigit[53 - 48] == ++isdigit[5]
        } else if (islower(character) || isupper(character)) { // Check if the character is a letter
            ++isalphabet;
        } else if (ispunct(character)) { // Check if the character is a punctuation mark
            ++ispunctCount;
        } else if (character == ' ') { // Check if the character is a space
            ++isspaceCount;
        } else if (character == '\t') { // Check if the character is a tab
            ++istab;
        } else if (character == '\n') { // Check if the character is a newline (corrected syntax)
            ++isnewline;
        }
    }

    printf("digits =");
    for (increment = 0; increment < 10; ++increment) {
        printf(" %d:%d", increment, isdigit[increment]); // Print the count of each digit
    }
    printf(", alphabet = %d, punctuation = %d, space = %d, tab = %d, new line = %d\n", isalphabet, ispunctCount, isspaceCount, istab, isnewline);
    return 0;
}
