#include <stdio.h>

int main(){

    double x,m;
    while( scanf("%lf %lf", &x, &m) ){
    	if(x == 0 || m == 0) break;
        printf("%.0f\n", (m*x) );
    }

    return 0;

}
