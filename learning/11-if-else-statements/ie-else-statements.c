#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int age = 0;
    int isStudent = 0;
    char name[50] = "";

    do {
        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin);
        name[strlen(name) - 1] = '\0';
        if (strlen(name) > 20) {
            printf("Name is too long...try again\n");
            name[0] = '\0'; // reset to empty string
        }
    } while (strlen(name) == 0);
    
    do {
        printf("Enter your age: ");
        scanf("%d", &age);

        if (age>=150) {
            printf("Invalid entry for age...try again\n");
            age = 0; // reset to age
        }
    } while (age==0);
    
    /*
    boolean type cannot be used as input instead we can use integer or text 
    to replicate the boolean input behaviour
    */

    do {
        printf("If you're a student, Enter 1 = student or Enter 0 = non-student: ");
        scanf("%d", &isStudent);
        if (isStudent > 1 || isStudent < 0) {
            printf("Invalid entry for student flag...try again\n");
        }
        
    } while (isStudent > 1 || isStudent < 0);

    // output condition
    if (age>18 && isStudent) {
        printf("He is an adult and a student!");
    }
    else if (age>18 && !isStudent) {
        printf("He is only an adult and not a student!");
    }
    else if (age==0) {
        printf("He is a new born!");
    }
    else if (age<0) {
        printf("He is not born yet!");
    }
    else if (age<18 && !isStudent) {
        printf("He is a minor and not a student!");
    }

    return 0;
}