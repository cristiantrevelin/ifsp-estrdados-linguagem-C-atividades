#ifndef CT_DATE_H
#define CT_DATE_H

#include <time.h>

typedef struct sDate
{
    int day;
    int month;
    int year;

} DATE;

typedef struct sTime
{
    int hour;
    int minute;
    int second;

} TIME;

typedef struct sDatetime
{
    DATE date;
    TIME time;

} DATETIME;

DATETIME ct_getlocal_dttm ()
{
    time_t t;
    struct tm *tm;
    DATETIME datetime;

    t = time(NULL);
    tm = localtime(&t);

    datetime.date.year = tm -> tm_year + 1900;
    datetime.date.month = tm -> tm_mon + 1;
    datetime.date.day = tm -> tm_mday;
    datetime.time.hour = tm -> tm_hour;
    datetime.time.minute = tm -> tm_min;
    datetime.time.second = tm -> tm_sec;

    return datetime;
}

int ct_compare_dt (DATE first, DATE second)
{
    int comparison = 0;

    if (first.year > second.year)
        comparison = 1;
    else if (first.year < second.year)
        comparison = -1;
    else
    {
        if (first.month > second.month)
            comparison = 1;
        else if (first.month < second.month)
            comparison = -1;
        else
        {
            if (first.day > second.day)
                comparison = 1;
            else if (first.day < second.day)
                comparison = -1;
        }
    }

    return comparison;
}

int ct_compare_tm (TIME first, TIME second)
{
    int comparison = 0;

    if (first.hour > second.hour)
        comparison = 1;
    else if (first.hour < second.hour)
        comparison = -1;
    else
    {
        if (first.minute > second.minute)
            comparison = 1;
        else if (first.minute < second.minute)
            comparison = -1;
        else
        {
            if (first.second > second.second)
                comparison = 1;
            else if (first.second < second.second)
                comparison = -1;
        }
    }

    return comparison;
}

int ct_compare_dttm (DATETIME first, DATETIME second)
{
    int comparison;
    comparison = ct_compare_dt(first.date, second.date);

    if (comparison == 0)
        comparison = ct_compare_tm(first.time, second.time);

    return comparison;
}

#endif // CT_DATE_H
