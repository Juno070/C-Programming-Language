#include <stdio.h> // Include the standard input/output library for functions like getchar() and printf()
#include <stdbool.h> // Include the boolean library for using boolean data type
#include <string.h> // Include the string library for functions like memset() and strncpy()
#include <ctype.h> // Include the character type library for functions like isspace()


#define ARRAY_SIZE 10 // Define the size of the array to store characters
#define NULL_TERMINATE_INDEX 9 // Define the index at which to null-terminate the array
#define WHITESPACE_PERCENTAGE_THRESHOLD 80 // Define the percentage threshold for whitespace characters

bool whitespaceThreshold(char c) { // Function to check if the whitespace threshold has been exceeded
    // Static variables to keep track of whitespace and non-whitespace characters
    static int whitespace_count = 0;
    static int non_whitespace_count = 0;

    if (isspace(c)) { // If the character is a whitespace, increment the whitespace count
        ++whitespace_count;
    } 
    else if (c != EOF) { // If the character is not a whitespace and not EOF, increment the non-whitespace count
        ++non_whitespace_count;
    } 
    else if (c == EOF) { // If the character is EOF, reset the counts
        whitespace_count = 0;
        non_whitespace_count = 0;
    }
    float percentage = ((float)whitespace_count / (whitespace_count + non_whitespace_count)) * 100; // Calculate the percentage of whitespace characters

    return (percentage > WHITESPACE_PERCENTAGE_THRESHOLD); // Return true if the percentage exceeds the threshold, false otherwise
}

int main() { // Main function
    char lines[ARRAY_SIZE] = {0}; // Array to store characters of a line
    char longestLine[ARRAY_SIZE] = {0}; // Array to store the longest line
    int character; // Variable to store the current character
    int index = 0; // Index to keep track of the current position in the lines array
    int characterCounter = 0; // Counter to keep track of the number of characters in the current line
    int longestlineLength = 0; // Variable to store the length of the longest line

    printf("Enter multiple lines of text (Ctrl+D to end on Unix, Ctrl+Z to end on Windows):\n"); // Print a prompt for the user to start entering multiple lines of text

    while ((character = getchar()) != EOF) { // Loop until the end of the input is reached (EOF)
        if (whitespaceThreshold(character)) { // Check if the whitespace threshold has been exceeded
            printf("The whitespace threshold has been exceeded.\n"); // If exceeded, print a message and break out of the loop
            break;
        }
        if (character != '\n') { // If the character is not a newline, increment the character counter and store the character
            ++characterCounter;
            if (index < NULL_TERMINATE_INDEX) { // Store the character in the lines array if there is space
                lines[index++] = character;
            } 
            else if (index == NULL_TERMINATE_INDEX) { // Null-terminate the lines array if it is full
                lines[NULL_TERMINATE_INDEX] = '\0';
            }
        }

        if (character == '\n') { // If the character is a newline, check if the current line is the longest
            if (characterCounter > longestlineLength) { // If the current line is longer than the longest line, update the longest line
                longestlineLength = characterCounter;
                memset(longestLine, 0, sizeof(longestLine)); // Clear the longestLine array
                strncpy(longestLine, lines, ARRAY_SIZE - 1); // Copy the current line to the longestLine array
                longestLine[ARRAY_SIZE - 1] = '\0'; // Null-terminate the longestLine array
            }
            // Reset the index and character counter for the next line
            index = 0;
            characterCounter = 0;
            memset(lines, 0, sizeof(lines)); // Clear the lines array for the next line
        }
    }
    if (longestlineLength > 0) { // Print the longest line if it is not empty
        printf("\nLongest line: %s\n", longestLine);
        printf("Length of the longest line: %d\n", longestlineLength);
    }
    return 0; // Return 0 to indicate successful execution
}
