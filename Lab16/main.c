#include <stdio.h>
#include <stdlib.h>
int count_bits_long(long number) {
    int count = 0;
    int i;
    for (i = 0; i < 8*sizeof(number); i++) {
        if (number & (1 << i))
            count++;
    }
    return count;
}
int count_bits_double(double number) {
    long *p = (long*)&number;
    return count_bits_long(*p);
}

int main() {
    long long_num;
    double double_num;
    printf("Long: ");
    scanf("%ld", &long_num);
    printf("Double: ");
    scanf("%lf", &double_num);
    printf("edenizi long: %d\n", count_bits_long(long_num));
    printf("edenizi double: %d\n", count_bits_double(double_num));
    return 0;
}
