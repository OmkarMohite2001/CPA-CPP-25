#include "Date.h"

// Implementation of functions
struct Date* getDateInstance(int _day, int _month, int _year)
{
    struct Date* newDate = NULL;

    newDate = (struct Date*)malloc(sizeof(struct Date));
    if(newDate == NULL)
    {
        puts("Out of memory");
        exit(EXIT_FAILURE);
    }

    newDate->day = _day;
    newDate->month = _month;
    newDate->year = _year;

    return (newDate);
}

int getDay(struct Date* pDate)
{
    return (pDate->day);
}

int getMonth(struct Date* pDate)
{
    return (pDate->month);
}

int getYear(struct Date* pDate)
{
    return (pDate->year);
}

void setDay(struct Date* pDate, int newDay)
{
    pDate->day = newDay;
}

void setMonth(struct Date* pDate, int newMonth)
{
    pDate->month = newMonth;
}

void setYear(struct Date* pDate, int newYear)
{
    pDate->year = newYear;
}

void showDate(struct Date* pDate)
{
    printf("%d/%d/%d\n", pDate->day, pDate->month, pDate->year);
}

void releaseDate(struct Date* pDate)
{
    free(pDate);
    pDate = NULL;
}
