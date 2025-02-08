#include <stdio.h> // Include the standard input/output header file for input/output operations
#include <string.h> // Include the string header file for string manipulation functions
#include <stdlib.h> // Include standard library for memory management functions

#define ARRAY_ROW 200 // Define the maximum number of lines to read
#define ARRAY_COLUMN 200 // Define the maximum length of each line
#define MAX_LINES 170 // Define the maximum number of lines to process
#define MAX_CHARACTER_LENGTH 170 // Define the maximum number of characters in a line

int main() {
    char line[ARRAY_ROW] = {0}; // Array to hold the current line of input, initialized to zero
    char reversedLine[ARRAY_ROW] = {0}; // Array to hold the reversed version of the current line, initialized to zero
    char reversedLines[ARRAY_ROW][ARRAY_COLUMN] = {0}; // 2D array to hold all reversed lines, initialized to zero
    int lineCounter = 0; // Counter for the number of lines processed
    int rowCounter = 0; // Counter for the number of rows in reversedLines
    int stringLength; // Variable to hold the length of the current line
    int ii; // Index for the reversed line
    int i; // Index for iterating through the line

    printf("Enter multiple lines of text (Ctrl+D to end on Unix, Ctrl+Z to end on Windows):\n"); // Print a prompt for the user to start entering multiple lines of text

    // Read lines from standard input until EOF or an error occurs
    while (fgets(line, sizeof(line), stdin) != NULL) {
        ++lineCounter; // Increment the line counter for each line read
        stringLength = strlen(line); // Get the length of the current line

        // Check if the maximum number of lines has been reached
        if (lineCounter == MAX_LINES) { // If lineCounter reaches the limit
            break; // Exit the loop if the limit is reached
        }
        
        // Check if the line is empty or contains only whitespace
        if (strspn(line, " \t\n\r") == strlen(line)) { // Counts how many characters at the start of str1 are only in str2
            --lineCounter; // Decrement the line counter since this line is not valid
            continue; // Skip to the next iteration of the loop
        }

        // Check if the line exceeds the maximum character length
        if (stringLength >= MAX_CHARACTER_LENGTH) {
            line[MAX_CHARACTER_LENGTH] = '\0'; // Null terminate the line at the maximum length
        }
        else {
            // Remove the newline character from the end of the line
            line[strcspn(line, "\n")] = '\0'; // Find the newline character and replace it with a null terminator
        }

        // Reverse the current line
        for (i = strlen(line) - 1, ii = 0; i >= 0; i--, ii++) {
            reversedLine[ii] = line[i]; // Copy characters from the end of line to the beginning of reversedLine
        }
        reversedLine[ii] = '\0'; // Null terminate the reversed line

        // Copy the reversed line into the array of reversed lines
        strncpy(reversedLines[rowCounter++], reversedLine, MAX_CHARACTER_LENGTH); // Store the reversed line and increment rowCounter

        // Clear the reversedLine array for the next iteration
        memset(reversedLine, 0, ARRAY_ROW); // Set all characters in reversedLine to zero
    }

    // Print the total number of lines processed
    printf("\n%d lines were processed\n", lineCounter);
    
    // Print each reversed line
    for (i = 0; i < rowCounter; i++) {
        printf("%s\n", reversedLines[i]); // Output each reversed line
    }

    // Clear the reversedLines array
    for (int i = 0; i < rowCounter; i++) { // Iterate over each row in the array
        memset(reversedLines[i], 0, MAX_CHARACTER_LENGTH); // Set all characters in the current row to zero
    }
    
    // Reset counters for potential future use
    rowCounter = 0; // Reset the row counter
    lineCounter = 0; // Reset the line counter
    return 0; // Return 0 to indicate successful completion
}
