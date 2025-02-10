#include <stdio.h> // Include the standard input-output library to use functions like printf and getchar

#define SPACE_TO_TAB_LIMIT 4 // Define a constant that specifies how many spaces will be replaced by a single tab

int main() { // Start of the main function, which is the entry point of the program
    int increment; // Declare an integer variable 'increment' (not used in this code)
    int character; // Declare an integer variable 'character' to store the ASCII value of the input character
    int spaceCounter = 0; // Initialize a counter to keep track of the number of consecutive spaces encountered

    // Prompt the user to enter multiple lines of text and inform them how to end input
    printf("Enter multiple lines of text and then use 'Enter' to properly execute the code then, (Ctrl+D to end on Unix, Ctrl+Z to end on Windows):\n");
    
    // Start a loop that continues until the end of file (EOF) is reached
    while ((character = getchar()) != EOF) { // Read a character from standard input and check if it is not EOF
        // Check if the character read is a space
        if (character == ' ') {
            ++spaceCounter; // Increment the space counter for each space encountered
        } else { // If the character is not a space
            // While there are enough spaces to replace with a tab
            while (spaceCounter >= SPACE_TO_TAB_LIMIT) {
                putchar('\t'); // Output a tab character to replace the counted spaces
                spaceCounter -= SPACE_TO_TAB_LIMIT; // Decrease the space counter by the number of spaces replaced by the tab
            }

            // While there are remaining spaces that couldn't be replaced by a tab
            while (spaceCounter > 0) {
                putchar(' '); // Output a space character for each remaining space
                --spaceCounter; // Decrement the space counter
            }

            // Output the current non-space character
            putchar(character); // Print the character that was read (which is not a space)
        }
    }

    return 0; // Return 0 to indicate that the program finished successfully
}
