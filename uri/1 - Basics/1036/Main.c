#include <stdio.h>
#include <math.h>

int main(){
    double a, b, c;

    scanf("%lf %lf %lf", &a, &b, &c);

    if((pow(b,2) - 4*a*c) < 0 || 2*a == 0)
         printf("Impossivel calcular\n");
    else{
         printf("R1 = %.5lf\n",((-b) + sqrt((pow(b,2) - 4*a*c)))/(2*a));
         printf("R2 = %.5lf\n",((-b) - sqrt((pow(b,2) - 4*a*c)))/(2*a));
     }
    return 0;
}