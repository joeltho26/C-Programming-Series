#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum {
        BREAKFAST,
        BRUNCH,
        LUNCH,
        SNACKS,
        DINNER,
        UNKNOWN
    } Foodcombo;

Foodcombo get_food_combo(const char *str) {
    if (strcmp(str, "breakfast") == 0) return BREAKFAST;
    if (strcmp(str, "brunch") == 0)  return BRUNCH;
    if (strcmp(str, "lunch") == 0) return LUNCH;
    if (strcmp(str, "snacks") == 0)  return SNACKS;
    if (strcmp(str, "dinner") == 0) return DINNER;
    return UNKNOWN;
};

int main () {
    int dayOfWeek = 0;
    printf("Days of the week:\n");
    printf("1 -> Monday\n");
    printf("2 -> Tuesday\n");
    printf("3 -> Wednesday\n");
    printf("4 -> Thursday\n");
    printf("5 -> Friday\n");
    printf("6 -> Saturday\n");
    printf("7 -> Sunday\n");

    printf("Enter the day of the week in number: ");
    while (scanf("%d", &dayOfWeek) != 1 || (dayOfWeek < 1 || dayOfWeek > 7)) {
        printf("Invalid option! Please enter valid option: ");

        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    };

    switch (dayOfWeek) {
        case 1:
            printf("It is monday!\n");
            break;
        case 2:
            printf("It is tuesday!\n");
            break;
        case 3:
            printf("It is wednesday!\n");
            break;
        case 4:
            printf("It is thursday!\n");
            break;
        case 5:
            printf("It is friday!\n");
            break;
        case 6:
            printf("It is saturday!\n");
            break;
        case 7:
            printf("It is sunday!\n");
            break;

    };

    int isStringValid = 0;
    char foodCombo[15] = "";
    getchar();
    while (!isStringValid) {
        
        printf("Enter the food combo option: ");
        if (fgets(foodCombo, sizeof(foodCombo), stdin) == NULL) {
            continue;
        };

        foodCombo[strcspn(foodCombo, "\n")] = '\0'; // removing trailing newline character added by fgets

        if (strlen(foodCombo) == 0) {
            printf("food combo option not entered. Try again.\n");
            continue;
        };

        isStringValid = 1;
        for (int i=0; i < strlen(foodCombo); i++) {
            if (!isalpha((unsigned char) foodCombo[i])) {
                isStringValid = 0;
                break;
            };
        };

        if (!isStringValid) {
            printf("Invalid food combo input are not allowed...try again!\n");
        };
        
    };

    /*
    you cannot use a string directly in a switch statement. 
    The C compiler requires the switch expression to resolve 
    to an integral type (such as int, char, or an enum)
    */

    switch (get_food_combo(foodCombo)) {
        case BREAKFAST:
            printf("We will be serving you mash potatos, croissant and coffee!\n");
            break;
        case BRUNCH:
            printf("We will be serving you burgers, french fries and coke!\n");
            break;
        case LUNCH:
            printf("We will be serving you buritto, cheesecake and a water bottle!\n");
            break;
        case SNACKS:
            printf("We will be serving you chicken nuggets, cookies and apple juice!\n");
            break;
        case DINNER:
            printf("We will be serving you pizza, wings and sprite!\n");
            break;
        default:
            printf("Unknown food combo option\n");
            break;

    };

    return 0;
}