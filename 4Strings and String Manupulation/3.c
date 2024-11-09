// 3. Program to analyzes a set of customer support tickets and prioritizes them as High, Medium, or Low based on the presence of certain keywords or phrases (e.g., crash, urgent, fail, error). Tickets with high-priority keywords or urgent phrases should be flagged for immediate attention. (Example tickets: System crash on startup, Payment processing issue, Unable to access account - urgent. Example Output: System crash on startup - High, Payment processing issue - Medium, Unable to access account - urgent - High)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TICKETS 100
#define MAX_LENGTH 256

// Function to check for keywords in a ticket and assign priority
const char* determine_priority(const char *ticket) {
    // High priority keywords
    const char *high_keywords[] = {"crash", "urgent", "fail", "error"};
    int num_high_keywords = sizeof(high_keywords) / sizeof(high_keywords[0]);

    // Medium priority keywords
    const char *medium_keywords[] = {"issue", "problem", "delay"};
    int num_medium_keywords = sizeof(medium_keywords) / sizeof(medium_keywords[0]);

    // Check for high-priority keywords
    for (int i = 0; i < num_high_keywords; i++) {
        if (strstr(ticket, high_keywords[i]) != NULL) {
            return "High";
        }
    }

    // Check for medium-priority keywords
    for (int i = 0; i < num_medium_keywords; i++) {
        if (strstr(ticket, medium_keywords[i]) != NULL) {
            return "Medium";
        }
    }

    // Default to Low priority if no keywords found
    return "Low";
}

// Convert string to lowercase for case-insensitive comparison
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char tickets[MAX_TICKETS][MAX_LENGTH];
    int num_tickets = 0;

    printf("Enter support tickets (type 'END' to stop):\n");

    // Read tickets from user
    while (num_tickets < MAX_TICKETS) {
        fgets(tickets[num_tickets], MAX_LENGTH, stdin);
        tickets[num_tickets][strcspn(tickets[num_tickets], "\n")] = 0; // Remove newline

        // Stop if the user enters "END"
        if (strcmp(tickets[num_tickets], "END") == 0) {
            break;
        }

        to_lowercase(tickets[num_tickets]); // Convert to lowercase for case-insensitive matching
        num_tickets++;
    }

    // Analyze and print priorities
    printf("\nTicket Priorities:\n");
    for (int i = 0; i < num_tickets; i++) {
        printf("%s - %s\n", tickets[i], determine_priority(tickets[i]));
    }

    return 0;
}
