// File: Date.cpp
// Author:
// Contents: This file contains the implementation of a class called Date.

#include <iostream>
#include <iomanip>
#include <sstream>

#include "Date.h"

using namespace std;

Date::Date (void) {
    month = day = year = -1;
}

Date::Date (const Date & D) {
    month = D.month;
    day = D.day;
    year = D.year;
}

Date::Date (string date) {
    int slash1 = date.find("/");
    int slash2 = date.rfind("/");

    string mm = date.substr(0, slash1);
    string dd = date.substr(slash1+1, slash2);
    string yy = date.substr(slash2+1);

    month = atoi(mm.c_str());
    day = atoi(dd.c_str());
    year = atoi(yy.c_str());
}

Date::Date (int inMonth, int inDay, int inYear) {
    month = inMonth;
    day = inDay;
    year = inYear;
}

Date & Date::operator = (const Date & D) {
    month = D.month;
    day = D.day;
    year = D.year;

    return *this;
}

void Date::SetDate (string date) {
    int slash1 = date.find("/");
    int slash2 = date.rfind("/");

    string mm = date.substr(0, slash1);
    string dd = date.substr(slash1+1, slash2);
    string yy = date.substr(slash2+1);

    month = atoi(mm.c_str());
    day = atoi(dd.c_str());
    year = atoi(yy.c_str());
}

void Date::SetMonth (int inMonth) {
    month = inMonth;
}

void Date::SetDay (int inDay) {
    day = inDay;
}

void Date::SetYear (int inYear) {
    year = inYear;
}

string Date::GetDate (void) const {
    string date;
    stringstream ss(date);
    ss << month << "/" << day << "/" << year;

    return date;
}

int Date::GetMonth (void) const {
    return month;
}

int Date::GetDay (void) const {
    return day;
}

int Date::GetYear (void) const {
    return year;
}

void Date::SetNull(void) {
    day = month = year = -1;
}

bool Date::IsNull(void) const {
    return (day == -1 || month == -1 || year == -1) ? true : false;
}

Date Date::Today(void) {
    time_t t = time(0);
    struct tm *now = localtime(&t);
    return Date(now->tm_mon + 1, now->tm_mday, now->tm_year + 1900);
}

int Date::operator - (const Date & D) const {
    return IsNull() ? julian_days(D.year, D.month, D.day) : julian_days(year, month, day) - julian_days(D.year, D.month, D.day);
}

Date Date::operator + (int days) {
    int *date = julian_to_date(year, month, day + days);
    Date formatted_date(date[1], date[2], date[0]);
    delete date;
    return formatted_date;
}

bool Date::operator < (const Date & D) const {
    if (!IsNull()) {
        if (year != D.year)
            return year < D.year;

        else if (month != D.month)
            return month < D.month;

        else
            return day < D.day;
    }
    else
        return D.IsNull() ? false : true;
}

bool Date::operator > (const Date & D) const {
    if (!IsNull()) {
        if (year != D.year)
            return year > D.year;

        else if (month != D.month)
            return month > D.month;

        else
            return day > D.day;
    }
    else
        return D.IsNull() ? false : true;
}

bool Date::operator == (const Date & D) const {
    return julian_days(year, month, day) == julian_days(D.year, D.month, D.day);
}

istream & operator >> (istream & ins, Date & D) {
    ins >> D.month;
    ins.ignore();
    ins >> D.day;
    ins.ignore();
    ins >> D.year;

    return ins;
}

ostream & operator << (ostream & outs, const Date & D) {
    outs << setw(2) << setfill('0');

    if (!D.IsNull()) 
         outs <<  D.month << "/" << D.day << "/" << D.year;
    else
        outs << "00/00/00";

    return outs;
}


