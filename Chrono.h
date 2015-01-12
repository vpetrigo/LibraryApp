#include "std_lib_facilities.h"

namespace Chrono {
  
  enum class Month {
    Jan = 1, Feb, Mar, Apr, May,
    Jun, Jul, Aug, Sep, Oct, Nov, Dec
  };

  class Date {
  public:
    class Invalid {}; // Used if something goes wrong
    Date(int y, Month m, int d);
    Date();

    int day() const {
      return d;
    }

    Month month() const {
      return m;
    }

    int year() const {
      return y;
    }

    void add_day(int n);
    void add_month(int n);
    void add_year(int n);
  private:
    int y;
    Month m;
    int d;
  };
  
  bool is_date(int y, Month m, int d);

  bool leapyear(int y);

  bool operator==(const Date& a, const Date& b);
  bool operator!=(const Date& a, const Date& b);

  ostream& operator<<(ostream& os, const Date& a);
  istream& operator>>(istream& is, Date& a);
} // Chrono
