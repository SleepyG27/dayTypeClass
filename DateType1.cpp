#include <iostream>
#include "Date.h"

int main() {
    int Month, Day, Year;
    Date customDate;


    // Set and print individual date components
    std::cout << "Enter the  month (1-12): ";
    std::cin >> Month; // Precondition: Month value must be within a valid range (1-12).
    customDate.setMonth(Month);

    std::cout << "Enter the day: ";
    std::cin >> Day; // Precondition: Day value must be within a valid range (1-31).
    customDate.setDay(Day);

    std::cout << "Enter the year (>= 1900): ";
    std::cin >> Year; // Precondition: Year value must be >= 1900.
    customDate.setYear(Year);

    // Print the updated custom date
    std::cout << " Date Entered : ";
    customDate.printDate();

    // Check if the year is a leap year
    std::cout << "Is the entered year a leap year? " << (customDate.isLeapYear() ? "Yes" : "No") << std::endl;

    // Print the number of days in the current month
    std::cout << "Number of days in the current month: " << customDate.daysInMonth() << std::endl;

    // Print the number of days passed since the beginning of the year
    std::cout << "Days passed since the beginning of the year: " << customDate.daysSinceYearStart() << std::endl;

    // Print the number of days remaining in the year
    std::cout << "Days remaining in the year: " << customDate.daysRemainingInYear() << std::endl;

    // Set the date to a future date
    int futureDays;
    std::cout << "Enter the number of days to set the date in the future: ";
    std::cin >> futureDays; // Precondition: days must be a non-negative integer.
    customDate.setFutureDate(futureDays);

    // Print the future date
    std::cout << "Date " << futureDays << " days in the future: ";
    customDate.printDate();

    return 0;
}