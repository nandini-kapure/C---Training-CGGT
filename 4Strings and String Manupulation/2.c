// 2. Program to filter a set of log entries entered by the user. Each log entry is a timestamped entry in a format that includes date, time, and message. The program should filter log entries based on a date range and display the filtered entries. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int year;
    int month;
    int day;
};

struct LogEntry {
    struct Date date;
    char message[256];
};

// Function to parse a date string in the format "YYYY-MM-DD"
int parse_date(const char *date_str, struct Date *date) {
    return sscanf(date_str, "%4d-%2d-%2d", &date->year, &date->month, &date->day);
}

// Function to check if a date is within the range (inclusive)
int is_within_date_range(struct Date date, struct Date start_date, struct Date end_date) {
    if (date.year < start_date.year || date.year > end_date.year)
        return 0;
    if (date.year == start_date.year && date.month < start_date.month)
        return 0;
    if (date.year == end_date.year && date.month > end_date.month)
        return 0;
    if (date.year == start_date.year && date.month == start_date.month && date.day < start_date.day)
        return 0;
    if (date.year == end_date.year && date.month == end_date.month && date.day > end_date.day)
        return 0;
    return 1;
}

// Main program
int main() {
    struct LogEntry logs[100];
    int n = 0;
    char input[256];
    struct Date start_date, end_date;

    // Input the date range
    printf("Enter start date (YYYY-MM-DD): ");
    fgets(input, sizeof(input), stdin);
    parse_date(input, &start_date);

    printf("Enter end date (YYYY-MM-DD): ");
    fgets(input, sizeof(input), stdin);
    parse_date(input, &end_date);

    printf("Enter log entries (format: YYYY-MM-DD Message). Enter 'END' to finish:\n");

    // Read and parse log entries
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "END", 3) == 0)
            break;

        // Extract date and message
        if (sscanf(input, "%4d-%2d-%2d %[^\n]", &logs[n].date.year, &logs[n].date.month, &logs[n].date.day, logs[n].message) == 4) {
            n++;
        } else {
            printf("Invalid entry format. Please use 'YYYY-MM-DD Message'\n");
        }
    }

    // Display filtered log entries within the specified date range
    printf("\nFiltered log entries:\n");
    for (int i = 0; i < n; i++) {
        if (is_within_date_range(logs[i].date, start_date, end_date)) {
            printf("%04d-%02d-%02d %s\n", logs[i].date.year, logs[i].date.month, logs[i].date.day, logs[i].message);
        }
    }

    return 0;
}
