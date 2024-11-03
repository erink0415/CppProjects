// copyright 2024 ekelly
#ifndef _PROGRAM2_FUNCTIONS_H_
#define _PROGRAM2_FUNCTIONS_H_

// function that sees if an int(year) is a leap year
bool LeapYear(int y);

// function that returns the number of days in a given month
// make year default to 0
int LastDayOfMonth(int m, int y = 0);

// function that will see if an inputted date is valid
bool ValidDate(int m, int d, int y);

// function that takes the inputted date and outputs the next day
int NextDate(int& m, int& d, int& y);

// function that takes the inputted date and outputs the previous day
int PreviousDate(int& m, int& d, int& y);

#endif
