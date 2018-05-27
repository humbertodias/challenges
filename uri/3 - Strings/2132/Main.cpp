#include <iostream>
#include <string>


using namespace std;
 
int main()
{
    string w;
    int test = 1;
    long long r = 1;
    long long rf = 0;
 
    while (cin >> w) {
 
        for (int i = 0; i < w.length(); i++) {
            if (w[i] == 'b') {
                for (int j = i + 1; j < w.length(); j++) {
                    r = r * 2;
                }
                rf = rf + r;
                r = 1;
            }
        }
 
        cout << "Palavra " << test++ << endl
             << rf << endl;
        rf = 0;

        cout << endl;
    }
    return 0;
}