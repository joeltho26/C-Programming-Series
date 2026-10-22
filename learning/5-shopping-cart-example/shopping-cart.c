#include <stdio.h>
#include <string.h>

int main() {
    char item_name[20] = "";
    float price = 0.0f;
    int quantity = 0;
    char currency = '$';
    float total = 0.0f;

    printf("What item would you like today?:");
    fgets(item_name, sizeof(item_name), stdin);
    item_name[strlen(item_name)-1] = '\0';

    printf("What is the price for each?:");
    scanf("%f", &price);

    printf("How many would you like?:");
    scanf("%d", &quantity);

    total = quantity * price;

    printf("\n");
    printf("You have brought %d %ss\n", quantity, item_name);
    printf("The total is: %c%.2f", currency, total);

    return 0;

}