#include <stdio.h>

int main() {
    int num1 = 1;
    int num2 = -10;
    int num3 = 100;
    float weight = 3.789; 
    double pi = 3.14159265358979;

    // right justify with length of 3 char
    // char space with no digits or -ve sign '-' will be represented by empty spaces
    printf("%3d", num1); 
    printf("\n%3d", num2); 
    printf("\n%4d", num3); 
    printf("\n***************");

    // left justify with length of 3 char
    // char space with no digits or -ve sign '-' will be represented by empty spaces
    printf("\n%-3d", num1); 
    printf("\n%-3d", num2);
    printf("\n%-3d", num3);
    printf("\n***************");

    // right justify with length of 3 char
    // char space with no digits or -ve sign '-' will be represented with zeros preceeded
    printf("\n%03d", num1); 
    printf("\n%03d", num2);
    printf("\n%03d", num3);
    printf("\n***************");

    // left justify with length of 3 char
    //  if the value is +ve then it will print '+' else '-'
    // applicable for accounting
    printf("\n%+-3d", num1);
    printf("\n%+-3d", num2); 
    printf("\n%+-3d", num3); 
    printf("\n***************");

    // precision of floating point values upto 2 decimal points
    printf("\n%.6f", pi); 
    printf("\n%.2f", weight); 
    printf("\n***************");

    // precision of floating point values upto 2 decimal points
    // right justify with length of 15 char
    printf("\n%+15.6f", pi); 
    printf("\n%15.2f", weight); 
    printf("\n***************");

    // precision of floating point values upto 2 decimal points
    // left justify with length of 15 char
    printf("\n%-15.6f", pi); 
    printf("\n%+-15.2f", weight); 
    printf("\n***************");

}