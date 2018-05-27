// Problem   Automatic Correction of Misspellings
// Algorithm straightforward
// Runtime   O(q log n) (assumes string length and alphabet size are constant)

#include <iostream>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <map>
#include <string>
using namespace std;

#define MAXN 10000
#define MAXQ 1000

void assert_word(string &w) {
    assert( w.size() <= 25 );
    for (int i=0; i<(int)w.size(); i++)
        assert( w[i] >= 'a' && w[i] <= 'z' );
}

// use map data structure
map<string,int> dict;

int is_in_dictionary(string &w, int n) {
    if (dict.find(w) != dict.end())
        return dict[w];
    return n;
}

int checkword(string &qw, int n, string &realword) {
    // check if word is correct
    if (is_in_dictionary(qw,n)<n)
        return 0;
    // index of the earliest word for which qw can be a misspelling
    int smallest_index = n;
    // check first error (missing letter or letter too much)
    for (int i=0; i<=(int)qw.size(); i++) {
        string temp = "";
        if (i > 0)
            temp += qw.substr(0,i);
        temp += 'a';
        if (i < (int)qw.size()) {
            temp += qw.substr(i);
            string temp2 = qw;
            temp2.erase(temp2.begin()+i);
            int t = is_in_dictionary(temp2,n);
            if (t < smallest_index) {
                smallest_index = t;
                realword = temp2;
            }
        }
        for (int j=0; j<26; j++,temp[i]++) {
            int t = is_in_dictionary(temp,n);
            if (t < smallest_index) {
                smallest_index = t;
                realword = temp;
            }
        }
    }
    // check second error (wrong letter)
    for (int i=0; i<(int)qw.size(); i++) {
        char old = qw[i];
        for (char c='a'; c <= 'z'; ++c) {
            qw[i] = c;
            int t = is_in_dictionary(qw,n);
            if (t < smallest_index) {
                smallest_index = t;
                realword = qw;
            }
        }
        qw[i] = old;
    }
    // check third error
    for (int i=0; i+1<(int)qw.size(); i++) {
        string temp = "";
        if (i > 0)
            temp += qw.substr(0,i);
        temp += qw[i+1];
        temp += qw[i];
        if (i+2 < (int)qw.size())
            temp += qw.substr(i+2);
        int t = is_in_dictionary(temp,n);
        if (t < smallest_index) {
            smallest_index = t;
            realword = temp;
        }
    }
    if (smallest_index < n)
        return 1;
    return 2;
}

int main() {
    int n;
    cin >> n;
    assert( n >= 0 && n <= MAXN );
    for (int i=0; i<n; i++) {
        string dictword;
        cin >> dictword;
        assert_word(dictword);
        assert(dict.find(dictword) == dict.end());
        dict[dictword] = i;
    }
    int q;
    cin >> q;
    assert( q >= 0 && q <= MAXQ );
    for (int i=0; i<q; i++) {
        string qw,realword;
        cin >> qw;
        assert_word(qw);
        cout << qw;
        switch(checkword(qw,n,realword)) {
            case 0: cout << " is correct" << endl; break;
            case 1: cout << " is a misspelling of " << realword << endl; break;
            case 2: cout << " is unknown" << endl; break;
            default: assert(0);
        }
    }
    return 0;
}