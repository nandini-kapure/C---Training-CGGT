// 4. Program to prompt the user to enter a password and check if it meets the strength criteria. Inform the user if the password is unacceptable, strong or weak based on the criteria. If the password doesn't meet the criteria, generate and suggest 2-3 strong passwords to the user which the user can select. (Example Criteria: (a) Minimum length of 8 characters. (b) Must include at least one uppercase letter, one lowercase letter, one digit, and one special character.)

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 8

// Function to check if the password is strong
int isStrongPassword(char password[]) {
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    
    if (length < MIN_LENGTH) {
        return 0;
    }

    // Check each character in the password
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = 1;
        if (islower(password[i])) hasLower = 1;
        if (isdigit(password[i])) hasDigit = 1;
        if (strchr("!@#$%^&*()-_=+[]{}|;:',.<>/?", password[i])) hasSpecial = 1;
    }

    // Return 1 if all criteria are met
    return (hasUpper && hasLower && hasDigit && hasSpecial);
}

// Function to suggest strong passwords
void generateStrongPassword(char password[], int length) {
    char possibleChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
    int possibleLength = strlen(possibleChars);

    for (int i = 0; i < length; i++) {
        password[i] = possibleChars[rand() % possibleLength];
    }
    password[length] = '\0';  // Null-terminate the string
}

int main() {
    char password[50];
    int strong;

    srand(time(0));  // Initialize random number generator

    // Prompt the user to enter a password
    printf("Enter a password: ");
    scanf("%s", password);

    // Check if the password is strong
    strong = isStrongPassword(password);

    if (strong) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is weak. It must have at least 8 characters, an uppercase letter, a lowercase letter, a digit, and a special character.\n");

        // Suggest 2-3 strong passwords
        char suggestedPassword1[MIN_LENGTH + 1];
        char suggestedPassword2[MIN_LENGTH + 1];
        char suggestedPassword3[MIN_LENGTH + 1];

        generateStrongPassword(suggestedPassword1, MIN_LENGTH);
        generateStrongPassword(suggestedPassword2, MIN_LENGTH);
        generateStrongPassword(suggestedPassword3, MIN_LENGTH);

        printf("Here are 3 strong password suggestions:\n");
        printf("1. %s\n", suggestedPassword1);
        printf("2. %s\n", suggestedPassword2);
        printf("3. %s\n", suggestedPassword3);
    }

    return 0;
}
