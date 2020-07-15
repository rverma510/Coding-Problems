#include <iostream>
#include <cassert>

class Date{
    int day{1};
    int month{1};
    int year{2000};
    public:
        void Day(int d) {
            if (d >= 1 && d <= 31)
                day = d;
        }
        int Day() {
            return day;
        }
        void Month(int m) {
            if (m >= 1 && m <= 12)
                month = m;
        }
        int Month() {
            return month;
        }
        void Year(int y) {
            if (y >= 0)
                year = y;
        }
        int Year() {
            return year;
        }
};

// Test in main
int main()
{
    Date date;
    date.Day(-1);
    date.Month(14);
    date.Year(2000);
    assert(date.Day() != -1);
    assert(date.Month() != 14);
    assert(date.Year() == 2000);
}
