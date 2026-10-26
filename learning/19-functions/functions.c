#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
parameter name need not be the same the one from the main function
*/
void print_message(char birthdayBoyName[], int age) {
    printf("\n");
    printf("Happy birthday to you!\n");
    printf("Happy birthday to you!\n");
    printf("Happy birthday to dear %s !\n", birthdayBoyName);
    printf("Happy birthday to you!\n");
    printf("You are %d years old!\n", age);
}

int main() {
    char name[25] = "";
    int age = 0;
    bool isValid = false;
    printf("Press enter to continue....");
    while(getchar() != '\n');
    while (!isValid) {
        printf("Enter your name: ");
        if (fgets(name, sizeof(name), stdin) == NULL) {
            continue;
        }
        size_t len = strlen(name);
        if (len > 0 && name[len-1] == '\n') {
            name[len - 1] = '\0';
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        };
        isValid = true;
    };
    isValid = false;
    while (!isValid) {
        printf("Enter your age: ");
        if (scanf("%d", &age) != 1) {
            continue;
        }
        isValid = true;
    }
    
    for (int i=0; i<3; i++) {
        print_message(name, age);
    }
    return 0;
}