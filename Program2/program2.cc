// Copyright 2024 ekelly
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include"program2functions.h"

int main() {
    //
    int days = 0;
    int m, d, y, m2, d2, y2;
    char s, s1, s2, s3;
    cin >> m >> s >> d >> s1 >> y >> m2 >> s2 >> d2 >> s3 >> y2;
    if ( !ValidDate(m, d, y) && ValidDate(m2, d2, y2) ) {
        cout << m << "/" << d << "/" << y << " is not a valid date" << endl;
        return 0;
    } else if ( !ValidDate(m, d, y) && !ValidDate(m2, d2, y2) ) {
        cout << m << "/" << d << "/" << y << " is not a valid date" << endl;
        cout << m2 << "/" << d2 << "/" << y2 << " is not a valid date" << endl;
        return 0;
    } else if ( !ValidDate(m2, d2, y2) && ValidDate(m, d, y) ) {
        cout << m2 << "/" << d2 << "/" << y2 << " is not a valid date" << endl;
        return 0;
    }
    cout << m << "/" << d << "/" << y << " is ";
    if ( y < y2 ) {
    // the first year is less so date1 has to be before
        while (d < d2 || m < m2 || y < y2) {
            NextDate(m, d, y);
            days++;
        }
        cout << days << " days before " << m2 << "/" << d2 << "/" << y << endl;
    } else if (y == y2) {
    // year is equal so the month has to be less than other month or month
    // is same and day is less
        if (m < m2) {
            while (d < d2 || m < m2 || y < y2) {
                NextDate(m, d, y);
                days++;
            }
            cout << days << " days before " << m2 << "/";
            cout << d2 << "/" << y << endl;
        } else if ( m == m2 && d < d2 ) {
            while (d < d2 || m < m2 || y < y2) {
                NextDate(m, d, y);
                days++;
            }
            cout << days << " days before " << m2 << "/";
            cout << d2 << "/" << y << endl;
        } else if ( m2 == m && d2 == d ) {
            days = 0;
            cout << days << " days before " << m2 << "/";
            cout << d2 << "/" << y << endl;
        } else if (m2 < m) {
            // year is equal do the month2 has to be less
            // than other month or month is same and day2 is less
            while (d > d2 || m > m2 || y > y2) {
                PreviousDate(m, d, y);
                days++;
            }
            cout << days << " days after " << m2 << "/";
            cout << d2 << "/" << y << endl;
        } else if ( m2 == m && d2 < d ) {
            while (d > d2) {
                PreviousDate(m, d, y);
                days++;
            }
            cout << days << " days after " << m2 << "/";
            cout << d2 << "/" << y << endl;
        }
    } else if (y2 < y) {
    // the second year is less so date2 has to be before
        while (d2 < d || m2 < m || y2 < y) {
                    PreviousDate(m, d, y);
                    days++;
        }
        cout << days << " days after " << m2 << "/" << d2 << "/" << y << endl;
    }
    return 0;
}
