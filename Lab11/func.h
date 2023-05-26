#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int sum(int count, ...) {
    va_list args;
    va_start(args, count);
    int result = 0;
    while (count){
    	result += va_arg(args, int);
		--count;
	}
    va_end(args);
    return result;
}

// функция для поиска максимального значения из переменного количества аргументов
int max(int count, ...) {
    va_list args;
    va_start(args, count);
    int i;
    int result = va_arg(args, int);
    for (i = 1; i < count; i++) {
        int num = va_arg(args, int);
        if (num > result) {
            result = num;
        }
    }
    va_end(args);
    return result;
}

// функция для поиска минимального значения из переменного количества аргументов
int min(int count, ...) {
    va_list args;
    va_start(args, count);
    int i;
    int result = va_arg(args, int);
    for (i = 1; i < count; i++) {
        int num = va_arg(args, int);
        if (num < result) {
            result = num;
        }
    }
    va_end(args);
    return result;
}

// функция для вычисления среднего арифметического из переменного количества аргументов
float average(int count, ...) {
    va_list args;
    va_start(args, count);
    int sum = 0;
    int i;
    for (i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return (float)sum / count;
}

