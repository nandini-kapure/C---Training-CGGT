#include <stdio.h>
#include <string.h>
 
#define ROWS 5      
#define COLS 5        
#define NAME_LEN 30  
 
typedef struct {
    int is_reserved;          
    int is_occupied;            
    char reservation_name[NAME_LEN]; 
} Table;
 
void initialize_tables(Table layout[ROWS][COLS]);
void reserve_table(Table layout[ROWS][COLS], int row, int col, const char *name);
void cancel_reservation(Table layout[ROWS][COLS], int row, int col);
void display_table_status(Table layout[ROWS][COLS]);
 
int main() {
    Table layout[ROWS][COLS];
    initialize_tables(layout);
 
    int choice, row, col;
    char name[NAME_LEN];
 
    while (1) {
        printf("\nRestaurant Table Management System\n");
        printf("1. Reserve Table\n");
        printf("2. Cancel Reservation\n");
        printf("3. Display Table Status\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("Enter table row (0-%d): ", ROWS - 1);
                scanf("%d", &row);
                printf("Enter table column (0-%d): ", COLS - 1);
                scanf("%d", &col);
                getchar();  
 
                if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
                    printf("Enter reservation name: ");
                    fgets(name, NAME_LEN, stdin);
                    name[strcspn(name, "\n")] = '\0';  
                    reserve_table(layout, row, col, name);
                } else {
                    printf("Invalid table position.\n");
                }
                break;
 
            case 2:
                printf("Enter table row (0-%d): ", ROWS - 1);
                scanf("%d", &row);
                printf("Enter table column (0-%d): ", COLS - 1);
                scanf("%d", &col);
 
                if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
                    cancel_reservation(layout, row, col);
                } else {
                    printf("Invalid table position.\n");
                }
                break;
 
            case 3:
                display_table_status(layout);
                break;
 
            case 0:
                printf("Exiting program.\n");
                return 0;
 
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
 

void initialize_tables(Table layout[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            layout[i][j].is_reserved = 0;
            layout[i][j].is_occupied = 0;
            strcpy(layout[i][j].reservation_name, "");
        }
    }
}
 

void reserve_table(Table layout[ROWS][COLS], int row, int col, const char *name) {
    if (layout[row][col].is_reserved) {
        printf("Table %d,%d is already reserved by %s.\n", row, col, layout[row][col].reservation_name);
    } else {
        layout[row][col].is_reserved = 1;
        layout[row][col].is_occupied = 0;
        strncpy(layout[row][col].reservation_name, name, NAME_LEN - 1);
        layout[row][col].reservation_name[NAME_LEN - 1] = '\0';  
        printf("Table %d,%d has been reserved under the name '%s'.\n", row, col, name);
    }
}
 

void cancel_reservation(Table layout[ROWS][COLS], int row, int col) {
    if (!layout[row][col].is_reserved) {
        printf("Table %d,%d is not reserved.\n", row, col);
    } else {
        layout[row][col].is_reserved = 0;
        layout[row][col].is_occupied = 0;
        strcpy(layout[row][col].reservation_name, "");
        printf("Reservation for table %d,%d has been canceled.\n", row, col);
    }
}
 

void display_table_status(Table layout[ROWS][COLS]) {
    printf("\nCurrent Table Status:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Table %d,%d: ", i, j);
            if (layout[i][j].is_reserved) {
                printf("Reserved by %s", layout[i][j].reservation_name);
                if (layout[i][j].is_occupied) {
                    printf(" (Occupied)");
                }
                printf("\n");
            } else {
                printf("Available\n");
            }
        }
    }
}