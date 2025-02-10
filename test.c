#include <stdio.h>

#define SPACE_TO_TAB_LIMIT 4 // Defines the number of spaces that must be present before a tab can be substituded in their place

int main() {
    int increment;
    int character;
    int spaceCounter = 0;
    int inSpaceinWord = 0;

    printf("Enter multiple lines of text and then use 'Enter' to properly execute the code then, (Ctrl+D to end on Unix, Ctrl+Z to end on Windows):\n");
    
    while ((character = getchar()) != EOF) {
        if (character == ' ') {
            ++spaceCounter;
            inSpaceinWord = 1; // True
        }
        else {
            inSpaceinWord = 0; // False
        }
        if (spaceCounter == SPACE_TO_TAB_LIMIT) {
            putchar('\t');
            spaceCounter = 0;
        }
        if (spaceCounter > 0 && spaceCounter < SPACE_TO_TAB_LIMIT && inSpaceinWord == 0) {
            for (increment = 0; increment < spaceCounter; ++increment) {
                putchar(' ');
            }
            spaceCounter = 0;
        }
        if (character != ' ') {
            putchar(character);
        }
    }
    return 0;
}
