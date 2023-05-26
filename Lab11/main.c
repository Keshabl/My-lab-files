#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "func.h"



int main() {
    // получаем количество чисел
    int n, i;
    printf("Kol-vo: ");
    scanf("%d", &n);

    // получаем сами числа и сохраняем их в массив
    int numbers[n];
    printf("Numbers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // выводим результаты работы функций
    printf("Sum: %d\n", sum(n, numbers));
    printf("Max: %d\n", max(n, numbers));
    printf("Min: %d\n", min(n, numbers));
    printf("Avg: %.2f\n", average(n, numbers));

    return 0;
}
