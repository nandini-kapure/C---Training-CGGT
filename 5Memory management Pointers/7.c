#include <stdio.h>
#include <stdlib.h>
 

void bubble_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
 

void print_array(int arr[], int n);
 

typedef void (*sort_function)(int[], int);
 

void print_menu();
 
int main() {
    int choice;
    int n;
 

    sort_function sortFunctions[] = { bubble_sort, insertion_sort };
 

    printf("Enter the number of elements: ");
    scanf("%d", &n);
 
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
 
 
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
 
   
    while (1) {
        print_menu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);
 
        if (choice == 0) {
            printf("Exiting program.\n");
            break;
        } else if (choice > 0 && choice <= 2) {
            sortFunctions[choice - 1](arr, n);
            printf("Sorted array: ");
            print_array(arr, n);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    free(arr);
    return 0;
}
 

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted using Bubble Sort.\n");
}
 

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("Array sorted using Insertion Sort.\n");
}
 

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
 

void print_menu() {
    printf("\nSorting Algorithm Menu:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("0. Exit\n");
}