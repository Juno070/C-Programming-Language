<<<<<<< HEAD
=======
// EXERCISE 1.5.1 File Copying pg.18
#include <stdio.h> // Include the library for standard input/ output

char str[] = "Hello, World!";  // Simulated input string
int i = 0; // String starting index

while (str[i] != '\0') {  // Loop until null terminator
      putchar(str[i]);     // Print each character
      i++; // Iterate through the string indexes
}
putchar('\n');  // Print a newline at the end

// Executable version
>>>>>>> master
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
