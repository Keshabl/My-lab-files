#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "func.h"



int main() {
    // �������� ���������� �����
    int n, i;
    printf("Kol-vo: ");
    scanf("%d", &n);

    // �������� ���� ����� � ��������� �� � ������
    int numbers[n];
    printf("Numbers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // ������� ���������� ������ �������
    printf("Sum: %d\n", sum(2, 4, 5));
    printf("Max: %d\n", max(2, 4, 5));
    printf("Min: %d\n", min(2, 4, 5));
    printf("Avg: %.2f\n", average(2, 4, 5));

    return 0;
}
