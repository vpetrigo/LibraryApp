#include "std_lib_facilities.h"
#include "Chrono.h"

enum class Genre {
    fiction = 1, nonfiction, periodical,
    biography, children
};

class Book {
public:
    class Invalid {};
    const int isbn_len = 4; // ISBN pattern is Num-Num-Num-(Num | Alph); 4 parts at all

    Book(const string& author, const string& title, const string& isbn, const Chrono::Date& cr_date, bool ch_out, const Genre& gen) :
       author{author}, title{title}, isbn{isbn}, cr_date{cr_date}, check_out{ch_out}, genre{gen} {
         if (!isbn_check())
          throw Invalid{};
      }

    bool isbn_check();
    bool have_book();
    const string& isbn_get() const;
    const string& author_get() const;
    const string& title_get() const;
    const Chrono::Date& cdate_get() const;
    const Genre& genre_get() const;
    const string& genre_str() const;
private:
    bool check_out;
    string isbn;
    string author;
    string title;
    Chrono::Date cr_date;
    Genre genre;
};

bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);

ostream& operator<<(ostream& os, const Book& b);
