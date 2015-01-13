#include "Patron.h"

bool Patron::lcard_check(const string& ln) {
    if (!ln.size())
        error("Length of the string you passed is zero");

    int pos = 0; // current position in the string
    int hyphen = 0; // this variable controls quantity of hyphens in library cardnumber
                    // conform to format Num-Num-(Num | Alph); Num - may be any positive integer value
    for ( ; pos < ln.size() && hyphen != 2; ++pos)
        if (!isdigit(ln[pos]))
            return false;
        else if (ln[pos] == '-')
            ++hyphen;

    if (hyphen < 2)
        return false;

    for (pos += 1; pos < ln.size(); ++pos)
        if (!isalnum(ln[pos]))
            return false;

    return true;
}