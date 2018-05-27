#include <stdio.h>

// #define PERCENTUAL(x,y) ((y - x) / (float)x) * 100
#define PERCENTUAL(x,y) (y / x - 1)  * 100

int main(){

    double x,y;
    long long i = 1;
    while( scanf("%lf %lf", &x, &y) != EOF ){
      printf("Projeto %lld:\n", i++);
      printf("Percentual dos juros da aplicacao: %.2f %%\n\n", PERCENTUAL(x,y) );
    }

    return 0;
}