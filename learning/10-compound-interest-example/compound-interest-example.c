#include <stdio.h>
#include <math.h>

int main() {
    double principal = 0.0;
    double rate = 0.0;
    int years = 0;
    int timesCompounded = 0;
    double total = 0.0;

    printf("Compound Interest Calculator");
    printf("Enter the principal (P) in rupees: ");
    scanf("%lf", &principal);

    printf("Enter the rate of interest %% (r): ");
    scanf("%lf", &rate);
    rate = rate/100;

    printf("Enter the number of years (t): ");
    scanf("%d", &years);

    printf("Enter the number of times compounded per year (n): ");
    scanf("%d", &timesCompounded);
    total = principal * pow(1 + rate/timesCompounded, timesCompounded * years);
    printf("The total sum after including the interest: Rs.%.2lf\n", total);
    printf("The interest sum: Rs.%.2lf\n", (total-principal));
}