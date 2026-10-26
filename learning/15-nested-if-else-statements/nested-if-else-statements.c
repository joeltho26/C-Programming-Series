#include <stdio.h>
#include <stdbool.h>

int main() {
    float price = 10.00f;
    int isStudent = 0;
    int isSenior = 0;
    bool isValidStudent = false, isValidSenior = false;

    while (!isValidStudent) {
        printf("Are you a student? Enter 1->Yes or 0->No: ");
        if (scanf("%d", &isStudent) != 1 || (isStudent > 1 || isStudent < 0)) {
            printf("Invalid input! Try again\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        };
        
        isValidStudent = true;
    };

    while (!isValidSenior) {
        printf("Are you a senior? Enter 1->Yes or 0->No: ");
        if (scanf("%d", &isSenior) != 1 || (isSenior > 1 || isSenior < 0)) {
            printf("Invalid input! Try again\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        };
        isValidSenior = true;
    };

    if (isStudent) {
        if (isSenior) {
            printf("You get a student discount of 30%%\n");
            price *= 0.7;
            
        } else {
            printf("You get a student discount of 10%%\n");
            price *= 0.9;
        };
         
    } else {
        if (isSenior) {
            printf("You get a student discount of 20%%\n");
            price *= 0.8;
            
        } else {
            printf("You get no discount\n");
        }
    };

    printf("The price of a ticket is: $%.2f\n", price);
    return 0;
}