#include "Library.h"

void Library::read_books() {
    while (cin) {
        cout << "\nEnter the author: ";
        string author;

        author = read_str();

        cout << "\nEnter the title: ";
        string title;

        title = read_str();

        string isbn;

        cout << "\nEnter the ISBN: ";

        cin >> isbn;

        cout << "\nEnter the genre of this book.\n";

        Genre gen = read_genre();

        int year = 0, mon = 0, day = 0;

        cout << "\nEnter the date of release (format: YY MM DD): ";
        cin >> year >> mon >> day;

        Chrono::Date c_date{year, Chrono::Month(mon), day};

        bool avail = false;
        cout << "\nEnter the availability of the book (0 if it is absent, 1 otherwise): ";

        cin >> avail;

        Book new_book{author, title, isbn, c_date, avail, gen};

        books.push_back(new_book);

        cout << "Would you like to add one more book?\n";

        string ans;

        cin >> ans;
        if (ans != "yes" && ans != "y")
            break;
    }
}

void Library::read_patrons() {
    string name, surname, lib_cnum;
    int fee = 0;

    cout << "Enter patrons in format 'Name' 'Surname' 'Library cardnum' 'Fees'\n"
        << "If you want to finish an input put the name as 'NoName'\n";

    while (cin >> name >> surname >> lib_cnum >> fee && name != "NoName") {
        string full_name = name + ' ' + surname;
        if (is_user(full_name, lib_cnum) != Library::nusr)
            error("Patron with such name and library cardnumber already exist: ", full_name + ' ' + lib_cnum);

        patrons.push_back(Patron {full_name, lib_cnum, fee});
    }
}

string read_str() { // function for reading author and title
    string inp;
    char c = '\0';

    while (isspace(cin.get()))  // After each iteration of input the very last symbol in stream will be '\n'
        ;                       // Here we check it and if so skip it

    cin.unget();
    while (cin.get(c) && c != '\n')
        inp.push_back(c);

    return inp;
}

Genre read_genre() {
    cout << "Please enter the number of genre which mathes this book:\n"
            << "1 - fiction\n2 - nonfiction\n3 - periodical\n4 - biography\n5 - for children\n";

    int genre = 0;

    cin >> genre;

    return Genre(genre);
}

void Library::book_chout(Patron& p, Book& b) {
    int user_pos = 0;
    int book_pos = 0;

    if ((user_pos = is_user(p.getP_name(), p.getLib_cardnum())) == Library::nusr)
        error("User with such name and library card wasn't found in library: ", p.getP_name() + ' ' + p.getLib_cardnum());
    else if ((book_pos = is_book(b.isbn_get())) == Library::nbk)
        error("There are no such books in the library: ", b.author_get() + ' ' + b.title_get());
    else if (patrons[user_pos].have_fee())
        error("You have a fee, please get back your books before getting new one");
    else if (!books[book_pos].have_book())
        error("This book is currently unavailable");

    patrons[user_pos].setLib_fees(1);
    books[book_pos].setCheck_out(false);

    trans.push_back(Transaction{b, p, Chrono::Date {2015, Chrono::Month::Jan, 14}});
}

int Library::is_user(const string& name, const string& l_cnum) {
    for (int i = 0; i < patrons.size(); ++i)
        if (name == patrons[i].getP_name() && l_cnum == patrons[i].getLib_cardnum())
            return i;

    return Library::nusr;
}

int Library::is_book(const string& isbn) {
    for (int i = 0; i < books.size(); ++i)
        if (isbn == books[i].isbn_get())
            return i;

    return Library::nbk;
}

ostream &operator<<(ostream &os, const Transaction &tr) {
    return os << "Book:\n" << tr.book << "was checked out in " << tr.date
            << " by " << tr.patron.getP_name() << ": " << tr.patron.getLib_cardnum() << '\n';
}

vector<Patron> Library::have_arrears() {
    vector<Patron> fee_owners;

    for (int i = 0; i < patrons.size(); ++i)
        if (patrons[i].have_fee())
            fee_owners.push_back(patrons[i]);

    return fee_owners;
}
