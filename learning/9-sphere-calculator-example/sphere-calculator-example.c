#include <stdio.h>
#include <math.h>

int main() {
    float radius = 0.0f;
    const double pi = (double) 22/7; // to get decimal-based value

    printf("Enter the radius value of a sphere:");
    scanf("%f", &radius);

    double surface_area = 4 * pi * pow(radius, 2);
    double volume = (double) 4/3 * pi * pow(radius, 3);

    printf("Area of a sphere: %f\n", surface_area);
    printf("Circumference of a sphere: %f\n", volume);
}