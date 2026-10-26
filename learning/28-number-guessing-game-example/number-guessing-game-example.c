#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
    int number = 0;
    srand(time(NULL));
    bool isValid = false;
    int min = 1;
    int max = 100;
    int tries = 0;
    int randNumber = (rand() % (max - min + 1)) + min;
    while (true){
        printf("Press enter to continue...");
        while(getchar() != '\n');
        while (!isValid) {
            printf("Guess the number between 0 - 100: ");
            if (scanf("%d", &number) != 1 || (number < 1 || number > 100)) {
                printf("Invalid! Try again...\n");
                int c;
                while((c = getchar()) != '\n' && c != EOF);
                continue;
            };
            isValid = true;
        };
        tries++;
        if (randNumber == number) {
            printf("You guessed the correct number!\n");
            printf("Number of tries: %d\n", tries);
            int calculatedScore = 100 - ((tries * 500)/100);
            int score = (calculatedScore > 0) ? calculatedScore : 0;
            printf("Your score: %d\n", score);
            break;

        } else if (number > randNumber) {
            printf("Too high!\n");
        } else {
            printf("Too low!\n");
        }
        isValid = false;
        getchar();
    };
    return 0;
}