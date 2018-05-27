#include <iostream>
#include <cctype>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    string linha;
    while(getline(cin, linha) && cin) {
        bool lastupper = false;
        for(char c : linha) {
            if (isalpha(c)) {
                if(lastupper) {
                    c = tolower(c);
                    lastupper = false;
                } else {
                    c = toupper(c);
                    lastupper = true;
                }
            } 
            cout << c;
        }
        cout << endl;
    }

    return 0;
}