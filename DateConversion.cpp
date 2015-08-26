// File: DateConversion.cpp
// Author: Amandeep Gill
// Contents: the definition of the DateConversion function prototypes

using namespace std;

int julian_days(int year, int month, int day) {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;

    if (year > 1582 || (year == 1582 && month > 10) || (year == 1582 && month == 10 && day >= 15))
        return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    else
        return day + (153 * m + 2) / 5 + 365 * y + y / 4 - 32083;
}

int* julian_to_date(int year, int mo, int day) {
    int day_of_year = julian_days(year, mo, day) - julian_days(year, 0, 0);
    static const int month_len[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int leap = (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
    int day_of_month = day_of_year;
    int month;
    for (month = 0; month < 12; month ++) {
        int mlen = month_len[month];
        if (leap && month == 1)
            mlen ++;
        if (day_of_month <= mlen)
            break;
        day_of_month -= mlen;
    }

    int *date = new int[3];
    date[0] = year;
    date[1] = month;
    date[2] = day_of_month;

    return date;
}
