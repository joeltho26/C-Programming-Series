#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
scanf("%f") directly on user input is dangerous because it leaves trailing invalid characters 
(like letters) in the buffer and can cause infinite loops.
*/

bool validate_number(double *num, const char *str) {
    char buffer[100];
    printf("Enter the %s: ", str);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return false;
    };

    // Remove trailing newline if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    } else {
        // Input was too long for buffer; clear the rest of the line
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return false;
    };
    
    if (strlen(buffer) == 0) {
        return false;
    };

    char *endptr;
    *num = strtod(buffer, &endptr);

    if (*endptr == '\0') {
        return true;
    }
    return false;
}

int main () {
    while (true) {
        double num1 = 0.0f;
        int choice = 0;
        bool isValidOption = false;
        bool isValidNumber = false; 
        double result = 0.0f;
        printf("Press [Enter] to continue...");
        while (getchar() != '\n');  

        printf("Calculator:\n");
        printf("0 -> Addition:\n");
        printf("1 -> Subtraction:\n");
        printf("2 -> Multiplication:\n");
        printf("3 -> Division:\n");
        printf("4 -> Square root:\n");
        printf("5 -> Cube root:\n");
        printf("6 -> Square:\n");
        printf("7 -> Cube:\n");
        printf("8 -> Log:\n");
        printf("9 -> Sin:\n");
        printf("10 -> Cos:\n");
        printf("11 -> Tan:\n");
        printf("12 -> Cosec:\n");
        printf("13 -> Sec:\n");
        printf("14 -> Cot:\n");

        while (!isValidOption) {
            printf("Enter the option: ");
            if (scanf("%d", &choice) != 1 || (choice < 0 || choice > 14)) {
                printf("Invalid option! Try again.\n");
        
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            };
            isValidOption = true;
        };

        getchar();
        if (choice < 4) {
            double num2 = 0.0f;
            while (!isValidNumber) {
                if (!validate_number(&num1, "first number")) {
                    continue;
                };
                isValidNumber = true;
            };

            isValidNumber = false;
            while (!isValidNumber) {
                if (!validate_number(&num2, "second number")) {
                    continue;
                };
                isValidNumber = true;
            };
            
            switch (choice) {
                case 0:
                    result = num1 + num2;
                    printf("The addition of %.2f and %.2f: %.2f\n",num1, num2, result);
                    break;
                case 1:
                    result = num1 - num2;
                    printf("The subtraction of %.2f and %.2f: %.2f\n",num1, num2, result);
                    break;
                case 2:
                    result = num1 * num2;
                    printf("The multiplication of %.2f and %.2f: %.2f\n",num1, num2, result);
                    break;
                case 3:
                    result = (double) num1 / num2;
                    printf("The division of %.2f and %.2f: %.2f\n",num1, num2, result);
                    break;
            };

        } else {
            while (!isValidNumber) {
                if (!validate_number(&num1, "number")) {
                    continue;
                };
                isValidNumber = 1;
            };

            switch (choice) {
                case 4:
                    result = sqrt(num1);
                    printf("The square root of %.2lf: %.2lf\n", num1, result);
                    break;
                case 5:
                    result = cbrt(num1);
                    printf("The cube root of %.2lf: %.2lf\n", num1, result);
                    break;
                case 6:
                    result = pow(num1, 2);
                    printf("The square of %.2lf: %.2lf\n", num1, result);
                    break;
                case 7:
                    result = pow(num1, 3);
                    printf("The cube of %.2lf: %.2lf\n", num1, result);
                    break;
                case 8:
                    result = log(num1);
                    printf("The log of %.2lf: %.2lf\n", num1, result);
                    break;
                case 9:
                    result = sin(num1);
                    printf("The sin of %.2lf: %.2lf\n", num1, result);
                    break;
                case 10:
                    result = cos(num1);
                    printf("The cos of %.2lf: %.2lf\n", num1, result);
                    break;
                case 11:
                    result = tan(num1);
                    printf("The tan of %.2lf: %.2lf\n",num1, result);
                    break;
                case 12:
                    result = (double) 1/sin(num1);
                    printf("The cosec of %.2lf: %.2lf\n", num1, result);
                    break;
                case 13:
                    result = (double) 1/cos(num1);
                    printf("The sec of %.2lf: %.2lf\n", num1, result);
                    break;
                case 14:
                    result = (double) 1/tan(num1);
                    printf("The cot of %.2lf: %.2lf\n", num1, result);
                    break;
            };
        };
    }
    
    return 0;
}
