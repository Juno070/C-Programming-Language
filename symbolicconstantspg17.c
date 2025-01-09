// EXERCISE 1.4 Symbolic Constants pg.17
#include <stdio.h> // Sandard input/ output library

// LOWER is the starting value (0).
#define LOWER  0
// UPPER is the ending value (300).
#define UPPER  300
// STEP is the increment value (20).
#define STEP   20

int fahr; // Set the variable's data type
for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) { // for (initialization; condition; increment)
    printf("%3d°F %6.1f°C\n", fahr, (5.0 / 9.0)*(fahr - 32)); // Print the results
    fflush(stdout); // Ensure immediate output. This can be particularly useful when you want to make sure that all previous outputs are displayed before proceeding with further operations.
}
