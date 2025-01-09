// EXERCISE 1.2B Variables and Arithmetic Expressions pg.16
#include <stdio.h>

// Set variable data type
double farenheit, celcius;
double lower, upper, step;

// Define variables
lower = 0.0;
upper = 300.0;
step = 20.0;

// Printing the heading
printf("%-10s\t%-10s\n", "Farenheit", "Celcius"); // %-10s left-aligns the text (%s = string) and assigns 10 spaces for output string
// Printing a line separator
printf("%-10s\t%-10s\n", "------------", "------------");
// Setup the looping sequence
farenheit = lower;
while (farenheit <= upper) { // While loop conditional, executes the body of the loop as long as farenheit is less than or equal to upper
      celcius = (5.0 / 9.0) * (farenheit - 32.0); // Farenheit to Celsius conversion formula
      printf("%-10.2lf°F\t%-10.2lf°C\n", farenheit, celcius); // Print the results
      farenheit = farenheit + step; // Increment farenheit
      fflush(stdout); // Ensure immediate output
}

printf("\n"); // Seperate the data tables by a space

// Printing the heading
printf("%-10s\t%-10s\n", "Celcius", "Farenheit"); // %-10s left-aligns the text (%s = string) and assigns 10 spaces for output string
// Printing a line separator
printf("%-10s\t%-10s\n", "------------", "------------");
// Setup the looping sequence
celcius = lower;
while (celcius <= upper) { // While loop conditional, executes the body of the loop as long as celsius is less than or equal to upper
      farenheit = (9.0 / 5.0) * (celcius + 32.0); // Celsius to Farenheit conversion formula
      printf("%-10.2lf°C\t%-10.2lf°F\n", celcius, farenheit); // Print the results
      celcius = celcius + step; // Increment celsius
      fflush(stdout); // Ensure immediate output. This can be particularly useful when you want to make sure that all previous outputs are displayed before proceeding with further operations.
}
