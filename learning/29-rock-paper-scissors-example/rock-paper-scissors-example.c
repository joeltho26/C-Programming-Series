#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void printOptionName(char subject[], int option){
    char optionName[] = "";
    if (option == 1) {
        strcpy(optionName, "Rock"); 
    } else if (option == 2) {
        strcpy(optionName, "Paper");
    } else {
        strcpy(optionName, "Scissor");
    }
    printf("%s chose %s \n", subject, optionName);
}

int main() {
    while (true) {
        bool isValid = false;
        int option = 0;
        srand(time(NULL));
        printf("Press enter to continue...");
        while(getchar() != '\n');
        printf("Rock Paper Scissors Game: \n");
        printf("Options: 1.Rock 2.Paper 3.Scissor\n");
        while (!isValid) {
            printf("Enter you option: ");
            if (scanf("%d", &option) != 1 || (option < 1 || option > 3)) {
                printf("Invalid option! Try again!\n");
                int c;
                while((c = getchar()) != '\n' && c != EOF);
                continue;
            }
            isValid = true;
        }
        printOptionName("You", option);
        int min = 1;
        int max = 3; 
        int randomOption = (rand() % (max-min+1)) + min;
        printOptionName("Computer", randomOption);

        if (option == randomOption) {
            printf("Tied!\n");
         } else if ((option == 1 && randomOption != 2) || (option == 2 && randomOption != 3) || (option == 3 && randomOption != 1)) {
            printf("You win!\n");
        } else {
            printf("Computer win!\n");
        }
        getchar();
    }
    return 0;
}