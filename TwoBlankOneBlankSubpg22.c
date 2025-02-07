#include <stdio.h> // Include the standard input/ output library

// Executable version
int main() { // Program entry point
    int current; // Initialize variable to store the current character
    int previous = 0;  // Initialize 'previous' to 0 (indicating no space initially)

    printf("Enter text (Ctrl+D to end):\n"); // Display a message to the user, explaining how to provide input
    
    while ((current = getchar()) != EOF) { // Set the loop conditions, loop to read characters until EOF
        if (current == ' ') {  // Check if the current character is a space
            if (previous == 0) {  // If the previous character was not a space
                putchar(current);  // Print the space
                previous = 1;  // Set 'previous' to indicate a space was printed
            }
        } else {  // For non-space characters
            putchar(current);  // Print the current character
            previous = 0;  // Reset 'previous' since it's not a space
        }
    }

    return 0; // Return 0 to indicate successful execution
}
