#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "func.h"

void print_calendar(int month, int year);
void print_month(int month, int year, int start_day, int num_days);
int is_leap_year(int year);
int get_start_day(int month, int year);

int main()
{
    char input[20];
    int year, month, day, start_day, num_days;

    printf("Enter a date (yyyy.mm.dd, yyyy.mm, yyyy or 'now'): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\r\n")] = 0; // remove newline

    if (strcmp(input, "now") == 0) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        year = tm.tm_year + 1900;
        month = tm.tm_mon + 1;
        day = tm.tm_mday;
    } else {
        if (sscanf(input, "%d.%d.%d", &year, &month, &day) != 3 &&
            sscanf(input, "%d.%d", &year, &month) != 2 &&
            sscanf(input, "%d", &year) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            printf("Invalid date.\n");
            return 1;
        }
    }

    start_day = get_start_day(month, year);
    num_days = (month == 2 && is_leap_year(year)) ? 29 : (int[]){31,28,31,30,31,30,31,31,30,31,30,31}[month - 1];

    if (day > 0 && day <= num_days) {
        struct tm date = {.tm_year = year - 1900, .tm_mon = month - 1, .tm_mday = day};
        char wday[10];
        strftime(wday, sizeof(wday), "%A", &date);
        printf("%04d.%02d.%02d is a %s.\n", year, month, day, wday);
    }

    if (day < 1 || day > num_days) {
        printf("Invalid day for month.\n");
    } else if (day == 1 && num_days == 28) {
        printf("%04d.%02d has 28 days.\n", year, month);
        print_calendar(month, year);
    } else if (day == 1 && num_days == 29) {
        printf("%04d.%02d has 29 days.\n", year, month);
        print_calendar(month, year);
    } else if (day > 1) {
        printf("%04d.%02d has %d days.\n", year, month, num_days);
        print_month(month, year, start_day, num_days);
    } else if (day == 1) {
        printf("%04d has 12 months.\n", year);
        int i;
        for (i = 1; i <= 12; i++) {
            printf("\n%d/%04d\n", i, year);
            start_day = get_start_day(i, year);
            num_days = (i == 2 && is_leap_year(year)) ? 29 : (int[]){31,28,31,30,31,30,31,31,30,31,30,31}[i - 1];
            print_month(i, year, start_day, num_days);
        }
    }

    return 0;
}
