// EXERCISE 1.3 The 'for' statement pg.16-17
#include <stdio.h> // Standard input/ output library

double celcius; // Setting the data type to double accuracy float
for (celcius = 0.0; celcius <= 300.0; celcius = celcius + 20.0) { // for (initialization; condition; increment)
    printf("%-3.2lf°C, %-5.2lf°F\n", celcius, (9.0 / 5.0) * (celcius + 32.0)); // Print the results
    fflush(stdout); // Ensure immediate output. This can be particularly useful when you want to make sure that all previous outputs are displayed before proceeding with further operations.
}

printf("\n"); // Print a 'new line' for seperation

for (celcius = 300.0; celcius >= 0.0; celcius = celcius - 20.0) { // for (initialization; condition; increment)
    printf("%-3.2lf°C, %-5.2lf°F\n", celcius, (9.0 / 5.0) * (celcius + 32.0)); // Print the results
    fflush(stdout); // Ensure immediate output. This can be particularly useful when you want to make sure that all previous outputs are displayed before proceeding with further operations.
}
