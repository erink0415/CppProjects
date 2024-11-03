// Copyright 2024 ekelly
#include"program2functions.h"

bool LeapYear(int y) {
    if ( y < 1 ) {
        return false;
    }
    if ( y % 400 == 0 ) {
        return true;
    } else if ( y % 100 == 0 ) {
        return false;
    } else if ( y % 4 == 0 ) {
        return true;
    } else {
        return false;
    }
}

// leap year is wrong here
int LastDayOfMonth(int m, int y) {
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        return 31;
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    } else if (m == 2 && LeapYear(y)) {
        return 29;
    } else if (m == 2 && y == 0) {
        return 0;
    } else if (m == 2 && !LeapYear(y)) {
        return 28;
    } else {
        return 0;
    }
}

bool ValidDate(int m, int d, int y) {
    if (m > 12 || m < 1 || d > 31 || d < 1 || y < 1) {
        return false;
    } else if ( d > LastDayOfMonth(m, y) ) {
        return false;
    } else {
        return true;
    }
}

int NextDate (int& m, int& d, int& y) {
    if (ValidDate(m, d, y)) {
        if ( d == LastDayOfMonth(m, y) ) {
            m++;
            d = 1;
            if ( m > 12 ) {
                y +=1;
                m = 1;
            }
        } else {
            d = d + 1;
            return 1;
        }

    } else {
        return 1;
    }
    return 0;
}

int PreviousDate(int& m, int& d, int& y) {
    if ( ValidDate(m, d, y) ) {
        if ( d == 1 ) {
            m--;
            if (m < 1) {
                m = 12;
                y--;
            }
            d = LastDayOfMonth(m, y);
        } else {
            d--;
        }
    }
    return 0;
}
