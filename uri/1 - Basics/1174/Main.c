#include <stdio.h>

int main(){
    int n = -1;
    float i;
    while (++n <= 99){
        scanf("%f", &i);
        if (i <= 10){
            printf("A[%d] = %.1f\n", n, i);
        }
    }
    return 0;
}