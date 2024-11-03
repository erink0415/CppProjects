// Copyright 2024 ekelly
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::abs;
bool prime(int x);

int main() {
    int total, pos_neg, pn, en;
    char op, ope, ip;
    int totalPN = 1, newTotal;
    cin >> total >> op >> pos_neg >> ope;
    if (total == 0)
        cout << "Invalid input format." << endl;
    if (op != '=') {
        cout << "Invalid input format." << endl;
        return 0;
    }
    if (pos_neg > 1 && pos_neg < -1 && pos_neg != '0') {
        cout << "Invalid input format." << endl;
        return 0;
    }
    if (ope != '*') {
        cout << "Invalid input format." << endl;
        return 0;
    }
    do {
    int newPN = 1;
    newTotal = total;
    cin >> pn >> op >> en >> ip;
    // if statements to make sure every input is correct
    if (!prime(pn)) {
        cout << "Invalid input format." << endl;
        return 0;
    }
    if (op != '^') {
        cout << "Invalid input format." << endl;
        return 0;
    }
    if (en < 1) {
        cout << "Invalid input format." << endl;
        return 0;
    }
    for (int i = 1; i < en+1; ++i) {
        newPN *= pn;
    }
    // add together all newPN's
    // multiply by pos_neg
    totalPN *= newPN;
    } while (ip != '?');
    totalPN = totalPN * pos_neg;
    if (total == totalPN) {
        cout << "Correct!";
    } else {
        cout << "Incorrect. ";
        // getting positive or negative 1
        if (total < 0)
            pos_neg = -1;
        else
            pos_neg = 1;
        cout << total << " = " << pos_neg;
         // so total is positive for math
        for (int i = 2; i < abs(total); ++i) {
            int wrongEN = 0;
            if (prime(i)) {
                if (newTotal%i == 0) {
                    do {
                        wrongEN +=1;
                        newTotal = newTotal / i;
                    }  while (newTotal%i == 0);
                    cout  << " * " << i << "^" << wrongEN;
                }
            }
        }
    }
    cout << endl;
    return 0;
}
    bool prime(int x) {
        if (x < 1)
            return false;
        for (int i = 2; i < (x); ++i) {
                if (x % i == 0) {
                    return false;
                }
            }
        return true;
    }
