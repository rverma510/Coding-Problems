#include <cassert>

class Date {
public:
  Date(int day, int month, int year);
  int Day() const { return day_; }
  void Day(int day);
  int Month() const { return month_; }
  void Month(int month);
  int Year() const { return year_; }
  void Year(int year);
  int daysInMonth();

private:
  int day_{1};
  int month_{1};
  int year_{0};
};

Date::Date(int day, int month, int year) {
  Year(year);
  Month(month);
  Day(day);
}

void Date::Day(int day) {
  if (day >= 1 && day <= daysInMonth())
    day_ = day;
}

void Date::Month(int month) {
  if (month >= 1 && month <= 12)
    month_ = month;
}

void Date::Year(int year) { year_ = year; }

int Date::daysInMonth() {
    bool leapYear = false;
    if (year_ % 4 == 0) {
        if (year_ % 100 == 0) {
            if (year_ % 400 == 0) {
                leapYear = true;
            }
        }
        else {
            leapYear = true;
        }
    }
    if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12) {
        return 31;
    }
    else if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) {
        return 30;
    }
    else {
        if (leapYear)
            return 29;
        else
            return 28;
    }
}

// Test
int main() {
  Date date(29, 8, 1981);
  assert(date.Day() == 29);
  assert(date.Month() == 8);
  assert(date.Year() == 1981);
}