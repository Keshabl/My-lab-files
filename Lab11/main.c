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
    printf("Sum: %d\n", sum(n, numbers));
    printf("Max: %d\n", max(n, numbers));
    printf("Min: %d\n", min(n, numbers));
    printf("Avg: %.2f\n", average(n, numbers));

    return 0;
}
