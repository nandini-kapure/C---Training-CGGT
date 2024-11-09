// 5. Program to generate a re-payment schedule for a loan. The user should provide the loan amount, 
//annual interest rate, and the number of years to repay. The program should output the monthly payment 
//and a detailed schedule showing payments over time.

#include <stdio.h>
#include <math.h>

int main() {
    double loanAmount, annualInterestRate, monthlyInterestRate;
    int numOfYears, totalPayments;
    double monthlyPayment, balance, principal, interest;
    
    printf("Enter loan amount: ");
    scanf("%lf", &loanAmount);
    printf("Enter annual interest rate (in percentage): ");
    scanf("%lf", &annualInterestRate);
    printf("Enter number of years to repay: ");
    scanf("%d", &numOfYears);

    monthlyInterestRate = (annualInterestRate / 100.0) / 12.0;
    totalPayments = numOfYears * 12;

    monthlyPayment = (loanAmount * monthlyInterestRate * pow(1 + monthlyInterestRate, totalPayments)) /
                     (pow(1 + monthlyInterestRate, totalPayments) - 1);

    printf("\nMonthly Payment: %.2lf\n", monthlyPayment);

    printf("\nRepayment Schedule:\n");
    printf("Payment\tInterest\tPrincipal\tBalance\n");

    balance = loanAmount;

    for (int payment = 1; payment <= totalPayments; payment++) {
        interest = balance * monthlyInterestRate;
        principal = monthlyPayment - interest;
        balance -= principal;
        printf("%d\t%.2lf\t\t%.2lf\t\t%.2lf\n", payment, interest, principal, balance);

        if (balance < 0) balance = 0;
    }

    return 0;
}
