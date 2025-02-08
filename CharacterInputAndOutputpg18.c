// EXERCISE 1.5 Character Input and Output pg.18
#include <stdio.h>

int input = 'O'; // Simulate input by hardcoding a character
printf("Character: %c, ASCII: %d\n", input, input); // Prints both the character and its ASCII value
fflush(stdout); // Ensure immediate output. This can be particularly useful when you want to make sure that all previous outputs are displayed before proceeding with further operations.

// Executable version
#include <stdio.h> // Library for standard input and output

int main() { // Program's entry point
    int input; // Setting the variable's data type
    printf("Enter a single character (Ctrl+D or Ctrl+Z to end): "); // Prompt user to enter a character
    input = getchar(); // Read a character from stdin
    printf("You entered: %c (ASCII: %d)\n", input, input); // Print the character and its ASCII value
    return 0; // Program's exit status
}
