#include "Patron.h"

bool Patron::lcard_check(const string& ln) {
    if (!ln.size())
        error("Length of the string you passed is zero");

    size_t pos = 0; // current position in the string
    size_t prev_pos = 0; // start position of part before delimiter
    const char delim = '-';

    vector<string> lcard_parts;

    while ((pos = ln.find(delim, prev_pos)) != string::npos) {
        lcard_parts.push_back(ln.substr(prev_pos, pos - prev_pos));
        prev_pos = pos + 1; // position right after a hyphen
    }

    lcard_parts.push_back(ln.substr(prev_pos, ln.size() - pos)); // and the last part

    if (lcard_parts.size() != Patron::lcard_len)
        return false;

    int (*analyse_fun)(int); // pointer to analysing function
    for (int i = 0; i < Patron::lcard_len; ++i) { // check first three parts of ISBN number which has to be numbers
        if (lcard_parts[i].size() == 0)
            return false;

        analyse_fun = (i != Patron::lcard_len - 1) ? (int (*)(int)) isdigit : (int (*)(int)) isalnum;   // for the 4th part of ISBN
                                                                                                        // accept numbers and alphabet in the string

        for (int j = 0; j < lcard_parts[i].size(); ++j)
            if (!analyse_fun(lcard_parts[i][j]))    // Check if the first three parts of ISBN
                return false;                       // is numbers and the last one might be
    }                                               // either number or alphabet characters



    return true;
}

bool Patron::have_fee() {
    return lib_fees;
}
