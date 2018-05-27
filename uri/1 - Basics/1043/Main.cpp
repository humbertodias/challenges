#include <iostream>
#include <iomanip> // setprecision
#include <cmath> //abs

using namespace std;

int main(){
    float a,b,c;
    float mod1, mod2, mod3;
    
    cin >> a >> b >> c;
    
    mod1 = fabs(c - b);
	mod2 = fabs(a - b);
    mod3 = fabs(a - c);

    cout << fixed << setprecision(1);
    
    if (mod1 < a && a < (b + c) && mod2 < c && c < (a+b) && mod3 < b && b < (a+c))
        cout << "Perimetro = " << a+b+c << endl;
    else
        cout << "Area = " << ((a+b)*c)/2.0 << endl;
            
    return 0;   
}