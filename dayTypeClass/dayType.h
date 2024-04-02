#ifndef DAYTYPE_H
#define DAYTYPE_H

#include <string>
using namespace std;

class dayType {
private:
    static string daysOfWeek[7];
    string day;

public:
    //Constructors
    dayType();
    dayType(string d);
    //Funtions
    void setDay(string d);
    void printDay();
    string getDay();
    string getNextDay();
    string getPrevDay();
    void addDays(int numDays);
};

#endif
