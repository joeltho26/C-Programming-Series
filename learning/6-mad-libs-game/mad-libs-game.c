#include <stdio.h>
#include <string.h>

int main() {
    char adj1[15] = "";
    char adj2[15] = "";
    char adj3[15] = "";
    char noun[15] = "";
    char verb[15] = "";

    printf("Enter an adjective (description):");
    scanf("%s", &adj1);

    getchar();
    printf("Enter a noun (animal or person):");
    fgets(noun, sizeof(noun), stdin);
    noun[strlen(noun)-1] = '\0';

    printf("Enter an adjective (description):");
    scanf("%s", &adj2);

    printf("Enter a verb (ending with ing):");
    scanf("%s", &verb);

    printf("Enter an adjective (description):");
    scanf("%s", &adj3);

    printf("\n");
    printf("Today I went to a %s zoo\n", adj1);
    printf("In a exhibit I saw %s\n", noun);
    printf("%s was %s and %s\n", noun, adj2, verb);
    printf("I was %s\n", adj3);
}