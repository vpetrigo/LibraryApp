#include "Books.h"

bool Book::isbn_check(const string& isbn) {
  int num = 0, hyphen = 0;
  int pos = 0;

  for (int i = 0; i < isbn.size() && hyphen != 3; ++i) {
    if (isdigit(isbn[i]))
      continue;
    else if (isbn[i] == '-') {
      ++hyphen;
      pos = i;
    }
    else
      return false;
  }

  if (hyphen < 3)
    return false;

  for (int i = pos + 1; i < isbn.size(); ++i)
    if (!isalnum(isbn[i]))
      return false;

  return true;
}

const string& Book::isbn_get() const {
  return isbn;
}

const string& Book::author_get() const {
  return author;
}

const string& Book::title_get() const {
  return title;
}

const Chrono::Date& Book::cdate_get() const {
  return cr_date;
}

const Genre& Book::genre_get() const {
  return genre;
}

bool Book::have_book() {
  return (check_out) ? true : false;
}

bool operator==(const Book& f, const Book& s) {
  return f.isbn_get() == s.isbn_get();
}

bool operator!=(const Book& f, const Book& s) {
  return !(f == s);
}

ostream& operator<<(ostream& os, const Book& b) {
  return os << "Author: " << b.author_get() << '\n'
	    << "Title: " << b.title_get() << '\n' 
	    << "ISBN: " << b.isbn_get() << '\n';
}
