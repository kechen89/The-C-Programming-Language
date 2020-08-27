#include <stdio.h>
/* Exercise 5.9. Rewrite the routines day_of_year and month_day with pointers instead of indexing */

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);

int month_day(int year, int yearday, int *pmonth, int *pday);


int main()
{
    int m, d;
    month_day(1988, 60, &m, &d);
    printf("%dth day in Month %d\n", d, m);
    
    
    int yearday = day_of_year(1988, 2, 29);
    printf("%dth day in the year\n", yearday);
    return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    
    if (year > 0 && month >= 1 && month <= 12 && day >= 1 && day <= 31)
    {
        leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        for (i = 1; i < month; i++)
            day += *(*(daytab + leap) + i);
        return day;
    }
    else
        return -1;
}

/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    
    if (year < 1 || yearday < 1 || yearday > 366)
    {
        *pmonth = -1;
        *pday = -1;
        return -1;
    }
    else
    {
        leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        for (i = 1; yearday > daytab[leap][i]; i++)
            yearday -= *(*(daytab + leap) + i);
        *pmonth = i;
        *pday = yearday;
        return 0;
    }
}
