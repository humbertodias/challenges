#include <iostream>

using namespace std;
int main()
{
    unsigned long long n, t, year;
    long long diff;
    cin >> n;
    for(unsigned long long i=0; i< n; i++){
        cin >> t;

        diff = 2015 - t;
        if (diff <= 0)
            year = diff * -1 + 1;
        else
            year = diff;
        cout << year << " " << (diff <= 0 ? "A.C." : "D.C.") << endl;

    }
    return 0;
}