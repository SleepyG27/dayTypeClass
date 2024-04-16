#ifndef DATE_H
#define DATE_H

class Date {
private:
    int month;
    int day;
    int year;

    bool isValidDate(int month, int day, int year);
    bool isLeapYear(int year) const;
    int daysInMonth(int month, int year) const;

public:
    Date(int month = 1, int day = 1, int year = 1900);
    void setDate(int month, int day, int year);
    void setMonth(int month);
    void setDay(int day);
    void setYear(int year);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    bool isLeapYear() const;
    int daysInMonth() const;
    void printDate() const;
    int daysSinceYearStart() const;
    int daysRemainingInYear() const;
    void setFutureDate(int days);
};

#endif // DATE_H