#include <stdio.h>
#include <time.h>

int main() {

    int date, month, year;

    printf("Enter the date of birth in \"dd mm yyyy\" format:\n");
    scanf("%d %d %d", &date, &month, &year);
    printf("Day: %d, Month: %d, Year: %d\n", date, month, year);

    // Get the current date
    time_t currentTime;
    time(&currentTime);

    struct tm *localTime = localtime(&currentTime);

    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;

    // Calculate the difference in years
    int ageYears = currentYear - year;

    // Adjust months and days if necessary
    int ageMonths = currentMonth - month;
    int ageDays = currentDay - date;

    if (ageDays < 0) {
        // Borrow days from the previous month
        ageMonths--;
        // Get the number of days in the previous month
        int daysInPrevMonth;

        if (currentMonth == 1 || currentMonth == 3 || currentMonth == 5 ||
            currentMonth == 7 || currentMonth == 8 || currentMonth == 10 || currentMonth == 12) {
            daysInPrevMonth = 31;
        } else if (currentMonth == 2) {
            // Check if it's a leap year
            if ((currentYear % 4 == 0 && currentYear % 100 != 0) || currentYear % 400 == 0) {
                daysInPrevMonth = 29;
            } else {
                daysInPrevMonth = 28;
            }
        } else {
            daysInPrevMonth = 30;
        }

        ageDays += daysInPrevMonth;
    }

    if (ageMonths < 0) {
        // Borrow a year if necessary
        ageYears--;
        ageMonths += 12;
    }

    printf("You are %d years, %d months, and %d days old.\n", ageYears, ageMonths, ageDays);

    return 0;
}
