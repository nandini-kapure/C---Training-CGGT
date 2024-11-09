#include <stdio.h>
#include <math.h>

int main() {
    int degree;
    double x, result = 0.0;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    double coefficients[degree + 1];  

    printf("Enter the coefficients of the polynomial (highest degree to constant term):\n");
    for (int i = 0; i <= degree; i++) {
        printf("Coefficient of x^%d: ", degree - i);
        scanf("%lf", &coefficients[i]);
    }

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, degree - i);  
    }

    printf("The value of the polynomial at x = %.2lf is: %.2lf\n", x, result);

    return 0;
}
