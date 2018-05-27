#include <stdio.h>

int main(){
    int a, b;

    scanf("%d %d",&a, &b);
    float f = (a*b)/12.0;
    
    printf("%.3f\n", f);
    return 0;
}