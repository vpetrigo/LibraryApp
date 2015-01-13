#include "Books.h"

string read_str(); // Used for reading an author name and a title in right format
Genre read_genre(); // Asked user for genre of the current book
void read_books(vector<Book>& lib); // Prompt process for obtaining data about a book

int main() {
    try {
        vector<Book> library;   // Vector of whole books which library have

        cout << "Welcome to test library program\n"
                << "You will be prompted about books you have in your library\n"
                << "Please, answer the questions and have fun.\n";
        Book a {"DB", "AND", "77-77-7-7US", Chrono::Date{2008, Chrono::Month::Apr, 15}, 1, Genre::fiction };
        read_books(library);

        for (size_t i = 0; i < library.size(); ++i)
            cout << library[i] << '\n';

        return 0;
    }
    catch (Book::Invalid& invalid) {
        cerr << "You inserted incorrect ISBN number\n";

        return 1;
    }
    catch (exception& e) {
        cerr << e.what() << '\n';

        return 2;
    }
    catch(...) {
        cerr << "Something wrong happend\n";

        return 3;
    }
}

string read_str() { // function for reading author and title
    string inp;
    char c = '\0';

    while (cin.get() == '\n') // After each iteration of input the very last symbol in stream will be '\n'
        ;       // Here we check it and if so skip it

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

    if (genre < int(Genre::fiction) || int(Genre::children) < genre)
        error("Wrong genre");

    return Genre(genre);
}

void read_books(vector<Book>& lib) {
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

        lib.push_back(new_book);

        cout << "Would you like to add one more book?\n";

        string ans;

        cin >> ans;
        if (ans != "yes" && ans != "y")
            break;
    }
}