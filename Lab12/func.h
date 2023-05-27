void print_calendar(int month, int year)
{
    int start_day = get_start_day(month, year);
    int num_days = (month == 2 && is_leap_year(year)) ? 29 : (int[]){31,28,31,30,31,30,31,31,30,31,30,31}[month - 1];
    char months[][10] = {"", "January", "February", "March", "April", "May", "June",
                         "July", "August", "September", "October", "November", "December"};

    printf("\n%s %d\n", months[month], year);
    printf("--------------------\n");
    printf("Su Mo Tu We Th Fr Sa\n");

    int day = 1;
    int i;
    for (i = 0; i < 6; i++) {
    	int j;
        for (j = 0; j < 7; j++) {
            if (i == 0 && j < start_day) {
                printf("   ");
            } else if (day > num_days) {
                printf("\n");
                return;
            } else {
                printf("%2d ", day);
                day++;
            }
        }
        printf("\n");
    }
}

void print_month(int month, int year, int start_day, int num_days)
{
    char months[][10] = {"", "January", "February", "March", "April", "May", "June",
                         "July", "August", "September", "October", "November", "December"};
    printf("   %s %d\n", months[month], year);
    printf("--------------------\n");
    printf(" Su Mo Tu We Th Fr Sa\n");

    int day = 1;
    int i;
    for (i = 0; i < 6; i++) {
    	int j;
        for (j = 0; j < 7; j++) {
            if (i == 0 && j < start_day) {
                printf("   ");
            } else if (day > num_days) {
                printf("\n");
                return;
            } else {
                printf("%3d", day);
                day++;
            }
        }
        printf("\n");
    }
}

int is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int get_start_day(int month, int year)
{
    struct tm date = {.tm_year = year - 1900, .tm_mon = month - 1, .tm_mday = 1};
    mktime(&date);
    return date.tm_wday;
}

