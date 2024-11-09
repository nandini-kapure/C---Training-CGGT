//5. Program to Convert a number from Base 1 to Base 2 where Base 1 and Base 2 are specified by the user.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int toDecimal(char num[], int base1) {
    int decimal = 0;
    int power = 0;
    int len = strlen(num);

    for (int i = len - 1; i >= 0; i--) {
        char digit = num[i];
        if (digit >= '0' && digit <= '9') {
            decimal += (digit - '0') * pow(base1, power);
        } else if (digit >= 'A' && digit <= 'Z') {
            decimal += (digit - 'A' + 10) * pow(base1, power);
        }
        power++;
    }
    return decimal;
}

void fromDecimal(int decimal, int base2, char result[]) {
    char temp[32];
    int index = 0;

    while (decimal > 0) {
        int remainder = decimal % base2;
        if (remainder < 10) {
            temp[index++] = remainder + '0';
        } else {
            temp[index++] = remainder - 10 + 'A';
        }
        decimal /= base2;
    }

    temp[index] = '\0';

     int len = strlen(temp);
    for (int i = 0; i < len; i++) {
        result[i] = temp[len - i - 1];
    }
    result[len] = '\0';
}

int main() {
    int base1, base2;
    char num[32];
    char result[32];

    printf("Enter Base 1: ");
    scanf("%d", &base1);

    printf("Enter Base 2: ");
    scanf("%d", &base2);

    printf("Enter the number in base %d: ", base1);
    scanf("%s", num);

    // Convert from base1 to decimal
    int decimalValue = toDecimal(num, base1);

    // Convert from decimal to base2
    fromDecimal(decimalValue, base2, result);

    printf("The number %s in base %d is %s in base %d\n", num, base1, result, base2);

    return 0;
}
