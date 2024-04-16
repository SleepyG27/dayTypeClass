#include "Date.h"
#include <iostream>

// Precondition: Month, day, and year values must be within valid ranges.
// Postcondition: Initializes a Date object with the given month, day, and year.
Date::Date(int month, int day, int year) {
    setDate(month, day, year);
}

// Precondition: Month, day, and year values must be within valid ranges.
// Postcondition: Sets the date of the Date object to the given month, day, and year.
void Date::setDate(int month, int day, int year) {
    if (isValidDate(month, day, year)) {
        this->month = month;
        this->day = day;
        this->year = year;
    }
    else {
        std::cerr << "Invalid date!" << std::endl;
    }
}

// Precondition: Month value must be within a valid range (1-12).
// Postcondition: Sets the month of the Date object to the given value.
void Date::setMonth(int month) {
    if (month >= 1 && month <= 12) {
        this->month = month;
    }
    else {
        std::cerr << "Invalid month!" << std::endl;
    }
}

// Precondition: Day value must be within a valid range for the current month and year.
// Postcondition: Sets the day of the Date object to the given value.
void Date::setDay(int day) {
    if (day >= 1 && day <= daysInMonth()) {
        this->day = day;
    }
    else {
        std::cerr << "Invalid day!" << std::endl;
    }
}

// Precondition: Year value must be >= 1900.
// Postcondition: Sets the year of the Date object to the given value.
void Date::setYear(int year) {
    if (year >= 1900) {
        this->year = year;
    }
    else {
        std::cerr << "Year must be >= 1900!" << std::endl;
    }
}

// Precondition: None.
// Postcondition: Returns the month of the Date object.
int Date::getMonth() const {
    return month;
}

// Precondition: None.
// Postcondition: Returns the day of the Date object.
int Date::getDay() const {
    return day;
}

// Precondition: None.
// Postcondition: Returns the year of the Date object.
int Date::getYear() const {
    return year;
}

// Precondition: None.
// Postcondition: Returns true if the year of the Date object is a leap year, false otherwise.
bool Date::isLeapYear() const {
    return isLeapYear(year);
}

// Precondition: None.
// Postcondition: Returns the number of days in the month of the Date object.
int Date::daysInMonth() const {
    return daysInMonth(month, year);
}

// Precondition: None.
// Postcondition: Prints the date of the Date object in the format mm-dd-yyyy.
void Date::printDate() const {
    std::cout << month << "-" << day << "-" << year << std::endl;
}

// Precondition: None.
// Postcondition: Returns the number of days passed since the beginning of the year to the current date.
int Date::daysSinceYearStart() const {
    int days = 0;
    for (int m = 1; m < month; ++m) {
        days += daysInMonth(m, year);
    }
    days += day;
    return days;
}

// Precondition: None.
// Postcondition: Returns the number of days remaining in the year from the current date to the end of the year.
int Date::daysRemainingInYear() const {
    int days = 0;
    for (int m = month + 1; m <= 12; ++m) {
        days += daysInMonth(m, year);
    }
    days += (isLeapYear() && month <= 2) ? (29 - day) : (28 - day);
    return days;
}

// Precondition: days must be a non-negative integer.
// Postcondition: Sets the date of the Date object to a future date by adding the number of days.
void Date::setFutureDate(int days) {
    int totalDays = daysSinceYearStart() + days;
    int y = year;
    int m = 1;
    while (totalDays > daysInMonth(m, y)) {
        totalDays -= daysInMonth(m, y);
        ++m;
        if (m > 12) {
            m = 1;
            ++y;
        }
    }
    setDate(m, totalDays, y);
}

// Precondition: Month, day, and year values must be within  range.
// Postcondition: Returns true if the provided month, day, and year form a valid date, false otherwise.
bool Date::isValidDate(int month, int day, int year) {
    if (month < 1 || month > 12 || year < 1900) {
        return false;
    }
    int maxDay = daysInMonth(month, year);
    return (day >= 1 && day <= maxDay);
}

// Precondition: Month and year values must be within valid ranges.
// Postcondition: Returns the number of days in the month and year.
int Date::daysInMonth(int month, int year) const {
    switch (month) {
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return (isLeapYear(year) ? 29 : 28);
    default:
        return 31;
    }
}

// Precondition: Year value must be >= 1900.
// Postcondition: Returns true if the year is a leap year, false otherwise.
bool Date::isLeapYear(int year) const {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}