#include <stdio.h>

int main() {
    float temperature = 0.0f;
    float convertedTemperature = 0.0f;
    int choice = 0;
    /*
    SCENARIO 1: When the input expected is int but given a string
    • scanf looks at the input buffer, sees 'h', realizes it cannot be parsed as a number, and fails immediately.
    • The Trap: It returns a value of 0 (meaning zero items were successfully matched). Crucially, the text "hello" is left sitting in the input buffer.
    • The Consequence: If your scanf is inside a loop, the next iteration will read the exact same 'h' from the buffer, fail again, and trap your program in an infinite loop.
    
    SCENARIO 2: The input starts with numbers but ends with text 
    • What happens: scanf successfully processes "123" and assigns the integer 123 to your variable.
    • The Trap: It returns 1 (success). However, it stops scanning the moment it hits 'x'. The "xyz" is left behind in the input buffer to break whatever input function you call next.

    */
    printf("Temperature Conversion\n");
    printf("Options:\n");
    printf("Enter 0 => Celsius -> Fahrenheit\n");
    printf("Enter 1 => Celsius -> Kelvin\n");
    printf("Enter 2 => Fahrenheit -> Celsius\n");
    printf("Enter 3 => Fahrenheit -> Kelvin\n");
    printf("Enter 4 => Kelvin -> Celsius\n");
    printf("Enter 5 => Kelvin -> Fahrenheit\n");

    printf("Enter your choice: ");
    while (scanf("%d", &choice) != 1 || (choice < 0  || choice > 5)) {
    printf("Invalid option! Please enter your option...");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    };
 
    switch (choice) {
        case 0:
        case 1:
            printf("Enter your temperature in celsius: ");
            break;
        case 2:
        case 3:
            printf("Enter your temperature in fahrenheit: ");
            break;
        case 4:
        case 5:
            printf("Enter your temperature in kelvin: ");
            break;
    } 

    while (scanf("%f", &temperature) != 1) {
    printf("Invalid input! Please enter your temperature...");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    };

    switch (choice) {
        case 0:
            convertedTemperature = (temperature * ((float) 9/5)) + 32;
            printf("The converted temperature from celsius -> fahrenheit %.2f", convertedTemperature);
            break;
        case 1:
            convertedTemperature = (temperature + 273.15);
            printf("The converted temperature from celsius -> kelvin: %.2f", convertedTemperature);
            break;
        case 2:
            convertedTemperature = (temperature-32) * ((float) 5/9);
            printf("The converted temperature from fahrenheit -> celsius: %.2f", convertedTemperature);
            break;
        case 3:
            convertedTemperature = (temperature-32) * ((float) 5/9) + 273.15;
            printf("The converted temperature from fahrenheit -> kelvin: %.2f", convertedTemperature);
            break;
        case 4:
            convertedTemperature = (temperature-273.15);
            printf("The converted temperature from kelvin -> celsius: %.2f", convertedTemperature);
            break;
        case 5:
            convertedTemperature = ((temperature-273.15) * ((float) 9/5)) + 32;
            printf("The converted temperature from kelvin -> fahrenheit: %.2f", convertedTemperature);
            break;
    }
    return 0;
}
