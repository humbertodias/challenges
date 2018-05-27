#include <stdio.h>

int main(){
    
    int a;
    float b;
    
    scanf("%d %f", &a, &b);
    printf("%.3f km/l\n", a/b);
    return 0;
}