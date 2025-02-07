#include <stdio.h> // Standard input and output library

int main() { // Program's entry point
    int c; // Data type of 'c'
    printf("Type characters (Ctrl+D or Ctrl+Z to end): "); // Prompt the user to provide a string as input
    c = getchar(); // Reads one character at a time from the standard input
    while (c != EOF) { // Continue reading until EOF
          putchar(c); // Output the current character to the terminal
          putchar('\n'); //  Outputs a newline after every character
          c = getchar(); // Gets the next character to feed back into the loop
    }
    return 0; // Program exit status
}
