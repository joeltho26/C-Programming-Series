#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

float squareNumber (float num) {
    return num * num;
};

bool validateNumber(float *num) {
    char buffer[100];
    printf("Enter the number: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return false;
    };
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return false;
    }

    if (len == 0) {
        return false;
    }

    char *endptr;
    *num = strtod(buffer, &endptr);
    if (*endptr == '\0') {
        return true;
    }
    return false;
}

int main() {
    float value = 0.0f;
    printf("Press enter to continue...");
    while (getchar() != '\n');
    bool isValid = false;

    while (!isValid) {
        if (!validateNumber(&value)) {
            continue;
        }
        isValid = true;
    }

    float result = squareNumber(value);
    printf("The square of %.2f: %.2f", value, result);

    return 0;
}