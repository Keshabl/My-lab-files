#include <stdio.h>
#include <stdlib.h>
#include "func.h"




int main() {
    int n, i;
    printf("Insert size number matrix plz: ");
    scanf("%d", &n);

    double **matrix1 = newMatrix(n);
    double **matrix2 = newMatrix(n);

    printf("First matrix elements:\n");
    fillMatrix(matrix1, n);

    printf("Second matrix elements:\n");
    fillMatrix(matrix2, n);

    printf("And what next you wanna do? (+, -, *): ");
    char operation;
    scanf(" %c", &operation);

    double **result;
    switch (operation) {
        case '+':
            result = plusMatrix(matrix1, matrix2, n);
            break;
        case '-':
            result = minusMatrix(matrix1, matrix2, n);
            break;
        case '*':
            result = xMatrix(matrix1, matrix2, n);
            break;
        default:
            printf("There is no variants like that, silly\n");
            return 1;
    }

    printf("Here you go, your answer:\n");
    printMatrix(result, n);

    for (i = 0; i < n; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
