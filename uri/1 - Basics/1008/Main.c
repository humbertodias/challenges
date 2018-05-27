#include <stdio.h>
 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */

     int NUMBER,HOURS; 
     double HOUR_VALUE, SALARY;
     scanf("%d", &NUMBER);
     scanf("%d", &HOURS);
     scanf("%lf", &HOUR_VALUE);
     SALARY = HOURS * HOUR_VALUE;

     printf("NUMBER = %d\n", NUMBER);
     printf("SALARY = U$ %.2f\n", SALARY);
     return 0;
}
