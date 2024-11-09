#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;
 

Matrix create_matrix(int rows, int cols);
void free_matrix(Matrix matrix);
void input_matrix(Matrix matrix);
void display_matrix(Matrix matrix);
Matrix add_matrices(Matrix mat1, Matrix mat2);
Matrix subtract_matrices(Matrix mat1, Matrix mat2);
Matrix multiply_matrices(Matrix mat1, Matrix mat2);
Matrix transpose_matrix(Matrix mat);
void print_menu();
 
int main() {
    Matrix mat1, mat2, result;
    int choice, rows, cols;
 
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("Enter rows and columns for Matrix 1: ");
                scanf("%d %d", &rows, &cols);
                mat1 = create_matrix(rows, cols);
                printf("Enter values for Matrix 1:\n");
                input_matrix(mat1);
 
                printf("Enter rows and columns for Matrix 2: ");
                scanf("%d %d", &rows, &cols);
                mat2 = create_matrix(rows, cols);
                printf("Enter values for Matrix 2:\n");
                input_matrix(mat2);
 
                result = add_matrices(mat1, mat2);
                printf("Result of Addition:\n");
                display_matrix(result);
                free_matrix(result);
                free_matrix(mat1);
                free_matrix(mat2);
                break;
 
            case 2:
                printf("Enter rows and columns for Matrix 1: ");
                scanf("%d %d", &rows, &cols);
                mat1 = create_matrix(rows, cols);
                printf("Enter values for Matrix 1:\n");
                input_matrix(mat1);
 
                printf("Enter rows and columns for Matrix 2: ");
                scanf("%d %d", &rows, &cols);
                mat2 = create_matrix(rows, cols);
                printf("Enter values for Matrix 2:\n");
                input_matrix(mat2);
 
                result = subtract_matrices(mat1, mat2);
                printf("Result of Subtraction:\n");
                display_matrix(result);
                free_matrix(result);
                free_matrix(mat1);
                free_matrix(mat2);
                break;
 
            case 3:
                printf("Enter rows and columns for Matrix 1: ");
                scanf("%d %d", &rows, &cols);
                mat1 = create_matrix(rows, cols);
                printf("Enter values for Matrix 1:\n");
                input_matrix(mat1);
 
                printf("Enter rows and columns for Matrix 2: ");
                scanf("%d %d", &rows, &cols);
                mat2 = create_matrix(rows, cols);
                printf("Enter values for Matrix 2:\n");
                input_matrix(mat2);
 
                result = multiply_matrices(mat1, mat2);
                printf("Result of Multiplication:\n");
                display_matrix(result);
                free_matrix(result);
                free_matrix(mat1);
                free_matrix(mat2);
                break;
 
            case 4:
                printf("Enter rows and columns for Matrix: ");
                scanf("%d %d", &rows, &cols);
                mat1 = create_matrix(rows, cols);
                printf("Enter values for Matrix:\n");
                input_matrix(mat1);
 
                result = transpose_matrix(mat1);
                printf("Result of Transposition:\n");
                display_matrix(result);
                free_matrix(result);
                free_matrix(mat1);
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
 

Matrix create_matrix(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix.data[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}
 
void free_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        free(matrix.data[i]);
    }
    free(matrix.data);
}
 

void input_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix.data[i][j]);
        }
    }
}
 

void display_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            printf("%d ", matrix.data[i][j]);
        }
        printf("\n");
    }
}
 

Matrix add_matrices(Matrix mat1, Matrix mat2) {
    if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
        printf("Error: Matrices dimensions do not match for addition.\n");
        return create_matrix(0, 0);
    }
    Matrix result = create_matrix(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }
    return result;
}
 

Matrix subtract_matrices(Matrix mat1, Matrix mat2) {
    if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
        printf("Error: Matrices dimensions do not match for subtraction.\n");
        return create_matrix(0, 0);
    }
    Matrix result = create_matrix(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
        }
    }
    return result;
}
 

Matrix multiply_matrices(Matrix mat1, Matrix mat2) {
    if (mat1.cols != mat2.rows) {
        printf("Error: Matrices dimensions do not match for multiplication.\n");
        return create_matrix(0, 0);
    }
    Matrix result = create_matrix(mat1.rows, mat2.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < mat1.cols; k++) {
                result.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
            }
        }
    }
    return result;
}
 

Matrix transpose_matrix(Matrix mat) {
    Matrix result = create_matrix(mat.cols, mat.rows);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            result.data[j][i] = mat.data[i][j];
        }
    }
    return result;
}
 

void print_menu() {
    printf("\nMatrix Calculator Menu:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Multiply Matrices\n");
    printf("4. Transpose Matrix\n");
    printf("0. Exit\n");
}