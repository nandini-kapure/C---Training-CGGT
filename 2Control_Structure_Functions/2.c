// 2. Program to calculate the total customer bill based on the user's menu choices in a restaurant. 
//The program should allow the user to view a menu, select items (which are used to add to their bill), 
//and display the final total considering tax (e.g., 5% GST and 10% service tax) on the ordered items.

// # Menu:-
// # oniondosa-90 rs
// # plaindosa-40 rs
// # ravadosa-75 rs
// # idli-10 rs
// # vada-5 rs
// # poori-30 rs
// # chapathi -30 rs
// # pongal-35 rs
// # tea-25 rs
// # coffee-35 rs
// # meals-75 rs

#include <stdio.h>
#include <cstdlib>

// void Menu(int choice)
{
    printf("a. oniondosa   - 90 rs\n");
    printf("b. plaindosa   - 40 rs\n");
    printf("c. idli        - 10 rs\n");
    printf("d. ravadosa    - 75 rs\n");
    printf("e. vada        - 05 rs\n");
    printf("f. poori       - 30 rs\n");
    printf("g. chapathi    - 30 rs\n");
    printf("h. pongal      - 35 rs\n");
    printf("i. tea         - 25 rs\n");
    printf("j. coffee      - 35 rs\n");
    printf("k. meals       - 75 rs\n");

    printf("1. Add Items from Menu:- \n");
    printf("2. Display Bill:- \n");
    printf("3. Exit\n");
    
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            addItems();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
    }
}


void addItems(float *subtotal) {
    char choice;
    int valid = 1;
    while (valid) {
        displayMenu();
        printf("\nEnter the letter corresponding to the item to add (or 'q' to finish adding): ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case 'a':
                *subtotal += prices[0];
                printf("Onion Dosa added. Price: 90 Rs\n");
                break;
            case 'b':
                *subtotal += prices[1];
                printf("Plain Dosa added. Price: 40 Rs\n");
                break;
            case 'c':
                *subtotal += prices[2];
                printf("Idli added. Price: 10 Rs\n");
                break;
            case 'd':
                *subtotal += prices[3];
                printf("Rava Dosa added. Price: 75 Rs\n");
                break;
            case 'e':
                *subtotal += prices[4];
                printf("Vada added. Price: 5 Rs\n");
                break;
            case 'f':
                *subtotal += prices[5];
                printf("Poori added. Price: 30 Rs\n");
                break;
            case 'g':
                *subtotal += prices[6];
                printf("Chapathi added. Price: 30 Rs\n");
                break;
            case 'h':
                *subtotal += prices[7];
                printf("Pongal added. Price: 35 Rs\n");
                break;
            case 'i':
                *subtotal += prices[8];
                printf("Tea added. Price: 25 Rs\n");
                break;
            case 'j':
                *subtotal += prices[9];
                printf("Coffee added. Price: 35 Rs\n");
                break;
            case 'k':
                *subtotal += prices[10];
                printf("Meals added. Price: 75 Rs\n");
                break;
            case 'q':
                valid = 0;
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
void Menu() {
    int choice;
    float subtotal = 0;
    
    while (1) {
        printf("\n1. Add Items from Menu\n");
        printf("2. Display Bill\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItems(&subtotal);
                break;
            case 2:
                displayBill(subtotal);
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
int main()
{
    Menu();
        
    return 0;
}
