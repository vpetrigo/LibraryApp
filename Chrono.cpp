#include "Chrono.h"

namespace Chrono {
  
  Date::Date(int year, Month mon, int day) : y{year}, m{mon}, d{day} {
    if (!is_date(year, mon, day))
      throw Invalid{};
  }
  
  const Date& dafault_date() {
    static Date def_date {2001, Month::Jan, 1};
    
    return def_date;
  }
  
  Date::Date() : y{dafault_date().year()},
    m{dafault_date().month()}, d{dafault_date().day()} { }

  void Date::add_year(int n) {
    if (m == Month::Feb && d == 29 && !leapyear(y + n)) {
      m = Month::Mar;
      d = 1;
    }
    
    y += n;
  }
  
  bool is_date(int y, Month m, int d) {
    if (d <= 0)
      return false;
    if (m < Month::Jan || Month::Dec < m)
      return false;

    int days_in_month = 31;

    switch(m) {
    case Month::Feb:
      days_in_month = leapyear(y) ? 29 : 28;
      break;
    case Month::Apr: case Month::Jun: case Month::Sep: case Month::Nov:
      days_in_month = 30;
      break;
    }

    if (days_in_month < d)
      return false;
    
    return true;
  }
  
  bool leapyear(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
      return true;
    else
      return false;
  }
  
  bool operator==(const Date& a, const Date& b) {
    return a.year() == b.year() && a.month() == b.month()
      && a.day() == b.day();
  }

  bool operator!=(const Date& a, const Date& b) {
    return !(a == b);
  }

  ostream& operator<<(ostream& os, const Date& a) {
    return os << '(' << a.year() << ", " << int(a.month())
	      << ", " << a.day() << ')';
  }
  
  istream& operator>>(istream& is, Date& a) {
    int y, m, d;
    char ch1, ch2, ch3, ch4;

    is >> ch1 >> d >> ch2 >> m >> ch3 >> y >> ch4;
    if (!is)
      return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
      is.clear(ios_base::failbit);
    
    return is;
  }
} // Chrono
