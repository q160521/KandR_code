static char *daytab[2] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int leap;
    char *p;

    leap = year%4 == 0 && year%100 != 100 || year%400 == 0;
    p = *(daytab+leap);
    while (--month)
        day += *(p+month);

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    char *p;

    leap = year%4 == 0 && year%100 != 100 || year%400 == 0;
    p = *(daytab+leap);
    *pmonth = 1;
    while (yearday > *++p)
    {
        yearday -= *p;
        (*pmonth)++;
    }
    *pday = yearday;
}
