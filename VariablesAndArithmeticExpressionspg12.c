// EXERCISE 1.2A Variables and Arithmetic Expressions pg.12
#include <stdio.h> // Library for standard input and output

int main() {
    // Define the range for temperature conversion
    double start = 0.0; // Start of range (Fahrenheit)
    double end = 20.0; // End of range (Fahrenheit)

    // Perform the conversion for each degree in the range
    for (double i = start; i < end; i++) { // The for loop starts at start and iterates while i is less than end, incrementing i by 1 in each iteration
        double DegCel = (5.0 / 9.0) * (i - 32.0); // Formula to convert Degrees Farenheit to Degrees Celcius
        printf("%.2lf Degrees Farenheit = %.2lf Degrees Celsius\n", i, DegCel); // Print the results of the conversions
        fflush(stdout); // Ensure the output is flushed immediately. This can be particularly useful when you want to make sure that all previous outputs are displayed before proceeding with further operations.
    }
}
