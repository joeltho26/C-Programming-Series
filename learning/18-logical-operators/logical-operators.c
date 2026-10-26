#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool validate_num(float *num) {
    char buffer[100];
    printf("Enter the temperature: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return false;
    }
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len - 1] = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return false;
    }

    if (strlen(buffer) == 0) {
        return false;
    }

    char *endptr;
    *num = strtod(buffer, &endptr);

    if (*endptr == '\0') {
        return true;
    }
    return false;
}

int main () {
    float temperature = 0.0f;
    printf("Press Enter to continue...");
    while(getchar() != '\n');
    bool isValid = false; 
    char condition[10] = ""; 
    while(!isValid) {
        if (!validate_num(&temperature)) {
            continue;
        };
        isValid = true;
    }

    if (temperature > 50 || temperature < -50) {
        strcpy(condition, "inhabitable");
    } else if (temperature > 35) {
        strcpy(condition, "hot");
    } else if (temperature > 25) {
        strcpy(condition, "good");
    } else if (temperature > 10) {
        strcpy(condition, "breezy");
    } else if (temperature >= -5) {
        strcpy(condition, "cold");
    } else {
        strcpy(condition, "freezing");
    }

    printf("The temperature is very %s", condition);
    
    return 0;

}