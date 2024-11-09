// 2. Given an N x N matrix, write a program to sort the matrix in alternating ascending and descending order rowwise (i.e. first row is sorted in ascending order, second row sorted in descending order, third row sorted in ascending order and so on.)
#include <stdio.h>
#include <stdlib.h>

int compareAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compareDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}
void sortMatrix(int matrix[][100], int N) {
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            qsort(matrix[i], N, sizeof(int), compareAsc);
        } else {
            qsort(matrix[i], N, sizeof(int), compareDesc);
        }
    }
}

int main() {
    int N;
    printf("Enter the size of the matrix (N x N): ");
    scanf("%d", &N);

    int matrix[100][100];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    sortMatrix(matrix, N);

    printf("Sorted matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}