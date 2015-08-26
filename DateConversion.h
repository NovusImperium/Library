#ifndef DATECONVERSION_H
#define DATECONVERSION_H

// File: DateConversion.h
// Authors: Amandeep Gill
// Contents: This file contains a function that converts the date into the
// number of days using the Julian day conversion algorithm, and a fucntion
// that converts the number of days to a Date

#include <tr1/tuple>
using namespace std;

int julian_days(int year, int month, int day);

int* julian_to_date(int year, int month, int day);

#endif
