#include <stdio.h>

int main(){
    
    int a,b,c,d;
    float e,f;
    
    scanf("%d %d %f", &a,&b,&e);
    scanf("%d %d %f", &c,&d,&f);
    
    printf("VALOR A PAGAR: R$ %.2f\n", (b*e + d*f) );
    return 0;
}