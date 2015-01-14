#include "Library.h"

int main() {
    try {
        Library my_lib;
        cout << "Welcome to test library program\n"
                << "You will be prompted about books you have in your library\n"
                << "Please, answer the questions and have fun.\n";

        my_lib.read_patrons();
        my_lib.read_books();
        Patron v {"Volodja Petrigo", "123-456-RU", 0};
        Book b {"Alexey Tolstoy", "Upir", "45-987-1-RU", Chrono::Date{2001, Chrono::Month::Jan, 1}, 1, Genre(1)};
        my_lib.book_chout(v, b);
        my_lib.book_chout(v, b);

        vector<Patron> clients = my_lib.get_Patrons();
        vector<Book> books = my_lib.get_Books();
        vector<Transaction> tr = my_lib.get_Trans();

        for (int i = 0; i < clients.size(); ++i)
            cout << clients[i].getP_name() << '\n';

        for (int i = 0; i < books.size(); ++i)
            cout << books[i] << '\n';

        for (int i = 0; i < tr.size(); ++i)
            cout << tr[i] << '\n';

        return 0;
    }
    catch (Book::Invalid& invalid) {
        cerr << "You inserted incorrect ";
        switch (invalid) {
            case Book::Invalid::author:
                cerr << "author name\n";
                break;
            case Book::Invalid::title:
                cerr << "title\n";
                break;
            case Book::Invalid::isbn:
                cerr << "ISBN number\n";
                break;
            case Book::Invalid::genre:
                cerr << "genre\n";
                break;
            default:
                cerr << "something else\n";
                break;
        }

        return 1;
    }
    catch (exception& e) {
        cerr << e.what() << '\n';

        return 2;
    }
    catch (Chrono::Date::Invalid& i) {
        cerr << "You inserted the wrong date\n";

        return 3;
    }
    catch(...) {
        cerr << "Something wrong happend\n";

        return 4;
    }
}
