#include <stdio.h>
#include <stdlib.h>

void addition(int a[3][3], int b[3][3], int result[3][3]);
void subtraction(int a[3][3], int b[3][3], int result[3][3]);
void multiplication(int a[3][3], int b[3][3], int result[3][3]);
void inputMatrix(int matrix[3][3]);
void printMatrix(int matrix[3][3]);

int main() {
    int menu_selection = 0;
    int matrix1[3][3], matrix2[3][3], result[3][3];

    do {
        printf("1. Matrix addition\n2. Matrix subtraction\n3. Matrix multiplication\n0. Exit\nSelect operation: ");
        scanf("%d", &menu_selection);

        if (menu_selection == 0) {
            exit(0);
        }

        printf("Matrix 1:\n");
        inputMatrix(matrix1);
        printf("Matrix 2:\n");
        inputMatrix(matrix2);

        switch (menu_selection) {
            case 1:
                addition(matrix1, matrix2, result);
                break;
            case 2:
                subtraction(matrix1, matrix2, result);
                break;
            case 3:
                multiplication(matrix1, matrix2, result);
                break;
            default:
                printf("Invalid selection. Please try again.\n");
                continue;
        }

        printf("Result:\n");
        printMatrix(result);

    } while (menu_selection != 0);

    return 0;
}

void addition(int x[3][3], int y[3][3], int result[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = x[i][j] + y[i][j];
        }
    }
}

void subtraction(int x[3][3], int y[3][3], int result[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = x[i][j] - y[i][j];
        }
    }
}

void multiplication(int a[3][3], int b[3][3], int result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void inputMatrix(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
