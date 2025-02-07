#include <stdio.h>  // Include the standard input/output library

int main() {
    int c;  // Declare an integer variable 'c' to store the character input
    printf("End of File (EOF) value at start: %d\n", EOF); // Print the value of EOF at the beginning
    printf("Type characters (Ctrl+D or Ctrl+Z to end): ");  // Prompt the user to enter characters

    while ((c = getchar()) != EOF) {  // Loop to read characters until EOF is encountered
          printf("\n");
          putchar(c);  // Output the character read
    }
    printf("Loop terminated.\n"); // Termination message
    printf("End of File (EOF) value at end: %d\n", EOF); // Print the value of EOF at the end of input
    return 0;  // Return 0 to indicate the program ended successfully
}
