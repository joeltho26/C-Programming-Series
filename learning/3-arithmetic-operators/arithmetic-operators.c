#include <stdio.h>
#include <math.h>

int main() {

    // arithmetic operator
    int num1 = 33;
    int num2 = 10;
    int sum_value, mul_value, sub_value, div_value, remainder;
    sum_value = num1 + num2;
    mul_value = num1 * num2;
    sub_value = num1 - num2;
    div_value = num1 / num2;
    remainder = num2 % num1;
    printf("Addition: %d\n", sum_value);
    printf("Multiplication: %d\n", mul_value);
    printf("Division: %d\n", div_value);
    printf("Subraction: %d\n", sub_value);
    printf("Remainder: %d\n", remainder);

    // decrement
    sum_value--;
    printf("sum_value: %d\n", sum_value);

    int new_val = sum_value--;
    printf("new_val: %d, sum_value: %d\n", new_val, sum_value);

    int new_val2 = --sum_value;
    printf("new_val: %d, sum_value: %d\n", new_val2, sum_value);

    // increment
    sum_value++;
    printf("sum_value: %d\n", sum_value);

    int new_val3 = sum_value++;
    printf("new_val: %d, sum_value: %d\n", new_val3, sum_value);

    int new_val4 = ++sum_value;
    printf("new_val: %d, sum_value: %d\n", new_val4, sum_value);
    
    // augmented assignment operator
    int value = 100;
    value += 2;
    printf("Addition: %d\n", value);
    value *= 2;
    printf("Multiplication: %d\n", value);
    value /= 2;
    printf("Division: %d\n", value);
    value -= 2;
    printf("Subraction: %d\n", value);
    value %= 2;
    printf("Remainder: %d\n", value);

    return 0;
}