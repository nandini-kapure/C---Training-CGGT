#include <stdio.h>
#include <time.h>

int main() {
    int birthDate, birthMonth, birthYear;
    
    printf("Enter the date of birth in \"dd mm yyyy\" format:\n");
    scanf("%d %d %d", &birthDate, &birthMonth, &birthYear);
    
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    
    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;
    
    int ageYears = currentYear - birthYear;
    int ageMonths = currentMonth - birthMonth;
    int ageDays = currentDay - birthDate;

    if (ageDays < 0) {
        ageMonths--;
        ageDays += 30; 
    }
    
    if (ageMonths < 0) {
        ageYears--;
        ageMonths += 12;
    }
    
    printf("You are %d years, %d months, and %d days old.\n", ageYears, ageMonths, ageDays);

    return 0;
}
