#ifndef _DATE_H 
#define _DATE_H 

// Header file inclusion
#include <stdio.h>
#include <stdlib.h>

// Type declarations
struct Date
{
    int day;
    int month;
    int year;
};

// Functions declarations
struct Date* getDateInstance(int _day, int _month, int _year);
int getDay(struct Date* pDate);
int getMonth(struct Date* pDate);
int getYear(struct Date* pDate);
void setDay(struct Date* pDate, int newDay);
void setMonth(struct Date* pDate, int newMonth);
void setYear(struct Date* pDate, int newYear);
void showDate(struct Date* pDate);
void releaseDate(struct Date* pDate);


#endif /* _DATE_H */