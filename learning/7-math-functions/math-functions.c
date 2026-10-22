#include <stdio.h>
#include <math.h>

int main() {
    int x = 3;
    float y = 3.14f;
    int z = 45;
    printf("Square root of %d: %f\n", x, sqrt(x));
    printf("Square of %d: %f\n", x, pow(x,2));
    printf("Cube of %d: %f\n", x, pow(x,3));
    printf("Rounded value of %.2f: %.0f\n", y, round(y));
    printf("Upper round value of %.2f: %.0f\n", y, ceil(y));
    printf("Lower round value of %.2f: %.0f\n", y, floor(y));
    printf("Absolute value of %.2f: %d\n", y, abs(y));
    printf("Log of %d: %f\n", x, log(x));
    printf("Sin, Cosine & Tan value of %d radians: %f, %f & %f\n", z, sin(z), cos(z), tan(z));
}