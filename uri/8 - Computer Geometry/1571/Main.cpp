#include <cstdio>
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

typedef std::numeric_limits< long double > dbl;

int main()
{
   long double x;
   long double sqrt3=sqrtl(3.0);
   long double sqrt2=sqrtl(2.0);
   long double sqrt6=sqrtl(6.0);

    while(std::cin >> x){

       std::cout.precision(10);
       std::cout << std::fixed;
       std::cout << 4.0*x/(sqrt6+sqrt2)<<" ";
       std::cout << (x*sqrt2)/sqrt3 <<" ";
       std::cout << (4.0*x)/(sqrt2*sqrt3+sqrt3*2.0)<<" ";
       std::cout << (x*sqrt3)/(1+sqrt3)<<" ";
       std::cout << (x*(sqrt3+2))/(sqrt3+5)<<" ";
       std::cout << (x*(1.0+sqrt3))/(3.0*sqrt3)<<" ";
       std::cout << (x+x*(sqrt3/3.0))/((sqrt3/3.0)*sqrt3+(sqrt3/3.0)+sqrt3)<<std::endl;
    }
    return 0;
}