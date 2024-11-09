#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int val;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) printf(" -> ");
        current = current->next;
    }
    printf("\n");
}

int main() {
    char input[100];
    printf("Enter a linked list (e.g., 1->2->3): ");
    fgets(input, sizeof(input), stdin);

    // Tokenize and parse input
    struct Node *head = NULL, *tail = NULL;
    char *ch = strtok(input, "->");

    while (ch != NULL) {
        int value = atoi(ch);
        struct Node *newNode = createNode(value);

        // Append the new node to the linked list
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        
        ch = strtok(NULL, "->");
    }

    // Print the linked list
    printf("Linked list: ");
    printList(head);

    // Free the allocated memory
    // struct Node *current = head;
    // while (current != NULL) {
    //     struct Node *next = current->next;
    //     free(current);
    //     current = next;
    // }

    return 0;
}
