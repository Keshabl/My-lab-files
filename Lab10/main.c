#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define AVG(arr, n) ({ \
	    double sum = 0; \
    for(i = 0; i < n; i++) { \
        sum += arr[i]; \
    } \
    sum / n; \
})

int main() {
	int result, n, i;
	double avg;
    char str[100];
    printf("Insert numbers: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    int count = 0;
    int *numbers = malloc(sizeof(int));
    char *token = strtok(str, " ");
    while(token != NULL) {
        numbers[count] = atoi(token); 
        count++;
        numbers = realloc(numbers, (count + 1) * sizeof(int)); 
        token = strtok(NULL, " ");}

    result = numbers[0];
    for (i = 1; i < count; i++)
        result = MAX(result, numbers[i]);
    i=0;
    avg = AVG(numbers, count);
    printf("Samii bolshoi: %d \n", result);
    printf("Sredni: %lf", avg);
    return 0;
}
