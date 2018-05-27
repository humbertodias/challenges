#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    const double g = 9.80665, pi = 3.14159;
    double h, alfa, v;
    int p1, p2, n;
    //g=9,80665
 
    while(true)
    {
        cin >> h;
        if(not cin) break;
        cin >> p1 >> p2;
        cin >> n;
        while(n-- > 0)
        {
            cin >> alfa >> v;
            alfa = alfa*pi/180;
            double va = v*sin(alfa);
            double t = (va+sqrt(va*va+2*g*h))/g;
            double d = v*cos(alfa)*t;
            cout << std::fixed << setprecision(5) << d << " -> ";
            if(d <= p2 && d >= p1) cout << "DUCK\n";
            else cout << "NUCK\n";
        }
    }
    return 0;
}