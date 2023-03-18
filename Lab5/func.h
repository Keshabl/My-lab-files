#include <stdio.h>
#include <stdlib.h>

double **newMatrix(int n)
{
    int i;
	double **matrix = malloc(n * sizeof(double *));
    for (i = 0; i < n; i++)
	{
        matrix[i] = malloc(n * sizeof(double));
    }
    return matrix;
}

void fillMatrix(double **matrix, int n)
{
	int i, j;
    for (i = 0; i < n; i++)
	{
        for (j = 0; j < n; j++)
		{
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void printMatrix(double **matrix, int n)
{
	int i, j;
    for (i = 0; i < n; i++)
	{
        for (j = 0; j < n; j++)
		{
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

double **plusMatrix(double **matrix1, double **matrix2, int n)
{
	int i, j;
    double **result = newMatrix(n);
    for (i = 0; i < n; i++)
	{
        for (j = 0; j < n; j++)
		{
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

double **minusMatrix(double **matrix1, double **matrix2, int n)
{
	int i, j;
    double **result = newMatrix(n);
    for (i = 0; i < n; i++)
	{
        for (j = 0; j < n; j++)
		{
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

double **xMatrix(double **matrix1, double **matrix2, int n)
{
	int i, j, k;
    double **result = newMatrix(n);
    for (i = 0; i < n; i++)
	{
        for (j = 0; j < n; j++)
		{
            double sum = 0;
            for (k = 0; k < n; k++)
			{
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

