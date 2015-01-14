#include "std_lib_facilities.h"

class Patron {
public:
    Patron(const string& name, const string& lib_cardnum, const int lib_fees)
            : p_name {name}, lib_cardnum {lib_cardnum}, lib_fees {lib_fees}
    {
        if (!lcard_check(lib_cardnum))
            error("Invalid library card number");
    }

    const string& getP_name() const {
        return p_name;
    }

    const string& getLib_cardnum() const {
        return lib_cardnum;
    }

    void setLib_cardnum(const string& cardnum) {
        if (!lcard_check(cardnum))
            error("Invalid library card number");

        lib_cardnum = cardnum;
    }

    int getLib_fees() const {
        return lib_fees;
    }

    void setLib_fees(const int fees) {
        lib_fees = lib_fees;
    }

    bool lcard_check(const string& ln);

private:
    string p_name;
    string lib_cardnum; // library card number in format Num-Num-(Num | Alph)
    int lib_fees;
};