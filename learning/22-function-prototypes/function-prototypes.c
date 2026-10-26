#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void printMessage(char name[], int age);
bool ageCheck(int age);

int main() {
    char name[] = "Joe";
    int age = 13;
    char ageCategory[] = "an adult";
    printMessage(name, age);
    if (ageCheck(age)) {
        strcpy(ageCategory, "a minor");
    }
    printf("He is %s", ageCategory);
    return 0;
}

void printMessage(char name[], int age) {
    printf("My name is %s.\n", name);
    printf("I am %d years old.\n", age);
}

bool ageCheck(int age) {
    return age < 18;
}

