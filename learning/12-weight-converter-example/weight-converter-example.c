#include <stdio.h>

int main() {
    const double conversionRate = 0.45359237f;
    float weight = 0.0f;
    float convertedWeight = 0.0f;
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
    printf("Weight Conversion\n");
    printf("Options:\n");
    printf("Enter 0 => Kilograms -> Pound\n");
    printf("Enter 1 => Pound -> Kilograms\n");

    printf("Enter your choice: ");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 0)) {
    printf("Invalid option! Please enter your option...");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    };
 
    if (choice == 0) {
        printf("Enter your weight in kgs: ");
    } 
    else {
        printf("Enter your weight in lbs: ");
    }
    
    while (scanf("%f", &weight) != 1) {
    printf("Invalid input! Please enter your weight...");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    };

    if (choice == 0) {
        convertedWeight = weight/conversionRate;
        printf("The converted weight from kilogram -> pound %f", convertedWeight);
    } 
    else {
        convertedWeight = weight * conversionRate;
        printf("The converted weight from pound -> kilogram %f", convertedWeight);
    }

    return 0;
}
