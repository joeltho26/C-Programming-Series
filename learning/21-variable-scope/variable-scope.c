#include <stdio.h>
#include <math.h>

// int result = 0; // global variable

int add(int x, int y) {
    int result = x + y;
    x -= 1;
    printf("Num1 (Inside add): %d\n", x);
    return result;
}

int subtract(int x, int y) {
    int result = x - y; // variable scope for 'result' is within the subtract method
    y -= 1;
    printf("Num2 (Inside subtract): %d\n", y);
    return result;
}

int main() {
    int num1, num2;
    num1 = 3, num2 = 4;
    // int num1 = 1;  leads to error, cannot name variables with same name within the same scope
    int result = add(num1, num2);
    printf("Result of %d + %d: %d\n", num1, num2, result);
    printf("Num1: %d\n",num1);
    printf("Num2: %d\n",num2);
    int result1 = subtract(num1, num2);
    printf("Result of %d + %d: %d\n", num1, num2, result1);
    return 0;
}