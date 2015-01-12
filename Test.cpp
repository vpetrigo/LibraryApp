#include "Books.h"

string read_str();
Genre read_genre();

int main() {
    vector<Book> library;

    cout << "Welcome to test library program\n"
            << "Please enter books you have:\n";

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

        int year = 0, mon = 0, day = 0;

        cout << "\nEnter the date of release (format: YY MM DD): ";
        cin >> year >> mon >> day;

        Chrono::Date c_date {year, Chrono::Month(mon), day};

        bool avail = false;
        cout << "\nEnter the availability of the book (0 if it is absent, 1 otherwise): ";

        cin >> avail;

        cout << avail << '\n';
        Book new_book {author, title, isbn, c_date, avail};

        library.push_back(new_book);

        cout << "Would you like to add one more book?\n";

        string ans;

        cin >> ans;
        if (ans != "yes" && ans != "y")
          break;
    }

    for (size_t i = 0; i < library.size(); ++i)
        cout << library[i] << '\n';

    return 0;
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
}