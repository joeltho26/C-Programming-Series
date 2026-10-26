#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //needed to generate pseudo random number

    // print random number based on time configured via 'srand()'
    printf("Random Number: %d\n", rand());

    printf("%d", RAND_MAX); //32767  

    // to limit the random number range between 0 & 1
    int number = rand() % 2;
    printf("Random Number (0/1): %d\n", number);

    // to limit the random number range between 1 & 2
    int number1 = (rand() % 2) + 1;
    printf("Random Number (1/2): %d\n", number1);

    // to limit the random number range between 1 to 10
    int number2 = rand() % 10;
    printf("Random Number (1-10): %d\n", number2);

    // to limit the random number range between 50 to 100
    int max = 100, min = 50;
    int number3 = (rand() % (max - min + 1)) + min;
    printf("Random Number (50-100): %d\n", number3);
    return 0;
}