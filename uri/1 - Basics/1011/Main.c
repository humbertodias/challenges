#include <stdio.h>
#include <math.h>

int main(){
    int a;
    scanf("%d", &a);
    
    printf("VOLUME = %.3f\n", (4.0/3.0)*3.14159*pow(a,3));
    return 0;
}