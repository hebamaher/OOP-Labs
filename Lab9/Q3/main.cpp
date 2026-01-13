#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() {
        day = 1;
        month = 1;
        year = 2000;
    }

    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    Date(const Date& other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }

    void printDate() {
        cout << day << "/" << month << "/" << year << endl;
    }

    int operator-(const Date& other) {
        return (year - other.year) * 365 + (month - other.month) * 30 + (day - other.day);
    }

    Date operator+(int days) {
        Date result(*this);
        result.day += days;
        while (result.day > 30) {
            result.day -= 30;
            result.month++;
        }
        while (result.month > 12) {
            result.month -= 12;
            result.year++;
        }
        return result;
    }

    Date& operator++() {
        day++;
        if (day > 30) {
            day = 1;
            month++;
        }
        if (month > 12) {
            month = 1;
            year++;
        }
        return *this;
    }

    Date operator++(int) {
        Date temp(*this);
        day++;
        if (day > 30) {
            day = 1;
            month++;
        }
        if (month > 12) {
            month = 1;
            year++;
        }
        return temp;
    }

    void operator=(const Date& other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }

    bool operator==(const Date& other) {
        return day == other.day && month == other.month && year == other.year;
    }

    int operator[](char ch) {
        switch (ch) {
            case 'd': case 'D': return day;
            case 'm': case 'M': return month;
            case 'y': case 'Y': return year;
            default: return 0;
        }
    }
};

int main() {
    Date d1;
    Date d2(1, 1, 2001);
    Date d3 = d2;

    d1.printDate();
    d2.printDate();
    d3.printDate();

    int diff = d2 - d1;
    cout << "Difference in days = " << diff << endl;

    d3 = d2 + 10;
    d3.printDate();

    d3 = ++d2;
    d2.printDate();
    d3.printDate();

    d3 = d2++;
    d2.printDate();
    d3.printDate();

    d1 = d2;
    d1.printDate();

    cout << "d1 == d2 " << (d1 == d2) << endl;

    cout << "Day = " << d2['d'] << ", Month = " << d2['m'] << ", Year = " << d2['y'] << endl;

    return 0;
}
