#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

#define PERCENTUAL(x,y) (y / x - 1)  * 100

int main(){

    double x,y;
    int i = 1;
    ios_base::sync_with_stdio(false);cin.tie(0);
    while( scanf("%lf %lf", &x, &y) != EOF ){
      printf("Projeto %d:\n", i++);
      printf("Percentual dos juros da aplicacao: %.2f %%\n\n", PERCENTUAL(x,y) );
    }

    return 0;
}