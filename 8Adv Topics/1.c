#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_APPLICATIONS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 11
 
char names[MAX_APPLICATIONS][MAX_NAME_LENGTH];
char dates[MAX_APPLICATIONS][MAX_DATE_LENGTH];
int experiences[MAX_APPLICATIONS];
int scores[MAX_APPLICATIONS];
 
int count;
 
void get_user_input() {
    printf("Enter the number of applications: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        printf("\nApplication %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", names[i]);
        printf("Enter application date (YYYY-MM-DD): ");
        scanf("%s", dates[i]);
        printf("Enter experience (in years): ");
        scanf("%d", &experiences[i]);
        printf("Enter score: ");
        scanf("%d", &scores[i]);
    }
}
 
int compare_applications(const void *a, const void *b) {
    int idx1 = *(const int *)a;
    int idx2 = *(const int *)b;
    int date_comparison = strcmp(dates[idx1], dates[idx2]);
    if (date_comparison != 0) {
        return date_comparison;
    }
    if (experiences[idx1] != experiences[idx2]) {
        return experiences[idx2] - experiences[idx1];
    }
    return scores[idx2] - scores[idx1];
}
 
void display_schedule(int sorted_indices[], int count) {
    printf("\nScheduled Interviews (in order of priority):\n");
    for (int i = 0; i < count; i++) {
        int idx = sorted_indices[i];
        printf("%s, Applied on: %s, Experience: %d years, Score: %d\n",
               names[idx], dates[idx], experiences[idx], scores[idx]);
    }
}
 
int main() {
    int indices[MAX_APPLICATIONS];
    get_user_input();
    for (int i = 0; i < count; i++) {
        indices[i] = i;
    }
    qsort(indices, count, sizeof(int), compare_applications);
    display_schedule(indices, count);
    return 0;
}