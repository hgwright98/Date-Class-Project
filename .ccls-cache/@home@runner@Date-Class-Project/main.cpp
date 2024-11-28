// main.cpp
#include "date.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    try {
        // Create a Date object using default constructor
        cout << "Default constructor: " << endl;
        cout << "---------------------------" << endl;
        Date date1;
        date1.printNumeric();
        date1.printLong();
        date1.printDayMonthYear();
        cout << endl;
        
        // Create a Date object using parameterized constructor
        cout << "Parameterized Constructor: " << endl;
        cout << "---------------------------" << endl;
        Date date2(2, 29, 2020);  // Leap year date
        date2.printNumeric();
        cout << endl;
        
        // Test increment operators
        cout << "Increment Operators: " << endl;
        cout << "---------------------------" << endl;
        cout << "Starting Date: ";
        date2.printNumeric();
        ++date2;  // Move to March 1, 2020
        cout << "Adding 1 day to the starting date: ";
        date2.printNumeric();
        date2++;  // Move to March 2, 2020
        cout << "Adding 2 days to the starting date: ";
        date2.printNumeric();
        cout << endl;

        // Test decrement operators
        cout << "Decrement Operators: " << endl;
        cout << "---------------------------" << endl;
        cout << "Starting Date: ";
        date2.printNumeric();
        --date2;  // Move to March 1, 2020
        cout << "Subtracting 1 day from the starting date: ";
        date2.printNumeric();
        date2--;  // Move to February 29, 2020
        cout << "Subtracting 2 days from the starting date: ";
        date2.printNumeric();
        cout << endl;

        // Test input from user
        cout << "Input from the user: " << endl;
        cout << "---------------------------" << endl;
        Date date3;
        cout << "Enter a date (MM/DD/YYYY): ";
        cin >> date3;
        date3.printLong();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
