#include <stdio.h>
#include <stdbool.h>
typedef struct {
    int day, month, year;
} Date;
bool isLeapYear(int year) {
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}
int daysInMonth(int month, int year) {
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}
bool isValidDate(Date d) {
    if (d.year < 1 || d.month < 1 || d.month > 12 || d.day < 1)
        return false;
    int maxDays = daysInMonth(d.month, d.year);
    if (d.day > maxDays)
        return false;
    return true;
}
Date inputDate() {
    Date d;
    do {
        printf("Enter date (dd mm yyyy): ");
        scanf("%d %d %d", &d.day, &d.month, &d.year);
        if (!isValidDate(d))
            printf("Invalid date, please try again.\n");
    } while (!isValidDate(d));
    return d;
}
Date nextDay(Date d) {
    d.day++;
    if (d.day > daysInMonth(d.month, d.year)) {
        d.day = 1;
        d.month++;
        if (d.month > 12) {
            d.month = 1;
            d.year++;
        }
    }
    return d;
}
int dateToDays(Date d) {
    int days = 0;
    for (int y = 1; y < d.year; y++) 
        days += isLeapYear(y) ? 366 : 365;
    for (int m = 1; m < d.month; m++) 
        days += daysInMonth(m, d.year);
    days += d.day;
    return days;
}
int dateDifference(Date d1, Date d2) {
    int days1 = dateToDays(d1);
    int days2 = dateToDays(d2);
    int diff = days1 - days2;
    return diff >= 0 ? diff : -diff;
}
int main() {
    printf("Enter first date:\n");
    Date d1 = inputDate();
    printf("Enter second date:\n");
    Date d2 = inputDate();
    
    Date nd = nextDay(d1);
    printf("Next day of %02d/%02d/%04d is %02d/%02d/%04d\n",
           d1.day, d1.month, d1.year, nd.day, nd.month, nd.year);

    int diff = dateDifference(d1, d2);
    printf("Difference between %02d/%02d/%04d and %02d/%02d/%04d is %d day(s)\n",
           d1.day, d1.month, d1.year, d2.day, d2.month, d2.year, diff);
    return 0;
}