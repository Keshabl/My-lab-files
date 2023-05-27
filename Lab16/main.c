#include <stdio.h>
#include <stdlib.h>
#include "func.h"


int main() {
    long long_num;
    double double_num;
    printf("Long: ");
    scanf("%ld", &long_num);
    printf("Double: ");
    scanf("%lf", &double_num);
    printf("edenizi long: %d\n", count_bits_long(long_num));
    printf("edenizi double: %d\n", count_bits_double(double_num));
    printf("Binary long %ld is: ", long_num);
    printBinary(long_num);
    printf("\n");
    printf("Binary double %lf is: ", double_num);
    printBinaryD(double_num);
    printf("\n");
    return 0;
}
