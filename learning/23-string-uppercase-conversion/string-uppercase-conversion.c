#include <stdio.h>

capitalize_first_char(char *str) {
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 32;
    };
}

int main() {
    char message[] = "welcome";
    printf("%s\n", message);
    capitalize_first_char(message);
    printf("%s\n", message);
    return 0;
}
