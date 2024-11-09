// 9. Program to Print a Digital Clock showing time (both in 24-hour format and 12-hour format) in IST, UTC and GMT
#include <stdio.h>
#include <time.h>

void printTimeInFormats(time_t rawtime) {
    struct tm *timeinfo;
    timeinfo = localtime(&rawtime);

    printf("Current Time in 24-hour format: %02d:%02d:%02d\n", 
           timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    int hour12 = timeinfo->tm_hour % 12; 
    hour12 = (hour12 == 0) ? 12 : hour12; 
    printf("Current Time in 12-hour format: %02d:%02d:%02d %s\n", 
           hour12, timeinfo->tm_min, timeinfo->tm_sec, 
           (timeinfo->tm_hour < 12) ? "AM" : "PM");
}

void printTimeInIST(time_t rawtime) {
    struct tm *timeinfo;
    timeinfo = gmtime(&rawtime); 

    timeinfo->tm_hour += 5;
    timeinfo->tm_min += 30;

    if (timeinfo->tm_min >= 60) {
        timeinfo->tm_hour += timeinfo->tm_min / 60;
        timeinfo->tm_min %= 60;
    }
    
    if (timeinfo->tm_hour >= 24) {
        timeinfo->tm_hour %= 24;
    }

    printf("Current Time in IST: %02d:%02d:%02d\n", 
           timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

int main() {
    time_t rawtime;
    time(&rawtime); 

    printf("Displaying current time...\n");

    printTimeInFormats(rawtime);
    printTimeInIST(rawtime);     

    struct tm *timeinfo = gmtime(&rawtime);
    printf("Current Time in UTC: %02d:%02d:%02d\n", 
           timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    printf("Current Time in GMT: %02d:%02d:%02d\n", 
           timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    return 0;
}
