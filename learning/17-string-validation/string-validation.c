#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    // 1. A string containing a valid double followed by leftover text
    const char *str1 = "3.1415926 This text is ignored";
    char *endptr1;
    
    double val1 = strtod(str1, &endptr1);
    
    printf("--- Basic Parsing ---\n");
    printf("Converted value: %f\n", val1);
    printf("Leftover string: \"%s\"\n\n", endptr1);

    // 2. Comprehensive Error Handling (No digits found vs Out of Range)
    const char *str2 = "abc123.45"; // Invalid starting characters
    char *endptr2;
    
    // Reset errno before making the call
    errno = 0; 
    double val2 = strtod(str2, &endptr2);
    
    printf("--- Error Handling ---\n");
    if (str2 == endptr2) {
        printf("Error: No valid digits could be found in \"%s\"\n", str2);
    } else if (errno == ERANGE) {
        printf("Error: The value is out of range for a double\n");
    } else {
        printf("Converted value: %f\n", val2);
    }

    return 0;
}