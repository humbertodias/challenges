#include <stdio.h>
#include <math.h>

int is_prime(unsigned long n){
    if (n == 2) return 1;
    if (n % 2 == 0 || n < 2) return 0;
    unsigned long i;
    for (i = 3; i <= sqrt(n); i += 2){
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){
    int n, i;
    scanf("%d", &i);
    while(i--){
        scanf("%d", &n);
        if (is_prime(n))
            printf("%d eh primo\n", n);
        else
            printf("%d nao eh primo\n", n);
    }

    return 0;
}