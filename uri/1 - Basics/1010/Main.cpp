#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    
    int a,b,c,d;
    float e,f;
    
    cin >> a >> b >> e;
    cin >> c >> d >> f;
    
    cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << (b*e + d*f) << endl;
    return 0;
}