#include <stdio.h> // Library for standard input and output

int main() { // Program's entry point
    int input; // Setting the variable's data type
    printf("Enter a single character (Ctrl+D or Ctrl+Z to end): "); // Prompt user to enter a character
    input = getchar(); // Read a character from stdin
    printf("You entered: %c (ASCII: %d)\n", input, input); // Print the character and its ASCII value
    return 0; // Program's exit status
}
