#include <stdio.h>

int main(){
    double f1, f2, f3;
    char name[256];

    scanf(" %[^\n]",name);
    scanf("%lf", &f1);
    scanf("%lf", &f2);
    f3 = f1 + (15.0*f2/100.0);
    printf("TOTAL = R$ %.2f\n",f3 );

    return 0;
}