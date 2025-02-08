#include <stdio.h> // Provides functions for input/output, like getchar() and printf()
#include <ctype.h> // Provides character classification functions like isspace()
#include <string.h> // Provides functions for string manipulation (not used here, but included)

#define MAX_WORDS 100 // Maximum number of words the program can handle
#define MAX_WORD_LENGTH 20 // Maximum length of a single word

int main() { // Program's entry
    int character; // Stores the current character read from input
    int word_lengths[MAX_WORDS] = {0}; // Array to store the lengths of each word, initialized to 0
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {0}; // 2D array to store up to MAX_WORDS words, 100 rows, 20 columns
    int word_index = 0; // Index to keep track of the current word in the array
    int char_index = 0; // Index to keep track of the current character in the current word
    int is_in_word = 0; // Flag to indicate whether the program is inside a word

    // Prompt the user to enter text and explain how to end the input
    printf("Enter text (Ctrl+D to end):\n");

    // Process input character by character
    while ((character = getchar()) != EOF) { // Read until the end of file (EOF)
        if (!isspace(character)) { // Check if the character is not whitespace
            if (!is_in_word) { // If we are not currently in a word, !is_in_word evaluates to true if is_in_word is 0 (false).
                is_in_word = 1; // Start word-reading mode
                char_index = 0; // Reset character index for the new word
            }
            words[word_index][char_index++] = character; // Add the character to the current word
        } else { // If a space or newline is encountered
            if (is_in_word) { // If we were in the middle of reading a word, is_in_word is treated as true for any non-zero value (typically 1 in this case).
                words[word_index][char_index] = '\0'; // Null-terminate the word to mark its end
                word_lengths[word_index] = char_index; // Store the length of the current word
                word_index++; // Move to the next word
                is_in_word = 0; // Exit word-reading mode
            }
        }
    }

    // Handle the edge case where the last word ends at EOF without a space
    if (is_in_word) { // If the input ends with a word and no trailing space
        words[word_index][char_index] = '\0'; // Null-terminate the word
        word_lengths[word_index] = char_index; // Store its length
        word_index++; // Increment word index
    }

    // Print the histogram heading
    printf("\n                                            Word Length Histogram\n");
    printf("                    |__________________________________________________________________________|\n");

    // Loop through each word to print its histogram
    for (int i = 0; i < word_index; i++) {
        printf("%-19s |", words[i]); // Print the word, left-aligned in a field of 12 characters
        for (int j = 0; j < word_lengths[i]; j++) { // Print one '*' for each character in the word
            printf("  *");
        }
        printf("\n"); // Move to the next line for the next word
    }

    // Print a footer to indicate the end of the histogram
    printf("                    |-------------------------------------------------------------------------|\n");
    printf("                    |  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20  |\n");
    printf("                    |-------------------------------------------------------------------------|\n");

    return 0; // Exit the program and check for successful execution
}
