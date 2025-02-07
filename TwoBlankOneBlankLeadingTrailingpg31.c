#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ARRAY_ROW 200 // Define the size of the array row to store characters
#define ARRAY_COLUMN 200 // Define the size of the array column to store characters
#define MAX_CHARACTER_LENGTH 50 // Define a constant for the maximum allowed length of a character string

void trimWhitespace(char *str) { 
    int i;
    int indexOne = 0;
    int indexTwo = 0; 
    // Trim leading whitespace 
    while (isspace((unsigned char)str[indexOne])) { // As long as the character at index for 'indexOne' is whitespace, until a non-whitespace character is met
          indexOne++; // Iterate the index + 1
    } 

    // Trim inter-string whitespace
    while (str[indexOne] != '\0') { // Checks if the first non whitespace character for 'indexOne' and every character after that is not a null terminator
        if (!isspace((unsigned char)str[indexOne])) { // If not whitespace or iswhitespace = 0
            str[indexTwo++] = str[indexOne]; // str[i++] begins reading from the first non whitespace character, the first non whitespace character is moved to index zero, this function uses two indexes, one for identification 'indexOne' and the other for relocation 'indexTwo',it essentially relocates the characters and arranges them in the desired format
        }
        else if (isspace((unsigned char)str[indexOne]) && str[indexOne + 1] != '\0' && !isspace((unsigned char)str[indexOne + 1])) { // Ensures that only a single space is added whe>
            str[indexTwo++] = ' '; // Current index is equal to one space character
        }  
        indexOne++; // Iterate the index + 1
    } // Null-terminate the string 
    str[indexTwo] = '\0';

    // Trim trailing whitespace 
    i = strlen(str) - 1;  // Start from the last character
    while (i >= 0 && isspace((unsigned char)str[i])) {  
    i--;  // Move backwards through whitespace
    }
    str[i + 1] = '\0'; // Places a null terminator ('\0') at the position immediately after the last non-whitespace character, effectively removing all trailing whitespace
}

void truncateString(char *str) { // Function to truncate strings longer than 100 characters and add null termination
    int length = strlen(str);
    if (length >= MAX_CHARACTER_LENGTH) { // Check if the string length exceeds the maximum allowed length
        str[MAX_CHARACTER_LENGTH - 1] = '\0'; // Force null termination by setting the last character to null, minis one to counter the zero starting index
    } 
    else {
        str[strcspn(str, "\n")] = '\0'; // Find the first new line character in the string and replace with a null terminator
    }
}

int isBlankline(const char *str) { // Check if the line is empty or contains only whitespace
        if (str == NULL) {
            return 1; // Consider NULL as a blank line
        }
        if (strspn(str, " \t\n\r") == strlen(str)) {
            return 1; // It's a blank line, true
        } 
    return 0; // Not a blank line, false
}

int main() {
    char line[ARRAY_ROW] = {0}; // 'fgets()' stors input in this buffer and reads from this buffer, all values set to 0
    char lines[ARRAY_ROW][ARRAY_COLUMN] = {0}; // This 2D array stores all lines that 'fgets()' reads, all values set to 0
    int rowCounter = 0; // Counts the rows
    int lineCounter = 0; // Counts the lines

    printf("Enter multiple lines of text (Ctrl+D to end on Unix, Ctrl+Z to end on Windows):\n");
    
    while (fgets(line, sizeof(line), stdin) != NULL) { // 'while loop' condition, unlike getchar(), fgets reads entire strings
        ++lineCounter; // Count the line/ string
        
        if (isBlankline(line)) { // Checks if line is an empty string (strlen(line) == 0) OR line consists entirely of whitespace characters (strspn(line, " \t\n\r") == strlen(line)).
            --lineCounter; // Decrement the line counter to compensate for the empty line
            continue; // Skip the empty line using the 'continue' keyword
        }
        truncateString(line);
        trimWhitespace(line);
        
        strncpy(lines[rowCounter], line, MAX_CHARACTER_LENGTH - 1);
        lines[rowCounter][MAX_CHARACTER_LENGTH - 1] = '\0';  // Ensure null termination after the sring is copied
        rowCounter++;
    }
    printf("\n%d lines were processed.\n", lineCounter);
    
    for (int i = 0; i < rowCounter; i++) { // 'for loop' condition to iterate through the 'lines' array
        if (strlen(lines[i]) > 0) { // If the 'lines' row is not empty
            printf("%s\n",lines[i]); // Print the string
        }
    }
    // Clear stored lines
    for (int i = 0; i < rowCounter; ++i) { // Iterate over each row in the array
        memset(lines[i], 0, MAX_CHARACTER_LENGTH); // Use memset to set all characters in the current row to zero
    }
    rowCounter = 0;
    lineCounter = 0;
        
    return 0;
}
