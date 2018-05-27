#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double f1, f2, f3;
    char name[256];

    cin.getline(name,256);
    cin >> f1 >> f2;
    f3 = f1 + (15.0*f2/100.0);
    cout << fixed << setprecision(2) << "TOTAL = R$ " << f3 << endl;

    return 0;
}