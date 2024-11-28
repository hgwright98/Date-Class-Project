#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int month, day, year;

    // This is an array for the number of days in each month
    static const int daysInMonth[12];

    // This is a function(helper) to check if a given year is a leap year
    bool isLeapYear(int year) const;

    // This is a function(helper) to get the number of days in a given month
    int getDaysInMonth(int month, int year) const;

    // Validate date
    void validateDate(int m, int d, int y);

public:
    // This is a default constructor sets the date to January 1, 1930
    // Pre-condition: None
    Date();
    // Post-condition: The Date object is initialized to 01/01/1930

    // This is a parameterized constructor to initialize date
    // Pre-condition: m is between 1 and 12, d is valid for the given month/year, y is a valid year
    Date(int m, int d, int y);
    // Post-condition: The Date object is initialized to the provided m/d/y, assuming valid input

    // This sets the date with validation
    // Pre-condition: m is between 1 and 12, d is valid for the given month/year, y is a valid year
    void setDate(int m, int d, int y);
    // Post-condition: The Date object is set to the provided m/d/y, assuming valid input; otherwise, it may throw an exception or handle invalid input

    // These are the getter functions
    // Pre-condition: None
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    // Post-condition: These return the corresponding member (month, day, or year) of the Date object

    // This prints the date in MM/DD/YYYY format
    // Pre-condition: None
    void printNumeric() const;
    // Post-condition: This outputs the date in MM/DD/YYYY format

    // This prints the date in "Month Day, Year" format
    // Pre-condition: None
    void printLong() const;
    // Post-condition: This outputs the date in "Month Day, Year" format

    // This prints the date in "Day Month Year" format
    // Pre-condition: None
    void printDayMonthYear() const;
    // Post-condition: This outputs the date in "Day Month Year" format

    // This is an overload prefix ++
    // Pre-condition: None
    Date& operator++();
    // Post-condition: This increments the date by one day and returns a reference to the updated Date object

    // This is an overload postfix ++
    // Pre-condition: None
    Date operator++(int);
    // Post-condition: This increments the date by one day and returns a new Date object representing the original value before the increment

    // This is a overload prefix --
    // Pre-condition: None
    Date& operator--();
    // Post-condition: This decrements the date by one day and returns a reference to the updated Date object

    // This is an overload postfix --
    // Pre-condition: None
    Date operator--(int);
    // Post-condition: This decrements the date by one day and returns a new Date object representing the original value before the decrement

    // This is an overload stream insertion operator <<
    // Pre-condition: os is a valid output stream and date is a valid Date object
    friend ostream& operator<<(ostream& os, const Date& date);
    // Post-condition: Thi outputs the Date object to the stream in a readable format (usually MM/DD/YYYY)

    // This is an overload stream extraction operator >>
    // Pre-condition: is is a valid input stream
    friend istream& operator>>(istream& is, Date& date);
    // Post-condition: The Date object is modified to reflect the date parsed from the input stream
};    

#endif // DATE_H

