#include <iostream>
using namespace std;

string to_roman(unsigned long value)
{
        struct romandata_t { unsigned long value; char const* numeral; };
        const struct romandata_t romandata[] =
        {
                {1000, "M"}, {900, "CM"},
                {500, "D"}, {400, "CD"},
                {100, "C"}, { 90, "XC"},
                { 50, "L"}, { 40, "XL"},
                { 10, "X"}, { 9, "IX"},
                { 5, "V"}, { 4, "IV"},
                { 1, "I"},
                { 0, NULL} // end marker
        };

        string result;
        for (const romandata_t* current = romandata; current->value > 0; ++current)
        {
                while (value >= current->value)
                {
                        result += current->numeral;
                        value -= current->value;
                }
        }
        return result;
}

int main() {
    long long n;
    while (cin >> n) {
        cout << to_roman(n) << endl;
    }
    return 0;
}