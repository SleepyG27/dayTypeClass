//implementation file for the class dayType

#include "dayType.h"
#include <iostream>
using namespace std;

string dayType::daysOfWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

dayType::dayType() {
    day = "Sunday";
}

dayType::dayType(string d) {
    setDay(d);
}

void dayType::setDay(string d) {
    day = d;
}

void dayType::printDay() {
    cout << day << endl;
}

string dayType::getDay() {
    return day;
}

string dayType::getNextDay() {
    int index = 0;
    for (int i = 0; i < 7; ++i) {
        if (daysOfWeek[i] == day) {
            index = i;
            break;
        }
    }
    return daysOfWeek[(index + 1) % 7];
}

string dayType::getPrevDay() {
    int index = 0;
    for (int i = 0; i < 7; ++i) {
        if (daysOfWeek[i] == day) {
            index = i;
            break;
        }
    }
    return daysOfWeek[(index - 1 + 7) % 7];
}

void dayType::addDays(int numDays) {
    int index = 0;
    for (int i = 0; i < 7; ++i) {
        if (daysOfWeek[i] == day) {
            index = i;
            break;
        }
    }
    day = daysOfWeek[(index + numDays) % 7];
}