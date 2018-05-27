#include <iostream>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
int main() {
    long double c, i;
    int n;
    while(scanf("%Lf", &c) == 1)
    {
        scanf("%Lf", &i);
        scanf("%d", &n);
 
        long double composto = c * powl((1 + i), (double)n) - c;
        long double simples = c * i * n;
 
        printf("DIFERENCA DE VALOR = %.2Lf\n", abs(composto - simples));
        printf("JUROS SIMPLES = %.2Lf\n", simples);
        printf("JUROS COMPOSTO = %.2Lf\n", composto);
 
    }
    return 0;
}