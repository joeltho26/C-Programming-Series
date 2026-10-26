#include <stdio.h>
#include <stdbool.h>

int main(void) {
    /*
    if only initializing an variable, always assign the variable with 0
    otherwise we will have random garbage value assigned to them
    */ 
    int you_age = 25, my_age = 34;
    float you_height = 183.5f;
    int my_height = 178;
    double pi = 3.14159265358979;
    char grade = 'A';
    char name[] = "Joe Denver";
    bool is_online = true;
    bool is_student = true;

    printf("You are %d years old and %.2f cms tall\n", you_age, you_height);
    printf("I am %d years old and %d cms tall\n", my_age, my_height);
    printf("The value of pi: %.15f\n", pi);
    printf("The grade is %c\n", grade);
    printf("My name is %s\n", name);
    if (is_online && is_student) {
        printf("The student is online!\n");
    }
    else if (is_student) {
        printf("The student is offline!\n");
    }
    else if (is_online) {
        printf("Online but not a student!\n");
    }
    else {
        printf("Neither a student nor online!\n");
    }
    return 0; // if the main function doesnt return 0 then it signifies that there is an error
}