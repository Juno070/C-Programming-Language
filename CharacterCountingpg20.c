#include <stdio.h>  // Include the standard input/output library

// Using a 'for' loop
int main() {
    int c;  // Declare an integer variable 'c' to store the input character
    int counter = 0;  // Initialize a counter to zero to count characters

    printf("Type characters ('Enter' to process input. 'Ctrl+D' to exit processing): ");  
    // Display a message to the user, explaining how to provide input

    for (c = getchar(); c != EOF; c = getchar()) {  // Loop to read characters, process each, and check for EOF
        ++counter;  // Increment the counter for each character read
    }
    counter--; // Decrement the final counter value by one to exclude the EOF character (-1) from the count
    printf("This string is %d characters long\n", counter);  
    // Display the total number of characters counted
    return 0;  // Return 0 to indicate the program ended successfully
}
