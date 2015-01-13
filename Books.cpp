#include "Books.h"

bool Book::isbn_check() {
  int pos = 0;
  int (*analyse_fun)(int); // pointer to char analyser function

  vector<string> isbn_parts;

  while (pos < isbn.size()) { // Here we split ISBN number we have by hyphen
    string part;
    for ( ; pos < isbn.size() && isbn[pos] != '-'; ++pos)
      part += isbn[pos];

    if (isbn[pos] == '-')
      ++pos;

    isbn_parts.push_back(part);
  }

  if (isbn_parts.size() != Book::isbn_len)
    return false;

  for (int i = 0; i < Book::isbn_len; ++i) { // check first three parts of ISBN number which has to be numbers
    if (isbn_parts[i].size() == 0)
      return false;

    analyse_fun = (i != Book::isbn_len - 1) ? (int (*)(int)) isdigit : (int (*)(int)) isalnum;

    for (int j = 0; j < isbn_parts[i].size(); ++j)
      if (!analyse_fun(isbn_parts[i][j])) // Check if the first three parts of ISBN
        return false;                     // is numbers and the last one might be
  }                                       // either number or alphabet characters

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
          << "ISBN: " << b.isbn_get() << '\n'
          << "Genre: " << b.genre_str() << '\n';
}

const string& Book::genre_str() const {
  static const vector<string> gen_str = {"fiction", "nonfiction", "periodical", "biography", "children"};

  return gen_str[static_cast<int>(genre) - 1];
}
