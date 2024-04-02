#include <iostream>
#include "dayType.h"
using namespace std;

int main() {
    cout << "Creating a day object using the default constructor and printing the day:" << endl;
    dayType day1;
    day1.printDay(); // Output: Sunday

    cout << "the previous day:" << endl;
    cout << day1.getPrevDay() << endl; // Output: Saturday

    cout << "the next day:" << endl;
    cout << day1.getNextDay() << endl; // Output: Monday

    cout << "Creating a day object using the constructor with parameters and initializing the object to Monday:" << endl;
    dayType day2("Monday");

    cout << "Using get function to display the value of the instance variable:" << endl;
    cout << day2.getDay() << endl; // Output: Monday

    cout << "Adding 3 days to the current day:" << endl;
    day2.addDays(3);
    day2.printDay(); // Output: Thursday

    cout << "Adding 30 days to the current day:" << endl;
    day2.addDays(30);
    day2.printDay(); // Output: Saturday

    cout << "Adding 365 days to the current day:" << endl;
    day2.addDays(365);
    day2.printDay(); // Output: Sunday

    return 0;
}