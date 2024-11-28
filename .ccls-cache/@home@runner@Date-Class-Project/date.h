// Date.h
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <array>

using namespace std;

class Date {
private:
    int month, day, year;

    // Array for the number of days in each month (index 0 is for January)
    static const array<int, 12> daysInMonth;

    // Helper function to check if a given year is a leap year
    bool isLeapYear(int year) const;

    // Helper function to get the number of days in a given month
    int getDaysInMonth(int month, int year) const;

    // Validate date
    void validateDate(int m, int d, int y);

public:
    // Default constructor sets the date to January 1, 1930
    Date();

    // Parameterized constructor to initialize date
    Date(int m, int d, int y);

    // Set date with validation
    void setDate(int m, int d, int y);

    // Getter functions
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    // Print date in MM/DD/YYYY format
    void printNumeric() const;

    // Print date in "Month Day, Year" format
    void printLong() const;

    // Print date in "Day Month Year" format
    void printDayMonthYear() const;

    // Overload prefix ++
    Date& operator++();

    // Overload postfix ++
    Date operator++(int);

    // Overload prefix --
    Date& operator--();

    // Overload postfix --
    Date operator--(int);

    // Overload stream insertion operator <<
    friend ostream& operator<<(ostream& os, const Date& date);

    // Overload stream extraction operator >>
    friend istream& operator>>(istream& is, Date& date);
};

#endif // DATE_H
