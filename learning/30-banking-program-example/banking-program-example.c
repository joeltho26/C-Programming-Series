#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool inputOption(int *num) {
    printf("Enter your option: ");
    if (scanf("%d", num) != 1 || (*num < 1 || *num > 4)) {
        printf("Invalid option! Try again!\n");
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        return false;
    }
    return true;
}

bool validateNumber(float *num) {
    char buffer[100];
    printf("Enter the sum: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return false;
    }
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
    } else {
        int c;
        while((c=getchar()) != '\n' && c != EOF);
        return false;
    };

    if (len == 0) {
        return false;
    }

    char *endptr;
    *num = strtod(buffer, &endptr);

    if (*endptr == '\0') {
        return true;
    }
    return false;
};

void checkBalance(float balance) {
    printf("You current balance is: $%.2f\n", balance);
};

void depositMoney(float *balance) {
    float value = 0.0f;
    while (!validateNumber(&value)) {
        printf("Invalid sum! Try again!\n");
        continue;
    }
    *balance += value;
    printf("%.2f deposited into the account\n", value);
    checkBalance(*balance);
};

void withdrawMoney(float *balance) {
    float value = 0.0f;
    while (!validateNumber(&value)) {
        printf("Invalid sum! Try again!\n");
        continue;
    }
    if (value > *balance) {
        printf("Insufficient balance!\n");
    } else {
        *balance -= value;
        printf("%.2f withdrawn from the account\n", value);
    }
    checkBalance(*balance);
};

int main() {
    bool loop = true;
    float balance = 0.0f;
    while (loop) {
        int option = 0;
        printf("Press enter to continue...");
        while(getchar() != '\n');
        checkBalance(balance);
        printf("Select an option:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        while(!inputOption(&option));
        getchar();
        switch (option) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                depositMoney(&balance);
                break;
            case 3:
                withdrawMoney(&balance);
                break;
            case 4:
                return 0;
        }

    }
    
    return 0;
}