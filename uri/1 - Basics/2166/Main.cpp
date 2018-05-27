#include <iomanip>
#include <iostream>
#include <tuple>
#include <cstdio>

using namespace std;
 
typedef std::tuple<double,double> coeff_t; // coefficients type
typedef coeff_t (*func_t)(int); // callback function type
 
double calc(func_t func, int n)
{
    double a, b, temp = 0;
    for (; n > 0; --n) {
        std::tie(a, b) = func(n);
        temp = b / (a + temp);
    }
    std::tie(a, b) = func(0);
    return a + temp;
}
 
coeff_t sqrt2(int n)
{
    return coeff_t(n > 0 ? 2 : 1, 1);
} 
 
int main()
{
    int n;
    scanf("%d", &n);
    printf("%.10f\n", calc(sqrt2, n) );
    return 0;
}