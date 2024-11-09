#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Order {
    int id;
    int delivery_time;
    char description[256];
    struct Order* next;
} Order;
 
Order* head = NULL;
int order_count = 0;
int total_delivery_time = 0;
 
void add_order(int id, int delivery_time, const char* description) {
    Order* new_order = (Order*)malloc(sizeof(Order));
    new_order->id = id;
    new_order->delivery_time = delivery_time;
    strcpy(new_order->description, description);
    new_order->next = NULL;
 
    total_delivery_time += delivery_time;
    order_count++;
 
    if (!head || delivery_time < head->delivery_time) {
        new_order->next = head;
        head = new_order;
    } else {
        Order* current = head;
        while (current->next && current->next->delivery_time <= delivery_time) {
            current = current->next;
        }
        new_order->next = current->next;
        current->next = new_order;
    }
 
    printf("Order %d added successfully.\n", id);
}
 
void retrieve_earliest_order() {
    if (!head) {
        printf("No pending orders.\n");
        return;
    }
 
    Order* earliest_order = head;
    head = head->next;
 
    printf("Retrieved order %d with description: %s\n", earliest_order->id, earliest_order->description);
    total_delivery_time -= earliest_order->delivery_time;
    order_count--;
 
    free(earliest_order);
}
 
void modify_order(int id, int new_delivery_time, const char* new_description) {
    Order* current = head;
    Order* previous = NULL;
 
    while (current && current->id != id) {
        previous = current;
        current = current->next;
    }
 
    if (!current) {
        printf("Order %d not found.\n", id);
        return;
    }
 
    total_delivery_time = total_delivery_time - current->delivery_time + new_delivery_time;
    current->delivery_time = new_delivery_time;
    strcpy(current->description, new_description);
 
    if (previous) {
        previous->next = current->next;
    } else {
        head = current->next;
    }
 
    add_order(current->id, current->delivery_time, current->description);
    free(current);
 
    printf("Order %d modified successfully.\n", id);
}
 
void cancel_order(int id) {
    Order* current = head;
    Order* previous = NULL;
 
    while (current && current->id != id) {
        previous = current;
        current = current->next;
    }
 
    if (!current) {
        printf("Order %d not found.\n", id);
        return;
    }
 
    if (previous) {
        previous->next = current->next;
    } else {
        head = current->next;
    }
 
    total_delivery_time -= current->delivery_time;
    order_count--;
 
    printf("Order %d canceled successfully.\n", id);
    free(current);
}
 
void list_orders() {
    if (!head) {
        printf("No pending orders.\n");
        return;
    }
 
    printf("Pending orders:\n");
    Order* current = head;
    while (current) {
        printf("Order ID: %d, Delivery Time: %d, Description: %s\n",
               current->id, current->delivery_time, current->description);
        current = current->next;
    }
}
 
void average_order_processing_time() {
    if (order_count == 0) {
        printf("No pending orders.\n");
        return;
    }
 
    double average_time = (double)total_delivery_time / order_count;
    printf("Average processing time of pending orders: %.2f minutes\n", average_time);
}
 
int main() {
    int choice, id, delivery_time;
    char description[256];
 
    while (1) {
        printf("\n1. Add Order\n2. Retrieve Earliest Order\n3. Modify Order\n4. Cancel Order\n5. List Orders\n6. Average Order Processing Time\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
 
        switch (choice) {
            case 1:
                printf("Enter order ID: ");
                scanf("%d", &id);
                printf("Enter delivery time (minutes): ");
                scanf("%d", &delivery_time);
                getchar();
                printf("Enter order description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0';
                add_order(id, delivery_time, description);
                break;
            case 2:
                retrieve_earliest_order();
                break;
            case 3:
                printf("Enter order ID to modify: ");
                scanf("%d", &id);
                printf("Enter new delivery time (minutes): ");
                scanf("%d", &delivery_time);
                getchar();
                printf("Enter new description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0';
                modify_order(id, delivery_time, description);
                break;
            case 4:
                printf("Enter order ID to cancel: ");
                scanf("%d", &id);
                cancel_order(id);
                break;
            case 5:
                list_orders();
                break;
            case 6:
                average_order_processing_time();
                break;
            case 7:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
 
    return 0;
}