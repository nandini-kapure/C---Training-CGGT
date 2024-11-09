#include <stdio.h>
#include <stdlib.h>
 
#define AVAILABLE 0
#define BOOKED 1
 
typedef struct {
    int sections;
    int rows;
    int columns;
    int ***seats; 
} Theater;
 

Theater create_theater(int sections, int rows, int columns);
void free_theater(Theater theater);
void book_seat(Theater *theater, int section, int row, int col);
void cancel_booking(Theater *theater, int section, int row, int col);
void view_beating(Theater theater);
void print_menu();
 
int main() {
    Theater theater;
    int sections, rows, columns;
    int choice, section, row, col;
 
   
    printf("Enter the number of sections: ");
    scanf("%d", &sections);
    printf("Enter the number of rows per section: ");
    scanf("%d", &rows);
    printf("Enter the number of columns per row: ");
    scanf("%d", &columns);
    theater = create_theater(sections, rows, columns);
 
   
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("Enter section, row, and column to book (0-indexed): ");
                scanf("%d %d %d", &section, &row, &col);
                book_seat(&theater, section, row, col);
                break;
 
            case 2:
                printf("Enter section, row, and column to cancel booking (0-indexed): ");
                scanf("%d %d %d", &section, &row, &col);
                cancel_booking(&theater, section, row, col);
                break;
 
            case 3:
                view_beating(theater);
                break;
 
            case 0:
                printf("Exiting program.\n");
                free_theater(theater);
                return 0;
 
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
 

Theater create_theater(int sections, int rows, int columns) {
    Theater theater;
    theater.sections = sections;
    theater.rows = rows;
    theater.columns = columns;
 
  
    theater.seats = (int ***)malloc(sections * sizeof(int **));
    for (int i = 0; i < sections; i++) {
        theater.seats[i] = (int **)malloc(rows * sizeof(int *));
        for (int j = 0; j < rows; j++) {
            theater.seats[i][j] = (int *)malloc(columns * sizeof(int));
            for (int k = 0; k < columns; k++) {
                theater.seats[i][j][k] = AVAILABLE;  
            }
        }
    }
    return theater;
}
 

void free_theater(Theater theater) {
    for (int i = 0; i < theater.sections; i++) {
        for (int j = 0; j < theater.rows; j++) {
            free(theater.seats[i][j]);
        }
        free(theater.seats[i]);
    }
    free(theater.seats);
}
 

void book_seat(Theater *theater, int section, int row, int col) {
    if (section >= theater->sections || row >= theater->rows || col >= theater->columns || section < 0 || row < 0 || col < 0) {
        printf("Invalid seat location.\n");
        return;
    }
    if (theater->seats[section][row][col] == BOOKED) {
        printf("Seat already booked.\n");
    } else {
        theater->seats[section][row][col] = BOOKED;
        printf("Seat at Section %d, Row %d, Column %d has been booked.\n", section, row, col);
    }
}
 

void cancel_booking(Theater *theater, int section, int row, int col) {
    if (section >= theater->sections || row >= theater->rows || col >= theater->columns || section < 0 || row < 0 || col < 0) {
        printf("Invalid seat location.\n");
        return;
    }
    if (theater->seats[section][row][col] == AVAILABLE) {
        printf("Seat is already available.\n");
    } else {
        theater->seats[section][row][col] = AVAILABLE;
        printf("Booking at Section %d, Row %d, Column %d has been canceled.\n", section, row, col);
    }
}
 

void view_beating(Theater theater) {
    printf("\nTheater Seating Arrangement:\n");
    for (int i = 0; i < theater.sections; i++) {
        printf("Section %d:\n", i);
        for (int j = 0; j < theater.rows; j++) {
            for (int k = 0; k < theater.columns; k++) {
                printf("%c ", theater.seats[i][j][k] == AVAILABLE ? 'O' : 'X');
            }
            printf("\n");
        }
        printf("\n");
    }
}
 

void print_menu() {
    printf("\nTheater Seating Management Menu:\n");
    printf("1. Book Seat\n");
    printf("2. Cancel Booking\n");
    printf("3. View Seating\n");
    printf("0. Exit\n");
}