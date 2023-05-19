#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char surname[20];
    int year;
} human;

int main() {
    FILE *fptr;
    human *arr1, *arr2;
    int n, i, j;

    fptr = fopen("file1.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file!");
        return 1;
    }

    fscanf(fptr, "%d", &n);

    arr1 = (human*) malloc(n * sizeof(human));
    arr2 = (human*) malloc(n * sizeof(human));

    for (i = 0; i < n; i++) {
        fscanf(fptr, "%s %s %d", arr1[i].name, arr1[i].surname, &arr1[i].year);
    }

    fclose(fptr);

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (arr1[i].year > arr1[j].year) {
                human temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }
        }
    }

    memcpy(arr2, arr1, n * sizeof(human));

    printf("Here they are:\n");
    for (i = 0; i < n; i++) {
        printf("%s %s (%d)\n", arr2[i].name, arr2[i].surname, arr2[i].year);
    }

    free(arr1);
    free(arr2);

    return 0;
}

