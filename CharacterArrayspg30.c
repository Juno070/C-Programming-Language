// Include the standard input/output header file for input/output operations
#include <stdio.h>

// Include the boolean header file for boolean data type
#include <stdbool.h>

// Include the string header file for string manipulation functions
#include <string.h>

// Define a constant for the maximum allowed length of a text line
#define TEXT_LINE_LIMIT 100

// Define a constant for the maximum allowed length of a character string
#define MAX_CHARACTER_LENGTH 100

// Function to check if a 2D array has any non-null data
// Returns true if any row in the array has a non-null character, false otherwise
bool hasData(char arr[][MAX_CHARACTER_LENGTH], int rows) {
    // Iterate over each row in the array
    for (int i = 0; i < rows; ++i) {
        // Check if the first character of the current row is non-null
        if (arr[i][0] != '\0') {
            // If a non-null character is found, return true immediately
            return true;
        }
    }
    // If no non-null characters are found, return false
    return false;
}

// Function to clear a 2D array by setting all elements to null characters
void clearArray(char arr[][MAX_CHARACTER_LENGTH], int rows) {
    // Iterate over each row in the array
    for (int i = 0; i < rows; ++i) {
        // Use the memset function to set all characters in the current row to null
        memset(arr[i], 0, MAX_CHARACTER_LENGTH);
    }
}


// Function to truncate strings longer than 100 characters and add null termination
void truncateString(char* str) {
    // Check if the length of the string is greater than the maximum allowed length minus 1
    if (strlen(str) > MAX_CHARACTER_LENGTH - 1) {
        // If the string is too long, force null termination by setting the last character to null
        str[MAX_CHARACTER_LENGTH - 1] = '\0';
    }
}

int main() {
    // Declare a character array to store the current line being read from stdin
    char lines[MAX_CHARACTER_LENGTH];

    // Declare a 2D character array to store the longest lines read from stdin
    char longestLines[TEXT_LINE_LIMIT][MAX_CHARACTER_LENGTH];

    // Initialize counters for the number of rows and lines
    int rowCounter = 0;
    int lineCounter = 0;

    // Initialize a variable to store the maximum length of a line
    int maxLength = 0;

    // Initialize the longestLines array by setting all elements to null
    clearArray(longestLines, TEXT_LINE_LIMIT);

    // Print a prompt for the user to start entering multiple lines of text
    printf("Enter multiple lines of text (Ctrl+D to end on Unix, Ctrl+Z to end on Windows):\n");

    // Read lines from stdin until the end of the input is reached or the line limit is reached
    while (fgets(lines, sizeof(lines), stdin) != NULL && lineCounter < TEXT_LINE_LIMIT) {
        // Increment the line counter
        ++lineCounter;

        // Remove the newline character from the end of the line if present
        size_t currentLength = strlen(lines);
        if (lines[currentLength - 1] == '\n') {
            // Replace the newline character with a null character
            lines[currentLength - 1] = '\0';
            // Decrement the length of the line
            --currentLength;
        }

        // Truncate the line if it is longer than the maximum allowed length
        truncateString(lines);
        // Update the length of the line after truncation
        currentLength = strlen(lines);

        // Check if the current line is longer than the previous longest line
        if (currentLength > maxLength) {
            // If the current line is longer, update the maximum length and clear the longestLines array
            maxLength = currentLength;
            clearArray(longestLines, TEXT_LINE_LIMIT);
            // Reset the row counter and add the current line to the longestLines array
            rowCounter = 0;
            strncpy(longestLines[rowCounter++], lines, MAX_CHARACTER_LENGTH);
        } else if (currentLength == maxLength) {
            // If the current line is as long as the previous longest line, add it to the longestLines array
            if (rowCounter < TEXT_LINE_LIMIT) {
                strncpy(longestLines[rowCounter++], lines, MAX_CHARACTER_LENGTH);
            }
        }
    }

    // Check if the line limit was reached
    if (lineCounter == TEXT_LINE_LIMIT) {
        // If the line limit was reached, print a message indicating that the program will not read beyond the limit
        printf("Input line limit reached. Program will not read beyond one hundred lines.\n");
    }


// Check if any valid input was provided
if (hasData(longestLines, TEXT_LINE_LIMIT)) {
    // If valid input was provided, print the number of lines read
    printf("\nThe program read %d lines of input.\n", lineCounter);

    // Print the length of the longest line
    printf("The longest line was %d characters long.\n", maxLength);

    // Print a header for the longest lines
    printf("Longest line(s):\n");

    // Iterate over the longest lines and print each one
    for (int i = 0; i < rowCounter; ++i) {
        // Print the line number and the line itself
        printf("Longest line %d: %s\n", i + 1, longestLines[i]);
    }
} else {
    // If no valid input was provided, print a message indicating that
    printf("No valid input was provided.\n");
}

// Return an integer value indicating the program's exit status (0 indicates successful execution)
return 0;
}
