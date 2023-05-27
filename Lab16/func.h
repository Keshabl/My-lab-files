#include <stdio.h>
#include <stdlib.h>
int count_bits_long(long number) {
	int i;
    int count = 0;
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

void printBinary(unsigned int num) {
    if (num > 1) {
        printBinary(num / 2);
    }
    printf("%d", num % 2);
}

void printBinaryD(double num) {
	int i, j;
    unsigned char* ptr = (unsigned char*)&num;
    for (i = sizeof(double) - 1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            printf("%d", (ptr[i] >> j) & 1);
        }
    }
}
