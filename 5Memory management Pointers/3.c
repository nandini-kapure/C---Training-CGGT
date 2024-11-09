
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_DESC_LENGTH 100
#define DATE_LENGTH 11
 
typedef struct {
    char description[MAX_DESC_LENGTH];
    char deadline[DATE_LENGTH];  
} Task;
 
typedef struct {
    Task *tasks;
    int size;
    int capacity;
} Task_scheduler;
 

void init_scheduler(Task_scheduler *scheduler);
void add_task(Task_scheduler *scheduler, const char *description, const char *deadline);
void remove_task(Task_scheduler *scheduler, int index);
void modify_task(Task_scheduler *scheduler, int index, const char *description, const char *deadline);
void list_tasks(const Task_scheduler *scheduler);
void sort_tasks(Task_scheduler *scheduler);
void filter_tasks_by_deadline(const Task_scheduler *scheduler, const char *deadline);
void free_scheduler(Task_scheduler *scheduler);
 
int main() {
    Task_scheduler scheduler;
    init_scheduler(&scheduler);
 
    int choice;
    char description[MAX_DESC_LENGTH];
    char deadline[DATE_LENGTH];
    int index;
 
    while (1) {
        printf("\nTask Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Modify Task\n");
        printf("4. List Tasks\n");
        printf("5. Sort Tasks by Deadline\n");
        printf("6. Filter Tasks by Deadline\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  
 
        switch (choice) {
            case 1:
                printf("Enter task description: ");
                fgets(description, MAX_DESC_LENGTH, stdin);
                description[strcspn(description, "\n")] = '\0';  
 
                printf("Enter task deadline (YYYY-MM-DD): ");
                fgets(deadline, DATE_LENGTH, stdin);
                deadline[strcspn(deadline, "\n")] = '\0';  
 
                add_task(&scheduler, description, deadline);
                break;
 
            case 2:
                printf("Enter task index to remove: ");
                scanf("%d", &index);
                remove_task(&scheduler, index);
                break;
 
            case 3:
                printf("Enter task index to modify: ");
                scanf("%d", &index);
                getchar();  
 
                printf("Enter new task description: ");
                fgets(description, MAX_DESC_LENGTH, stdin);
                description[strcspn(description, "\n")] = '\0';
 
                printf("Enter new task deadline (YYYY-MM-DD): ");
                fgets(deadline, DATE_LENGTH, stdin);
                deadline[strcspn(deadline, "\n")] = '\0';
 
                modify_task(&scheduler, index, description, deadline);
                break;
 
            case 4:
                list_tasks(&scheduler);
                break;
 
            case 5:
                sort_tasks(&scheduler);
                printf("Tasks sorted by deadline.\n");
                break;
 
            case 6:
                printf("Enter deadline to filter by (YYYY-MM-DD): ");
                fgets(deadline, DATE_LENGTH, stdin);
                deadline[strcspn(deadline, "\n")] = '\0';
 
                filter_tasks_by_deadline(&scheduler, deadline);
                break;
 
            case 0:
                free_scheduler(&scheduler);
                return 0;
 
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

void init_scheduler(Task_scheduler *scheduler) {
    scheduler->size = 0;
    scheduler->capacity = 10;
    scheduler->tasks = (Task *)malloc(scheduler->capacity * sizeof(Task));
}
 
void add_task(Task_scheduler *scheduler, const char *description, const char *deadline) {
    if (scheduler->size == scheduler->capacity) {
        scheduler->capacity *= 2;
        scheduler->tasks = (Task *)realloc(scheduler->tasks, scheduler->capacity * sizeof(Task));
    }
    strncpy(scheduler->tasks[scheduler->size].description, description, MAX_DESC_LENGTH);
    strncpy(scheduler->tasks[scheduler->size].deadline, deadline, DATE_LENGTH);
    scheduler->size++;
    printf("Task added successfully.\n");
}
 

void remove_task(Task_scheduler *scheduler, int index) {
    if (index < 0 || index >= scheduler->size) {
        printf("Invalid task index.\n");
        return;
    }
    for (int i = index; i < scheduler->size - 1; i++) {
        scheduler->tasks[i] = scheduler->tasks[i + 1];
    }
    scheduler->size--;
    printf("Task removed successfully.\n");
}
 

void modify_task(Task_scheduler *scheduler, int index, const char *description, const char *deadline) {
    if (index < 0 || index >= scheduler->size) {
        printf("Invalid task index.\n");
        return;
    }
    strncpy(scheduler->tasks[index].description, description, MAX_DESC_LENGTH);
    strncpy(scheduler->tasks[index].deadline, deadline, DATE_LENGTH);
    printf("Task modified successfully.\n");
}
 

void list_tasks(const Task_scheduler *scheduler) {
    if (scheduler->size == 0) {
        printf("No tasks to display.\n");
        return;
    }
    printf("\nTasks:\n");
    for (int i = 0; i < scheduler->size; i++) {
        printf("Task %d: %s, Deadline: %s\n", i, scheduler->tasks[i].description, scheduler->tasks[i].deadline);
    }
}
 

int compare_deadlines(const void *a, const void *b) {
    Task *taskA = (Task *)a;
    Task *taskB = (Task *)b;
    return strcmp(taskA->deadline, taskB->deadline);
}
 

void sort_tasks(Task_scheduler *scheduler) {
    qsort(scheduler->tasks, scheduler->size, sizeof(Task), compare_deadlines);
}
 

void filter_tasks_by_deadline(const Task_scheduler *scheduler, const char *deadline) {
    int found = 0;
    printf("\nTasks with deadline %s:\n", deadline);
    for (int i = 0; i < scheduler->size; i++) {
        if (strcmp(scheduler->tasks[i].deadline, deadline) == 0) {
            printf("Task %d: %s, Deadline: %s\n", i, scheduler->tasks[i].description, scheduler->tasks[i].deadline);
            found = 1;
        }
    }
    if (!found) {
        printf("No tasks with the specified deadline.\n");
    }
}
 

void free_scheduler(Task_scheduler *scheduler) {
    free(scheduler->tasks);
    printf("Scheduler memory freed.\n");
}