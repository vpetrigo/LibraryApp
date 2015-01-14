#include "std_lib_facilities.h"
#include "Books.h"
#include "Patron.h"

struct Transaction {
    Transaction(const Book& b, const Patron& p, const Chrono::Date& d) : book{b}, patron{p}, date{d} {}

    Book book;
    Patron patron;
    Chrono::Date date;
};

class Library {
public:
    void read_books();
    void read_patrons();
    void book_chout(Patron& p, Book& b);

    const vector<Book> get_Books() const {
        return books;
    }

    const vector<Patron> get_Patrons() const {
        return patrons;
    }

    const vector<Transaction> get_Trans() const {
        return trans;
    }

    int is_user(const string& name, const string& l_cnum); // check if user with proper name and library cardnumber is in the database
    int is_book(const string& isbn);    // check by an isbn if a book in the library
    vector<Patron> have_arrears(); // output all patrons who have fees;

    static constexpr int nusr = -1;
    static constexpr int nbk = -1;
private:
    vector<Book> books;
    vector<Patron> patrons;
    vector<Transaction> trans;
};

/* Helper functions */
string read_str(); // Prompt process for obtaining data about a book
Genre read_genre(); // Asked user for genre of the current book

/* Overloaded functions */

ostream& operator<<(ostream& os, const Transaction& tr);