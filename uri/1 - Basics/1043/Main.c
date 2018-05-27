#include <stdio.h>
#include <math.h> //abs

int main(){
    float a,b,c;
    float mod1, mod2, mod3;
    
    scanf("%f %f %f", &a, &b, &c);
    
    mod1 = fabs(c - b);
	mod2 = fabs(a - b);
    mod3 = fabs(a - c);

    if (mod1 < a && a < (b + c) && mod2 < c && c < (a+b) && mod3 < b && b < (a+c))
        printf("Perimetro = %.1f\n", a+b+c);
    else
        printf("Area = %.1f\n", ((a+b)*c)/2.0 );
            
    return 0;   
}