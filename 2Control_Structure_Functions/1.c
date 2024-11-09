// 1. Write a menu-driven program with following features: (a) Store Contact numbers of people, 
//(b) Search for the Contact numbers using their names, (c) Search for the Contact numbers using their number, 
//(d) Delete a Contact number, and (e) Update a Contact number

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char number[15];
};

void addContact(struct Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }
    printf("Enter contact name: ");
    scanf("%s", contacts[*count].name);
    printf("Enter contact number: ");
    scanf("%s", contacts[*count].number);
    (*count)++;
    printf("Contact added successfully!\n");
}

void searchByName(struct Contact contacts[], int count) {
    char name[50];
    int found = 0;
    printf("Enter the name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found: %s - %s\n", contacts[i].name, contacts[i].number);
            found = 1;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
}

void searchByNumber(struct Contact contacts[], int count) {
    char number[15];
    int found = 0;
    printf("Enter the number to search: ");
    scanf("%s", number);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].number, number) == 0) {
            printf("Contact found: %s - %s\n", contacts[i].name, contacts[i].number);
            found = 1;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
}

void deleteContact(struct Contact contacts[], int *count) {
    char name[50];
    int found = 0;
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);

    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) //Shift left
            {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

void updateContact(struct Contact contacts[], int count) {
    char name[50];
    int found = 0;
    printf("Enter the name of the contact to update: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Enter the new number: ");
            scanf("%s", contacts[i].number);
            printf("Contact updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

void displayContacts(struct Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts to display!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", contacts[i].name, contacts[i].number);
    }
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact by Name\n");
        printf("3. Search Contact by Number\n");
        printf("4. Delete Contact\n");
        printf("5. Update Contact\n");
        printf("6. Display All Contacts\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                searchByName(contacts, count);
                break;
            case 3:
                searchByNumber(contacts, count);
                break;
            case 4:
                deleteContact(contacts, &count);
                break;
            case 5:
                updateContact(contacts, count);
                break;
            case 6:
                displayContacts(contacts, count);
                break;
            case 7:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
