// Date.cpp
#include "date.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <array>

using namespace std;

// Initialize the static array of days in each month
const array<int, 12> Date::daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Default constructor sets the date to January 1, 1930
Date::Date() : month(1), day(1), year(1930) {}

// Parameterized constructor to initialize date
Date::Date(int m, int d, int y) {
    validateDate(m, d, y);
    month = m;
    day = d;
    year = y;
}

// Set date with validation
void Date::setDate(int m, int d, int y) {
    validateDate(m, d, y);
    month = m;
    day = d;
    year = y;
}

// Getter functions
int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }

// Helper function to check if a given year is a leap year
bool Date::isLeapYear(int year) const {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Helper function to get the number of days in a given month
int Date::getDaysInMonth(int month, int year) const {
    if (month < 1 || month > 12)
        throw invalid_argument("Invalid month");
    if (month == 2 && isLeapYear(year))
        return 29;  // February in a leap year has 29 days
    return daysInMonth[month - 1];
}

// Validate date
void Date::validateDate(int m, int d, int y) {
    if (m < 1 || m > 12)
        throw invalid_argument("Invalid month");
    if (d < 1 || d > getDaysInMonth(m, y))
        throw invalid_argument("Invalid day for the given month and year");
    if (y < 1)
        throw invalid_argument("Invalid year");
}

// Print date in MM/DD/YYYY format
void Date::printNumeric() const {
    cout << setw(2) << setfill('0') << month << "/"
         << setw(2) << setfill('0') << day << "/"
         << year << endl;
}

// Print date in "Month Day, Year" format
void Date::printLong() const {
    static const array<string, 12> monthNames = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    
    cout << monthNames[month - 1] << " " << day << ", " << year << endl;
}

// Print date in "Day Month Year" format
void Date::printDayMonthYear() const {
    static const array<string, 12> monthNames = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    
    cout << day << " " << monthNames[month - 1] << " " << year << endl;
}

// Overload prefix ++
Date& Date::operator++() {
    if (day < getDaysInMonth(month, year)) {
        ++day;
    } else {
        day = 1;
        if (month == 12) {
            month = 1;
            ++year;
        } else {
            ++month;
        }
    }
    return *this;
}

// Overload postfix ++
Date Date::operator++(int) {
    Date temp = *this;
    ++(*this);
    return temp;
}

// Overload prefix --
Date& Date::operator--() {
    if (day > 1) {
        --day;
    } else {
        if (month == 1) {
            month = 12;
            --year;
        } else {
            --month;
        }
        day = getDaysInMonth(month, year);
    }
    return *this;
}

// Overload postfix --
Date Date::operator--(int) {
    Date temp = *this;
    --(*this);
    return temp;
}

// Overload stream insertion operator <<
ostream& operator<<(ostream& os, const Date& date) {
    static const array<string, 12> monthNames = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};

    os << monthNames[date.month - 1] << " " << date.day << ", " << date.year;
    return os;
}

// Overload stream extraction operator >>
istream& operator>>(istream& is, Date& date) {
    int m, d, y;
    char slash;
    is >> m >> slash >> d >> slash >> y;

    if (is.fail()) {
        throw invalid_argument("Invalid input format.");
    }

    date.setDate(m, d, y);
    return is;
}
