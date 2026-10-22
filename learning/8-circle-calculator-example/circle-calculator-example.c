#include <stdio.h>
#include <math.h>

int main() {
    float radius = 0.0f;
    const double pi = (double) 22/7; // to get decimal-based value

    printf("Enter the radius value of a circle:");
    scanf("%f", &radius);

    double area = pi * pow(radius, 2);
    double circumference = 2 * pi * radius;

    printf("Area of a circle: %lf\n", area);
    printf("Circumference of a circle: %lf\n", circumference);
}